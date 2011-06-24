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

#include "chemkinReader.h"

using namespace boost;

namespace IO {

    class ThermoParser {
    public:

        ThermoParser(const std::string thermo_file);

        ~ThermoParser() {
        }

        void parse();

    private:

        const std::string thermo_file_;
        const std::vector<std::string> lines_;

        /**
         * Private self-contained function. Get subset of given vector which contains
         * only the NASA polynomials, i.e. lines within the THERMO and END tags.
         *
         * @param lines
         * @return
         */
        std::vector<std::string> getThermoSection(std::vector<std::string> lines);

        /**
         * Check if the first four lines are valid Chemkin form of NASA polynomials
         * (7 coefficients). If there are less than 4 lines, it return false.
         *
         * @param lines
         * @return
         */
        bool isSectionMatchedNASA(std::vector<std::string> lines, unsigned int offset);

        void parseNASASection(std::string l1, std::string l2, std::string l3, std::string l4);

    };

}

#endif /* THERMOPARSER_H_ */
