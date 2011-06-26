/*
 * reactionParser.h
 *
 *  Created on: Jun 23, 2011
 *      Author: Laurence R. McGlashan
 *     License: GPL
 */

#ifndef REACTIONPARSER_H_
#define REACTIONPARSER_H_

#include "boost/regex.hpp"
#include <string>
#include <map>

namespace IO {

    class Reaction;

    class ReactionParser
    {

            static const boost::regex reactionSingleRegex;

            const std::string reactionString_;
            std::vector<std::string> reactionStringLines_;

        public:

            ReactionParser(const std::string reactionString);

            ~ReactionParser(){}

            void parse(std::vector<IO::Reaction>& reactions);

            std::multimap<std::string, double> parseReactionSpecies(std::string reactants);
            std::multimap<std::string, double> parseThirdBodySpecies(const std::string& thirdBodies);
    };

}

#endif /* REACTIONPARSER_H_ */
