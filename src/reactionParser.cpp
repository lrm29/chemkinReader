/*
 * reactionParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "reactionParser.h"
#include "stringFunctions.h"

using namespace std;

// Empty default constructor, can be removed but leave it there just in case.
IO::ReactionParser::ReactionParser
(
    const string reactionfile
)
:
    reactionfile_(reactionfile),
    reactionfilestring_(fileToString(reactionfile))
{}

void IO::ReactionParser::parse()
{
    cout << "Reaction file: " << reactionfile_ << endl;



}
