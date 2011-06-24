/*
 * transportParser.h
 *
 *  Created on: Jun 23, 2011
 *      Author: Laurence R. McGlashan
 *     License: GPL
 */

#ifndef TRANSPORT_H_
#define TRANSPORT_H_

#include "boost/regex.hpp"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

#include "chemkinReader.h"

namespace IO {

    class TransportParser
    {

            static const std::string transportRegex;

            const std::string tranfile_;
            const std::string transportfilestring_;

            const boost::smatch findSpecies(const Species& specie);

            void setSpecieData
            (
                Species& specie,
                const boost::smatch& specieTransportData
            );

        public:

            TransportParser(const std::string tranfile);

            ~TransportParser(){}

            void parse(std::vector<Species>& species);

    };

}

#endif /* TRANSPORT_H_ */
