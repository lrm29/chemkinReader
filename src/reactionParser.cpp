/*
 * reactionParser.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: gigadot
 *     License: Apache 2.0
 */

#include <boost/algorithm/string.hpp>

#include "reactionParser.h"
#include "stringFunctions.h"
#include "reaction.h"

using namespace std;
using namespace boost;

const regex IO::ReactionParser::reactionSingleRegex
(
    "(.*?)\\s*(<=>|=>|=)\\s*(.*?)([0-9]+\\.[0-9]*E(?:|\\+|\\-)[0-9]+)\\s+(.*?)\\s+(.*?)$|\\n"
);

const regex IO::ReactionParser::blankLine
(
    "\\s?\\n?$"
);

// Empty default constructor, can be removed but leave it there just in case.
IO::ReactionParser::ReactionParser
(
    const string reactionString
)
:
    reactionString_(reactionString)
{
    split(reactionStringLines_, reactionString, boost::is_any_of("\n"));

    // Check for a blank line and erase.
    for (size_t i=0; i<reactionStringLines_.size(); ++i)
    {
        if(isBlankLine(reactionStringLines_[i]))
        {
            reactionStringLines_.erase(reactionStringLines_.begin()+i);
            --i;
        }
    }
}

void IO::ReactionParser::parse(vector<IO::Reaction>& reactions)
{

    cout << reactionStringLines_ << endl;

    for (size_t i=0; i<reactionStringLines_.size(); ++i)
    {

        smatch what;
        string::const_iterator start = reactionStringLines_[i].begin();
        string::const_iterator end = reactionStringLines_[i].end();

        regex_search(start, end, what, reactionSingleRegex);

        Reaction reaction;

        reaction.setReactants(parseReactionSpecies(what[1]));
        reaction.setProducts(parseReactionSpecies(what[3]));

        if (what[2] == "=>") reaction.setIrreversible();

        if (reaction.hasThirdBody())
        {
            // Parse the next line. If it is a reaction then continue,
            // otherwise look at the next lines. (Currently just look for third
            // bodies. Will need to check for extra things).
            smatch what2;
            start = reactionStringLines_[i+1].begin();
            end = reactionStringLines_[i+1].end();
            cout << reactionStringLines_[i] << endl;
            cout << reactionStringLines_[i+1] << endl;
            if (!regex_search(start, end, what2, reactionSingleRegex))
            {
                reaction.setThirdBodies(parseThirdBodySpecies(reactionStringLines_[i+1]));
                // Skip one line when looking for the next reaction.
                ++i;
            }
        }

        reaction.setArrhenius
        (
            from_string<double>(what[4]),
            from_string<double>(what[5]),
            from_string<double>(what[6])
        );

        reactions.push_back(reaction);

    }

}

multimap<string, double>
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

multimap<string, double>
IO::ReactionParser::parseThirdBodySpecies(const string& thirdBodies)
{

    multimap<string, double> thirdBodyMap;
    // Split the next line using / as delimiter.
    regex splitThirdBodies("\\/");

    sregex_token_iterator j
    (
        thirdBodies.begin(),
        thirdBodies.end(),
        splitThirdBodies,
        -1
    );
    sregex_token_iterator k;

    while (j != k)
    {
        string name = *j++;
        double efficiencyFactor = from_string<double>(*j++);
        thirdBodyMap.insert(pair<string,double>(trim(name),efficiencyFactor));
    }

    return thirdBodyMap;

}

bool
IO::ReactionParser::isBlankLine(const string& line)
{

    string::const_iterator start = line.begin();
    string::const_iterator end = line.end();

    return regex_match(start, end, blankLine);

}
