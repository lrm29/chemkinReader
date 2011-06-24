/*
 * species.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "species.h"

using namespace std;

IO::Species::Species
(
    const string name
)
:
    name_(name)
{}

IO::Transport& IO::Species::transport()
{
    return transport_;
}

namespace IO
{

    ostream& operator<<(ostream& output, const Species& species)
    {
        output << "(\n"
               << "    Species: \n    (\n        Name = " << species.name_ << "\n    )\n"
               << "    " << species.transport_
               << "\n )";
        return output;
    }

}
