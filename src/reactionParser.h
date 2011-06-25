/*
 * reactionParser.h
 *
 *  Created on: Jun 23, 2011
 *      Author: Laurence R. McGlashan
 *     License: GPL
 */

#ifndef REACTIONPARSER_H_
#define REACTIONPARSER_H_

#include <string>

namespace IO {

    class ReactionParser
    {

            const std::string reactionfile_;
            const std::string reactionfilestring_;

        public:

            ReactionParser(const std::string reactionfile);

            ~ReactionParser(){}

            void parse();

    };

}

#endif /* REACTIONPARSER_H_ */
