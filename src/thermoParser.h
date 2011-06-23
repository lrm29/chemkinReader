/*
 * thermoParser.h
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#ifndef THERMOPARSER_H_
#define THERMOPARSER_H_

#include "boost/regex.hpp"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

#include "element.h"

using namespace boost;

namespace IO {

    class ThermoParser {
        std::string therm_file;

    public:

        ThermoParser();

        ~ThermoParser() {
        }

        void parse(std::string therm_file);

    };

}

#endif /* THERMOPARSER_H_ */
