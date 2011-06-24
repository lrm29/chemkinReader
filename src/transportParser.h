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

            std::string tran_file;

        public:

            TransportParser();

            ~TransportParser(){}

            void parse(std::string tran_file);

    };

}

#endif /* TRANSPORT_H_ */
