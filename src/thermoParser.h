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
    public:

        ThermoParser();

        ~ThermoParser() {
        }

        void parse(std::string thermo_file);

    private:

        /**
         * Private self-contained function. It does exactly what is named.
         * 
         * @param file
         * @return 
         */
        std::vector<std::string> fileToStrings(std::string file);

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
