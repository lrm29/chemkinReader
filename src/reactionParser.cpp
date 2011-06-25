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
    smatch what;

    while (regex_search(start, end, what, reactionSingleRegex))
    {

        Reaction reaction;
        reaction.setReactants(parseReactionSpecies(what[1]));
        reaction.setProducts(parseReactionSpecies(what[2]));

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

std::multimap<std::string, double>
IO::ReactionParser::parseReactionSpecies(string reactionSpecies)
{

    std::multimap<std::string, double> reactionSpeciesMap;

    regex splitSpecies("\\+");
    regex splitStoichiometry("([0-9]*)(\\w+)");

    sregex_token_iterator i(reactionSpecies.begin(), reactionSpecies.end(), splitSpecies,-1);
    sregex_token_iterator j;
    while (i != j)
    {
        // *i Gives a reactant species. Now get its stoichiometry.
        smatch splitStoic;
        // ++ iterates to the next reactant!
        string reactionSpecie = *i++;

        string::const_iterator start = reactionSpecie.begin();
        string::const_iterator end = reactionSpecie.end();

        regex_search(start, end, splitStoic, splitStoichiometry);

        if (splitStoic[1] == "")
        {
            reactionSpeciesMap.insert
            (
                pair<string,double>
                (
                    splitStoic[2],
                    1.0
                )
            );
        }
        else
        {
             reactionSpeciesMap.insert
             (
                 pair<string,double>
                 (
                     splitStoic[2],
                     from_string<double>(splitStoic[1])
                 )
             );
         }
    }

    return reactionSpeciesMap;

}
