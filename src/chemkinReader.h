/*
 * chemkinReader.h
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 *
 *  \todo The element and species parsers currently cannot handle:
 *  SPEC H2
 *  spec O2
 *
 *  ELEM H
 *  elem H
 *
 */

#ifndef CHEMKINREADER_H_
#define CHEMKINREADER_H_

#include "boost/regex.hpp"
#include <string>
#include <vector>
#include <iostream>

#include "element.h"
#include "species.h"
#include "reaction.h"

namespace IO
{

    class ChemkinReader
    {

            static const boost::regex elementListRegex;
            static const boost::regex elementSingleRegex;
            static const boost::regex speciesListRegex;
            static const boost::regex speciesSingleRegex;
            static const boost::regex reactionListRegex;

            const std::string chemfile_;
            const std::string thermfile_;
            const std::string transfile_;

            const std::string chemfilestring_;

            std::vector<Element> elements_;
            std::vector<Species> species_;
            std::vector<Reaction> reactions_;

            bool checkChemFile();

        public:

            ChemkinReader
            (
                const std::string chemfile,
                const std::string thermfile,
                const std::string transfile = "NOT READ"
            );

            ~ChemkinReader(){}

            void check();

            void readElements();

            void readSpecies();

            void readReactions();

            std::vector<Species>& species()
            {
                return species_;
            }

    };

} // namespace IO

#endif /* CHEMKINREADER_H_ */
