/*
 * reactionParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include "reactionParser.h"
#include "stringFunctions.h"
#include "reaction.h"

using namespace std;
using namespace boost;

const regex IO::ReactionParser::reactionSingleRegex
(
    "(.*?)=(.*?)\\s+(.*?)\\s+(.*?)\\s+(.*?)\\s+"
);

// Empty default constructor, can be removed but leave it there just in case.
IO::ReactionParser::ReactionParser
(
    const string reactionString
)
:
    reactionString_(reactionString)
{}

void IO::ReactionParser::parse(std::vector<IO::Reaction>& reactions)
{

    string::const_iterator start = reactionString_.begin();
    string::const_iterator end = reactionString_.end();
    match_results<string::const_iterator> what;

    while (regex_search(start, end, what, reactionSingleRegex))
    {

        Reaction reaction;

        for (size_t i=0; i<what.size(); ++i)
        {
            cout << what[i] << "|";
        }
        cout << endl;

        //parseReactants(what[1]);
        //parseProducts(what[2]);

        reaction.setArrhenius
        (
            from_string<double>(what[3]),
            from_string<double>(what[4]),
            from_string<double>(what[5])
        );

        reactions.push_back(reaction);

        start = what[0].second;
    }

}
