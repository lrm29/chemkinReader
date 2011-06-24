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

void IO::TransportParser::parse(const std::vector<Species>& species)
{
    cout << "Transport file: " << tranfile_ << endl;

    for(size_t i = 0; i != species.size(); ++i) {
        findSpecies(species[i]);
    }

}


void IO::TransportParser::findSpecies(const Species& specie)
{

    smatch what;
    boost::regex reg(specie.name()+transportRegex);

    std::string::const_iterator start = transportfilestring_.begin();
    std::string::const_iterator end = transportfilestring_.end();

    regex_search(start, end, what, reg);

    cout << specie.name() << " "
         << "Mol Ind: " << what[1] << " "
         << "Well depth: " << what[2] << " "
         << "Coll. Diameter: " << what[3] << " "
         << "Dipole moment: " << what[4] << " "
         << "Polarizability: " << what[5] << " "
         << "Relax number: " << what[6] << endl;

}
