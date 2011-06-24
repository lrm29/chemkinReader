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

using namespace boost;

namespace IO {

    class TransportParser
    {

            static const regex transportRegex;

            const std::string tranfile_;
            const std::string transportfilestring_;

            void findSpecies(const Species& specie);

        public:

            TransportParser(const std::string tranfile);

            ~TransportParser(){}

            void parse(const std::vector<Species>& species);

    };

}

#endif /* TRANSPORT_H_ */
