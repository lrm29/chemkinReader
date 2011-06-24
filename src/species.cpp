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
    name_(name),
    moleculeIndex_(-1),
    potentialWellDepth_(-1.0),
    collisionDiameter_(-1.0),
    dipoleMoment_(-1.0),
    polarizability_(-1.0),
    rotRelaxationNumber_(-1.0)
{}

namespace IO
{

    std::ostream& operator<<(std::ostream& output, const Species& species)
    {
        output << "(\n"
               << "    Species Name = " << species.name_ << "\n"
               << "    Mol. Index = " << species.moleculeIndex_ << "\n"
               << "    Potential Well Depth = " << species.potentialWellDepth_ << "\n"
               << "    Collision Diameter = " << species.collisionDiameter_ << "\n"
               << "    Dipole Moment = " << species.dipoleMoment_ << "\n"
               << "    Polarizability = " << species.polarizability_ << "\n"
               << "    Rotational Relaxation Number = " << species.rotRelaxationNumber_
               << "\n )";
        return output;
    }

}
