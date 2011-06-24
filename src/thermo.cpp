/*
 * thermo.cpp
 *
 *  Created on: Jun 24, 2011
 *      Author: gigadot
 */

#include "thermo.h"

IO::Thermo::Thermo(const std::string species_name)
:
species_name_(species_name) {
}

namespace IO {

    std::ostream& operator<<(std::ostream& output, const Thermo& thermo) {
        output << "(" << thermo.species_name_ << ")";
        return output;
    }
}