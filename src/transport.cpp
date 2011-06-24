/*
 * transport.cpp
 *
 *  Created on: Jun 24, 2011
 *      Author: Laurence R. McGlashan
 */

#include "transport.h"

using namespace std;

IO::Transport::Transport()
:
    moleculeIndex_(-1),
    potentialWellDepth_(-1.0),
    collisionDiameter_(-1.0),
    dipoleMoment_(-1.0),
    polarizability_(-1.0),
    rotRelaxationNumber_(-1.0)
{}

void IO::Transport::setMoleculeIndex(const int moleculeIndex)
{
   this->moleculeIndex_ = moleculeIndex;
}

void IO::Transport::setCollisionDiameter(const double collisionDiameter_)
{
   this->collisionDiameter_ = collisionDiameter_;
}

void IO::Transport::setDipoleMoment(const double dipoleMoment_)
{
   this->dipoleMoment_ = dipoleMoment_;
}

void IO::Transport::setPolarizability(const double polarizability_)
{
   this->polarizability_ = polarizability_;
}

void IO::Transport::setPotentialWellDepth(const double potentialWellDepth_)
{
   this->potentialWellDepth_ = potentialWellDepth_;
}

void IO::Transport::setRotRelaxationNumber(const double rotRelaxationNumber_)
{
   this->rotRelaxationNumber_ = rotRelaxationNumber_;
}


namespace IO {

    ostream& operator<<(ostream& output, const Transport& transport) {
        output << "Transport Data:\n    (\n"
               << "        Mol. Index = " << transport.moleculeIndex_ << "\n"
               << "        Potential Well Depth = " << transport.potentialWellDepth_ << "\n"
               << "        Collision Diameter = " << transport.collisionDiameter_ << "\n"
               << "        Dipole Moment = " << transport.dipoleMoment_ << "\n"
               << "        Polarizability = " << transport.polarizability_ << "\n"
               << "        Rotational Relaxation Number = " << transport.rotRelaxationNumber_
               << "\n    )";
        return output;
    }
}
