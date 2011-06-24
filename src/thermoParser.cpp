/*
 * thermoParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "thermoParser.h"
#include "stringFunctions.h"
#include <istream>

using namespace std;
using namespace boost;

IO::ThermoParser::ThermoParser(const string thermo_file)
:
thermo_file_(thermo_file),
lines_(fileToStrings(thermo_file)) {
}

void IO::ThermoParser::parse() {

    vector<string> thermo_lines = getThermoSection(lines_);

    cout << "Parsing NASA" << endl;

    const regex empty("\\s*");

    for (unsigned int i = 0; i < thermo_lines.size(); i++) {
        if (isSectionMatchedNASA(thermo_lines, i)) {
            parseNASASection(thermo_lines[i], thermo_lines[i + 1], thermo_lines[i + 2], thermo_lines[i + 3]);
            i += 3;
        } else if (!regex_match(thermo_lines[i], empty, regex_constants::match_single_line)) {
            // Only print unmatched lines if it is not empty.
            cout << "Unmatched : " << thermo_lines[i] << endl;
        }
    }

    // this is where it print out info at the moment
    for (unsigned int i = 0; i < thermos_.size(); i++) {
        cout << thermos_[i] << endl;
    }

}

bool IO::ThermoParser::parseNASASection(string l1, string l2, string l3, string l4) {
    // line 1
    Thermo thermo(trim(l1.substr(0, 18)));
    thermo.setNote(trim(l1.substr(18, 6)));
    thermo.setElementsCounts(trim(l1.substr(24, 20)));
    thermo.setPhase(l1.substr(44, 1));
    thermo.setTLow(from_string<double>(trim(l1.substr(45, 10))));
    thermo.setTHigh(from_string<double>(trim(l1.substr(55, 10))));
    thermo.setTCommon(from_string<double>(trim(l1.substr(65, 8))));
    thermo.setElementsCounts(thermo.getElementsCounts() + trim(l1.substr(73, 5)));
    // line 2, 3 4
    double al1, al2, al3, al4, al5, al6, al7;
    double ah1, ah2, ah3, ah4, ah5, ah6, ah7;
    ah1 = from_string<double>(trim(l1.substr(0, 15)));
    ah2 = from_string<double>(trim(l1.substr(15, 15)));
    ah3 = from_string<double>(trim(l1.substr(30, 15)));
    ah4 = from_string<double>(trim(l1.substr(45, 15)));
    ah5 = from_string<double>(trim(l1.substr(60, 15)));
    ah6 = from_string<double>(trim(l1.substr(0, 15)));
    ah7 = from_string<double>(trim(l1.substr(15, 15)));
    al1 = from_string<double>(trim(l1.substr(30, 15)));
    al2 = from_string<double>(trim(l1.substr(45, 15)));
    al3 = from_string<double>(trim(l1.substr(60, 15)));
    al4 = from_string<double>(trim(l1.substr(0, 15)));
    al5 = from_string<double>(trim(l1.substr(15, 15)));
    al6 = from_string<double>(trim(l1.substr(30, 15)));
    al7 = from_string<double>(trim(l1.substr(45, 15)));
    thermo.setUpperTemperatureCoefficients(ah1, ah2, ah3, ah4, ah5, ah6, ah7);
    thermo.setLowerTemperatureCoefficients(al1, al2, al3, al4, al5, al6, al7);
    thermos_.push_back(thermo);
    return false;
}

bool IO::ThermoParser::isSectionMatchedNASA(std::vector<std::string> lines, unsigned int offset) {
    const regex nasaLine1("[^!]{79}1.*");
    const regex nasaLine2("[^!]{79}2.*");
    const regex nasaLine3("[^!]{79}3.*");
    const regex nasaLine4("[^!]{79}4.*");
    if (lines.size() >= (offset + 4)) {
        return regex_match(lines.at(offset), nasaLine1, regex_constants::match_single_line) &&
                regex_match(lines.at(offset + 1), nasaLine2, regex_constants::match_single_line) &&
                regex_match(lines.at(offset + 2), nasaLine3, regex_constants::match_single_line) &&
                regex_match(lines.at(offset + 3), nasaLine4, regex_constants::match_single_line);
    } else {
        return false;
    }
}

std::vector<std::string> IO::ThermoParser::getThermoSection(std::vector<std::string> lines) {
    vector<string> thermo_lines;
    int begin = -1;
    int end = -1;
    const regex thermoTag("\\s*THER(?:|MO).*");
    const regex endTag("\\s*END.*");

    // this loop only for finding index of THERMO and END keywords in the lines
    for (unsigned int i = 0; i < lines.size(); i++) {
        if ((begin < 0) && regex_match(lines.at(i), thermoTag, regex_constants::match_single_line)) {
            begin = (int) i;
        } else if ((end < 0) && regex_match(lines.at(i), endTag, regex_constants::match_single_line)) {
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
