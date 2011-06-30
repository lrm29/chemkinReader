/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"
#include "stringFunctions.h"
#include "reactionParser.h"

using namespace std;
using namespace boost;

const regex IO::ChemkinReader::elementListRegex("ELEM(?:|ENT|ENTS)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::elementSingleRegex("(\\w+)");

const regex IO::ChemkinReader::speciesListRegex("SPEC(?:|IE|IES)\\s+(.*?)\\s+END");
const regex IO::ChemkinReader::speciesSingleRegex("\\s+");

const regex IO::ChemkinReader::reactionListRegex("REAC(?:|TION|TIONS)\\s+(.*?)\\s+END");

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
{
    checkChemFile();
}

bool IO::ChemkinReader::checkChemFile()
{
    cout << "Checking the format of the chem.inp file." << endl;

    const regex fileStructure
    (
        "ELEM(?:|ENT|ENTS)\\s+.*?\\s+END.*?"
        "SPEC(?:|IE|IES)\\s+.*?\\s+END.*?"
        "REAC(?:|TION|TIONS)\\s+.*?\\s+END"
    );
    
    const regex unsupported("(SRI)|(HI)");
    
    if(!regex_search(chemfilestring_, fileStructure))
    {
        throw regex_error("chem.inp needs the structure:\n ELEMENTS END\n SPECIES END\n REACTIONS END.");
    }
    
    smatch result;
    if(regex_search(chemfilestring_, result, unsupported))
    {
        if (result[1] == "SRI")
            throw regex_error("SRI not supported yet.");
        if (result[2] == "HI")
            throw regex_error("HI not supported yet.");       
    }
       
    return true;
    
}

void IO::ChemkinReader::check() {
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;

    ofstream outputSpecies("speciesParsed");
    ofstream outputReactions("reactionsParsed");
    outputSpecies << elements_ << endl;
    outputSpecies << species_ << endl;
    outputReactions << reactions_ << endl;
}

void IO::ChemkinReader::readElements() {

    smatch result;
    regex_search(chemfilestring_, result, elementListRegex);
    string elementString = result[1];

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

    ReactionParser reactionParser(reactionString);
    reactionParser.parse(reactions_);

}
