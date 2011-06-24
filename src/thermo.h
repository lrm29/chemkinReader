/*
 * thermo.h
 *
 *  Created on: Jun 24, 2011
 *      Author: gigadot
 */

#ifndef THERMO_H_
#define THERMO_H_

#include <string>
#include <iostream>

namespace IO {

    class Thermo {
    public:

        Thermo(const std::string species_name);

        ~Thermo() {
        }

        const std::string getSpeciesName() const;

        friend std::ostream& operator<<(std::ostream& output, const Thermo& thermo);

    private:
        std::string species_name_;

    };

} // namespace IO

#endif /* THERMO_H_ */
