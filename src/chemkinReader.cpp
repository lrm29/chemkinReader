/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"
#include "stringFunctions.h"

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
    chemfilestring_(convertToCaps(replaceComments(fileToString(chemfile_))))
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

    string::const_iterator start = elementString.begin();
    string::const_iterator end = elementString.end();
    match_results<string::const_iterator> what;

    while (regex_search(start, end, what, elementSingleRegex)) {
        elements_.push_back(Element(what[1], 0.0));
        start = what[0].second;
    }

}

void IO::ChemkinReader::readSpecies() {

    smatch result;
    regex_search(chemfilestring_, result, speciesListRegex);
    string speciesString = result[1];

    string::const_iterator start = speciesString.begin();
    string::const_iterator end = speciesString.end();

    sregex_token_iterator i(start, end, speciesSingleRegex, -1);
    sregex_token_iterator j;
    while (i != j) {
        species_.push_back(Species(*i++));
    }

}

void IO::ChemkinReader::readReactions() {

    smatch result;
    regex_search(chemfilestring_, result, reactionListRegex);
    string reactionString = result[1];

    cout << reactionString << endl;

    string::const_iterator start = reactionString.begin();
    string::const_iterator end = reactionString.end();

    sregex_token_iterator i(start, end, reactionSingleRegex, -1);
    sregex_token_iterator j;
    // while(i != j)
    // {

    // }


}
