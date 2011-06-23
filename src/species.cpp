/*
 * species.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "species.h"

IO::Species::Species
(
    const std::string name
)
:
    name_(name)
{}

namespace IO
{

    std::ostream& operator<<(std::ostream& output, const Species& species)
    {
        output << "(" << species.name_ << ")";
        return output;
    }

}
