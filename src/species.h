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

#include "transport.h"
#include "thermo.h"

namespace IO
{

    class Species
    {

            std::string name_;
            double molecularWeight_;

            Transport transport_;
            Thermo thermo_;

        public:

            explicit Species
            (
                const std::string name
            );

            ~Species(){}

            std::string name() const
            {return name_;}

            Transport& transport();
            const Transport& transport() const;

            Thermo& thermo();
            const Thermo& thermo() const;

            friend std::ostream& operator<<(std::ostream& output, const Species& element);

    };


} // namespace IO

#endif /* SPECIES_H_ */
