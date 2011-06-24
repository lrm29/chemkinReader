/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"

using namespace std;
using namespace boost;

const regex IO::ChemkinReader::elementListRegex("ELEM(?:|ENT|ENTS)\\s+(.*?)\\s*END");
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

void IO::ChemkinReader::check()
{
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;
    cout << elements_ << endl;
    cout << species_ << endl;
}

void IO::ChemkinReader::readElements()
{

    smatch result;
    regex_search(chemfilestring_, result, elementListRegex);
    string elementString = result[1];

    std::string::const_iterator start = elementString.begin();
    std::string::const_iterator end = elementString.end();
    boost::match_results<std::string::const_iterator> what;

    while (regex_search(start, end, what, elementSingleRegex))
    {
        elements_.push_back(Element(what[1],0.0));
        start = what[0].second;
    }

}

void IO::ChemkinReader::readSpecies()
{

    smatch result;
    regex_search(chemfilestring_, result, speciesListRegex);
    string speciesString = result[1];

    replaceComments(speciesString);

    std::string::const_iterator start = speciesString.begin();
    std::string::const_iterator end = speciesString.end();

    boost::sregex_token_iterator i(start, end, speciesSingleRegex, -1);
    boost::sregex_token_iterator j;
    while(i != j)
    {
        species_.push_back(Species(*i++));
    }

}

void IO::ChemkinReader::readReactions()
{

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
IO::fileToString(const std::string& fileName)
{
    ifstream fin(fileName.c_str(), ios::in);

    string fileInString((std::istreambuf_iterator<char>(fin)),
                         std::istreambuf_iterator<char>());

    return fileInString;
}

const std::vector<std::string>
IO::fileToStrings(const std::string fileName)
{
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
)
{
    static const regex re_boostRegexEscape( "[\\^\\.\\$\\|\\(\\)\\[\\]\\*\\+\\?\\/\\\\]" );
    const string rep( "\\\\\\1&" );
    string result = regex_replace(string_to_escape, re_boostRegexEscape, rep, match_default | format_sed);
    return result;
}

void IO::replaceComments(std::string& stringToReplace)
{
    regex commentRegex("(!.*?)\\n|(!.*?)$");
    string format_string = " ";
    stringToReplace = regex_replace(stringToReplace, commentRegex, format_string, match_default | format_sed);
    //stringToReplace = format_string;
}
