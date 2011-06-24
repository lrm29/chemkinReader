/*
 * transportParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "transportParser.h"

using namespace std;

const regex IO::TransportParser::transportRegex
("\\w+\\s+([0-2]+?)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)\\s+([0-9]+\\.[0-9]+)");

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

    //cout << "Transport file: " << tranfile_ << endl;

//    cout << transportfilestring_ << endl;

    for(size_t i = 0; i != species.size(); ++i) {
        findSpecies(species[i]);
    }





    /*std::string::const_iterator start = transportfilestring_.begin();
    std::string::const_iterator end = transportfilestring_.end();

    boost::sregex_token_iterator i(start, end, transportRegex, -1);
    boost::sregex_token_iterator j;
    while(i != j)
    {
       cout << "Species = " << *i++ << " | ";
       cout << "Molecule Index = " << *i++ << " | ";
       cout << "Well Depth = " << *i++ << " | ";
       cout << "Collision Diameter = " << *i++ << " | ";
       cout << "Dipole Moment = " << *i++ << " | ";
       cout << "Polarizability = " << *i++ << " | ";
       cout << "Rot. relax. number = " << *i++ << endl;
    }*/

    //cout << species_ << endl;

//    1-15: Species name
//    16-80: Molecular parameters
//           molecule index: 0 = atom, 1= linear molec.
//                           2 = nonlinear molec.
//           L-J potential well depth, e/kb (K)
//           L-J collision diameter, s,
//           Dipole moment, f, Debye
//           Polarizability, `, 2
//           Rotational relaxation number, Zrot at 298K
//           Comments
//
//          C2O                1   232.400     3.828     0.000     0.000     1.000 ! *


}


void IO::TransportParser::findSpecies(const Species& specie)
{
    smatch what;
    boost::regex re("\\b"+specie.name()+"\\b");
    boost::sregex_iterator i(transportfilestring_.begin(), transportfilestring_.end(), re);
    boost::sregex_iterator j;
    while(i != j)
    {
        cout << "Specie " << specie.name() << " " << *i << endl;
        /*if(regex_search(i,j,what, transportRegex))
        {

        }*/
        *i++;
    }
    // H2                 1    38.000     2.920     0.000     0.790   280.000 ! *
}
