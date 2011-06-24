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

        public:

            Species
            (
                const std::string name
            );

            ~Species(){}

            friend std::ostream& operator<<(std::ostream& output, const Species& element);

    };


} // namespace IO

#endif /* SPECIES_H_ */