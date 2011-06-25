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
    name_(name),
    molecularWeight_(-1),
    transport_(),
    thermo_(name)
{}

IO::Transport& IO::Species::transport()
{
    return transport_;
}

const IO::Transport& IO::Species::transport() const
{
    return transport_;
}

IO::Thermo& IO::Species::thermo()
{
    return thermo_;
}

const IO::Thermo& IO::Species::thermo() const
{
    return thermo_;
}

namespace IO
{

    ostream& operator<<(ostream& output, const Species& species)
    {
        output << "(\n"
               << "    Species: \n"
               << "    (\n"
               << "        Name = " << species.name_ << "\n"
               << "        Mol. Mass = " << species.molecularWeight_ << "\n"
               << "    )\n"
               << species.transport_ << "\n"
               << species.thermo_ << "\n"
               << ")";
        return output;
    }

}
