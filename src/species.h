/*
 * species.h
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#ifndef SPECIES_H_
#define SPECIES_H_

#include <string>
#include <iostream>

namespace IO
{

    class Species
    {

            std::string name_;

          /*  1-15: Species name
            16-80: Molecular parameters
                   molecule index: 0 = atom, 1= linear molec.
                                   2 = nonlinear molec.
                   L-J potential well depth, e/kb (K)
                   L-J collision diameter, s,
                   Dipole moment, f, Debye
                   Polarizability, `, 2
                   Rotational relaxation number, Zrot at 298K
                   Comments*/

            int moleculeIndex_;
            double potentialWellDepth_;
            double collisionDiameter_;
            double dipoleMoment_;
            double polarizability_;
            double rotRelaxationNumber_;

        public:

            Species
            (
                const std::string name
            );

            ~Species(){}

            const std::string name() const
            {return name_;}

            friend std::ostream& operator<<(std::ostream& output, const Species& element);


            void setMoleculeIndex(const int moleculeIndex)
            {
                this->moleculeIndex_ = moleculeIndex;
            }

            void setCollisionDiameter(const double collisionDiameter_)
            {
                this->collisionDiameter_ = collisionDiameter_;
            }

            void setDipoleMoment(const double dipoleMoment_)
            {
                this->dipoleMoment_ = dipoleMoment_;
            }

            void setPolarizability(const double polarizability_)
            {
                this->polarizability_ = polarizability_;
            }

            void setPotentialWellDepth(const double potentialWellDepth_)
            {
                this->potentialWellDepth_ = potentialWellDepth_;
            }

            void setRotRelaxationNumber(const double rotRelaxationNumber_)
            {
                this->rotRelaxationNumber_ = rotRelaxationNumber_;
            }

    };


} // namespace IO

#endif /* SPECIES_H_ */
