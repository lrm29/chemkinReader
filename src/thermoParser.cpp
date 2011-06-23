/*
 * thermoParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "thermoParser.h"

using namespace std;

// Empty default constructor, can be removed but leave it there just in case.
IO::ThermoParser::ThermoParser() {
}

void IO::ThermoParser::parse() {
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
