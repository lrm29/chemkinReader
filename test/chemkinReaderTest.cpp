/*!
 *\file chemkinReaderTest.cpp
 *\author Laurence R. McGlashan
 *
 *\brief Test harness for the chemkin reader.
 *
 *  Copyright (C) 2011 Laurence R. McGlashan.
 *

 Licence:
    This file is part of "mops".

    brush is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

  Contact:
    Prof Markus Kraft
    Dept of Chemical Engineering
    University of Cambridge
    New Museums Site
    Pembroke Street
    Cambridge
    CB2 3RA
    UK

    Email:       mk306@cam.ac.uk
    Website:     http://como.cheng.cam.ac.uk
 *
 *
 */

#include "chemkinReader.h"
#include "thermoParser.h"
#include "transportParser.h"

int main(int argc, char* argv[])
{

    std::cout << "Chemkin Reader Test\n";

    // Using arguments like this is rather ugly, but it saves writing full argument
    // handling code in a test program.
    const std::string chemfile(argv[1]);
    const std::string thermfile(argv[2]);
    const std::string transfile(argv[3]);

    IO::ChemkinReader chemkinReader(chemfile,thermfile);
    chemkinReader.readElements();
    chemkinReader.readSpecies();
    chemkinReader.readReactions();
    chemkinReader.check();

    IO::ThermoParser thermoParser(thermfile);
    thermoParser.parse();

    IO::TransportParser transportParser(transfile);
    transportParser.parse(chemkinReader.species());
    chemkinReader.check();

    return 0;

}
