/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"

using namespace std;


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
  transfile_(transfile)
{}

void IO::ChemkinReader::check()
{
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;
}

void IO::ChemkinReader::readElements()
{

    smatch result;
    string chemfilestring = fileToString(chemfile_);
    regex_search(chemfilestring, result, elementListRegex);
    string elementString = result[1];

    std::string::const_iterator start = elementString.begin();
    std::string::const_iterator end = elementString.end();
    boost::match_results<std::string::const_iterator> what;

    while (regex_search(start, end, what, elementSingleRegex))
    {
        elements_.push_back(Element(what[1],0.0));
        start = what[0].second;
    }

    cout << elements_ << endl;

}

void IO::ChemkinReader::readSpecies()
{

    smatch result;
    string chemfilestring = fileToString(chemfile_);
    regex_search(chemfilestring, result, speciesListRegex);
    string speciesString = result[1];

    std::string::const_iterator start = speciesString.begin();
    std::string::const_iterator end = speciesString.end();

    boost::sregex_token_iterator i(start, end, speciesSingleRegex, -1);
    boost::sregex_token_iterator j;
    while(i != j)
    {
        species_.push_back(Species(*i++));
    }

    cout << species_ << endl;

}

void IO::ChemkinReader::readReactions()
{

    smatch result;
    string chemfilestring = fileToString(chemfile_);
    regex_search(chemfilestring, result, reactionListRegex);
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

std::string
IO::fileToString(const std::string& fileName)
{
    string fileInString;
    ifstream fin(fileName.c_str(), ios::in);

    while (fin.good())     // loop while extraction from file is possible
    {
      char c = fin.get();  // get character from file
      if (fin.good())
          fileInString.append(1,c);
    }
    return fileInString;
}
