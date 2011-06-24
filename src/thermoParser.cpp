/*
 * thermoParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "thermoParser.h"
#include <istream>


using namespace std;

// Empty default constructor, can be removed but leave it there just in case.

IO::ThermoParser::ThermoParser(const string thermo_file)
:
    thermo_file_(thermo_file),
    lines_(fileToStrings(thermo_file))
{}

void IO::ThermoParser::parse() {
    // let's do the thermo file first. easiest.
    // 1. Find the starting line in term.dat
    // 2. Ignore comments
    // 3. Ignore the default temperature line for now.
    // 4. For NASA 7 coefficient polynomials, here is the snipplet
    //H2                TPIS78H   2               G  200.0     3500.0    1000.0      1
    //+3.3372792E+00 -4.9402473E-05 +4.9945678E-07 -1.7956639E-10 +2.0025538E-14     2
    //-9.5015892E+02 -3.2050233E+00 +2.3443311E+00 +7.9805208E-03 -1.9478151E-05     3
    //+2.0157209E-08 -7.3761176E-12 -9.1793517E+02 +6.8301024E-01                    4
    //    create regex(es) which match each line
    // 5. if the 4 regex(es) match the 4 lines in a row then we extract the capture groups
    // 6 if not, we move forward by 1 line and redo the matching in step 5.

    std::vector<string> thermo_lines = getThermoSection(lines_);
    
    cout << "Parsing NASA" << endl;

    for (unsigned int i = 0; i < thermo_lines.size(); i++) {
        if (isSectionMatchedNASA(thermo_lines, i)) {
            parseNASASection(thermo_lines[i], thermo_lines[i + 1], thermo_lines[i + 2], thermo_lines[i + 3]);
            i += 3;
        } else {
            cout << "Unmatched : " << thermo_lines[i] << endl;
        }
    }

}

void IO::ThermoParser::parseNASASection(std::string l1, std::string l2, std::string l3, std::string l4) {

}

bool IO::ThermoParser::isSectionMatchedNASA(std::vector<std::string> lines, unsigned int offset) {
    const regex nasaLine1("[^!]{79}1.*");
    const regex nasaLine2("[^!]{79}2.*");
    const regex nasaLine3("[^!]{79}3.*");
    const regex nasaLine4("[^!]{79}4.*");
    if (lines.size() >= (offset + 4)) {
        return regex_match(lines.at(offset), nasaLine1, boost::regex_constants::match_single_line) &&
                regex_match(lines.at(offset + 1), nasaLine2, boost::regex_constants::match_single_line) &&
                regex_match(lines.at(offset + 2), nasaLine3, boost::regex_constants::match_single_line) &&
                regex_match(lines.at(offset + 3), nasaLine4, boost::regex_constants::match_single_line);
    } else {
        return false;
    }
}

std::vector<std::string> IO::ThermoParser::getThermoSection(std::vector<std::string> lines) {
    std::vector<std::string> thermo_lines;
    int begin = -1;
    int end = -1;
    const regex thermoTag("\\s*THER(?:|MO).*");
    const regex endTag("\\s*END.*");

    // this loop only for finding index of THERMO and END keywords in the lines
    for (unsigned int i = 0; i < lines.size(); i++) {
        if ((begin < 0) && regex_match(lines.at(i), thermoTag, boost::regex_constants::match_single_line)) {
            begin = (int) i;
        } else if ((end < 0) && regex_match(lines.at(i), endTag, boost::regex_constants::match_single_line)) {
            end = (int) i;
            break;
        }
    }

    // check if the indexes are correct
    if (-1 < begin && begin < end) {
        for (int i = ++begin; i < end; i++) {
            thermo_lines.push_back(lines[i]);
        }
    } else {
        cout << "Error: Thermo file does not contain valid starting and ending tags." << endl;
    }

    return thermo_lines;
}
