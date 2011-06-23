/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"

using namespace std;


const regex IO::ChemkinReader::elementListRegex("ELEM(?:|ENT|ENTS)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::elementSingleRegex("(\\w+)");

const regex IO::ChemkinReader::speciesListRegex("SPEC(?:|IE|IES)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::speciesSingleRegex("\\s+");

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

void IO::ChemkinReader::read()
{
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


}

void IO::ChemkinReader::check()
{
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;
}

std::string
IO::ChemkinReader::fileToString(const std::string& fileName)
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

    cout << speciesString<< endl;

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
