/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"

using namespace std;
using namespace boost;

const regex IO::ChemkinReader::elementListRegex("ELEM(?:|ENT|ENTS)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::elementSingleRegex("(\\w+)");

const regex IO::ChemkinReader::speciesListRegex("SPEC(?:|IE|IES)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::speciesSingleRegex("\\s+");

const regex IO::ChemkinReader::reactionListRegex("REAC(?:|TION|TIONS)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::reactionSingleRegex("\\s+");

IO::ChemkinReader::ChemkinReader
(
    const string chemfile,
    const string thermfile,
    const string transfile
)
:
    chemfile_(chemfile),
    thermfile_(thermfile),
    transfile_(transfile),
    chemfilestring_(fileToString(chemfile_))
{}

void IO::ChemkinReader::check() {
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;
    cout << elements_ << endl;
    cout << species_ << endl;
}

void IO::ChemkinReader::readElements() {

    smatch result;
    regex_search(chemfilestring_, result, elementListRegex);
    string elementString = result[1];

    //replaceComments(elementString);

    std::string::const_iterator start = elementString.begin();
    std::string::const_iterator end = elementString.end();
    boost::match_results<std::string::const_iterator> what;

    while (regex_search(start, end, what, elementSingleRegex)) {
        elements_.push_back(Element(what[1], 0.0));
        start = what[0].second;
    }

}

void IO::ChemkinReader::readSpecies() {

    smatch result;
    regex_search(chemfilestring_, result, speciesListRegex);
    string speciesString = result[1];

    std::string::const_iterator start = speciesString.begin();
    std::string::const_iterator end = speciesString.end();

    boost::sregex_token_iterator i(start, end, speciesSingleRegex, -1);
    boost::sregex_token_iterator j;
    while (i != j) {
        species_.push_back(Species(*i++));
    }

}

void IO::ChemkinReader::readReactions() {

    smatch result;
    regex_search(chemfilestring_, result, reactionListRegex);
    string reactionString = result[1];

    cout << reactionString << endl;

    std::string::const_iterator start = reactionString.begin();
    std::string::const_iterator end = reactionString.end();

    boost::sregex_token_iterator i(start, end, reactionSingleRegex, -1);
    boost::sregex_token_iterator j;
    // while(i != j)
    // {

    // }


}

const std::string
IO::fileToString(const std::string& fileName) {
    ifstream fin(fileName.c_str(), ios::in);

    string fileInString((std::istreambuf_iterator<char>(fin)),
            std::istreambuf_iterator<char>());

    return fileInString;
}

const std::vector<std::string>
IO::fileToStrings(const std::string fileName) {
    std::vector<std::string> lines;
    ifstream fin(fileName.c_str(), ios::in);
    std::string line;
    while (std::getline(fin, line)) {
        lines.push_back(line);
    }
    return lines;
}

string
IO::regex_escape
(
        const string& string_to_escape
        ) {
    static const regex re_boostRegexEscape("[\\^\\.\\$\\|\\(\\)\\[\\]\\*\\+\\?\\/\\\\]");
    const string rep("\\\\\\1&");
    string result = regex_replace(string_to_escape, re_boostRegexEscape, rep, match_default | format_sed);
    return result;
}


void IO::replaceComments(std::string& stringToReplace) {
    regex commentRegex("(!.*?)\\n|(!.*?)$");
    string format_string = " ";
    stringToReplace = regex_replace(stringToReplace, commentRegex, format_string, match_default | format_sed);
    return stringToReplace;
}

std::string IO::convertToCaps(const std::string &str)
{
    std::string::const_iterator i;
    std::string caps;

    for (i=str.begin(); i!=str.end(); i++) {
        switch (*i) {
            case 'a': caps.append("A"); break;
            case 'b': caps.append("B"); break;
            case 'c': caps.append("C"); break;
            case 'd': caps.append("D"); break;
            case 'e': caps.append("E"); break;
            case 'f': caps.append("F"); break;
            case 'g': caps.append("G"); break;
            case 'h': caps.append("H"); break;
            case 'i': caps.append("I"); break;
            case 'j': caps.append("J"); break;
            case 'k': caps.append("K"); break;
            case 'l': caps.append("L"); break;
            case 'm': caps.append("M"); break;
            case 'n': caps.append("N"); break;
            case 'o': caps.append("O"); break;
            case 'p': caps.append("P"); break;
            case 'q': caps.append("Q"); break;
            case 'r': caps.append("R"); break;
            case 's': caps.append("S"); break;
            case 't': caps.append("T"); break;
            case 'u': caps.append("U"); break;
            case 'v': caps.append("V"); break;
            case 'w': caps.append("W"); break;
            case 'x': caps.append("X"); break;
            case 'y': caps.append("Y"); break;
            case 'z': caps.append("Z"); break;
            default: caps.append(i,i+1); break;
        }
    }
    return caps;

}

std::string IO::trim(const std::string &str) {
    int b = str.find_first_not_of(" \t");
    if (b < 0)
        return "";
    int e = str.find_last_not_of(" \t");

    return str.substr(b, e - b + 1);
}
