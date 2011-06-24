/*
 * transportParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "transportParser.h"

using namespace std;

const string IO::TransportParser::transportRegex("\\s+([0-2]+?)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)");

// Empty default constructor, can be removed but leave it there just in case.
IO::TransportParser::TransportParser
(
    const std::string tranfile
)
:
    tranfile_(tranfile),
    transportfilestring_(fileToString(tranfile))
{}

void IO::TransportParser::parse(std::vector<Species>& species)
{
    cout << "Transport file: " << tranfile_ << endl;

    for(size_t i = 0; i != species.size(); ++i) {
        smatch specieTransportData = findSpecies(species[i]);
        setSpecieData(species[i], specieTransportData);
    }

}


const boost::smatch IO::TransportParser::findSpecies(const Species& specie)
{

    smatch what;
    boost::regex reg("\\b"+specie.name()+transportRegex);

    std::string::const_iterator start = transportfilestring_.begin();
    std::string::const_iterator end = transportfilestring_.end();

    regex_search(start, end, what, reg);

    return what;

}

void IO::TransportParser::setSpecieData
(
    Species& specie,
    const boost::smatch& specieTransportData
)
{

    specie.setMoleculeIndex(from_string<int>(specieTransportData[1]));
    specie.setPotentialWellDepth(from_string<double>(specieTransportData[2]));
    specie.setCollisionDiameter(from_string<double>(specieTransportData[3]));
    specie.setDipoleMoment(from_string<double>(specieTransportData[4]));
    specie.setPolarizability(from_string<double>(specieTransportData[5]));
    specie.setRotRelaxationNumber(from_string<double>(specieTransportData[6]));

}

