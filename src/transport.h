/*
 * transport.h
 *
 *  Created on: Jun 24, 2011
 *      Author: Laurence R. McGlashan
 */

#ifndef TRANSPORT_H_
#define TRANSPORT_H_

#include <string>
#include <iostream>
#include <vector>

namespace IO
{

    class Transport
    {
        public:

            Transport();

            ~Transport(){}

            void setMoleculeIndex(const int moleculeIndex);

            void setCollisionDiameter(const double collisionDiameter_);

            void setDipoleMoment(const double dipoleMoment_);

            void setPolarizability(const double polarizability_);

            void setPotentialWellDepth(const double potentialWellDepth_);

            void setRotRelaxationNumber(const double rotRelaxationNumber_);

            friend std::ostream& operator<<(std::ostream& output, const Transport& transport);

        private:

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

    };

} // namespace IO

#endif /* TRANSPORT_H_ */
