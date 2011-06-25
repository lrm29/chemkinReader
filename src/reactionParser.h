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

namespace IO {

    class Reaction;

    class ReactionParser
    {

            static const boost::regex reactionSingleRegex;

            const std::string reactionString_;

        public:

            ReactionParser(const std::string reactionString);

            ~ReactionParser(){}

            void parse(std::vector<IO::Reaction>& reactions);

    };

}

#endif /* REACTIONPARSER_H_ */
