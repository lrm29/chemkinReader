/*
 * reaction.cpp
 *
 *  Created on: Jun 25, 2011
 *      Author: lrm29
 */

#include "reaction.h"
#include <iomanip>

using namespace std;

IO::Reaction::Reaction()
:
   reversible_(true),
   reactants_(),
   products_(),
   A_(-1),
   n_(-1),
   E_(-1),
   flagThirdBody_(false),
   thirdBodies_()
{}

void IO::Reaction::setIrreversible()
{
    reversible_ = false;
}

void IO::Reaction::setArrhenius
(
    double A,
    double n,
    double E
)
{
    A_ = A;
    n_ = n;
    E_ = E;
}

void IO::Reaction::setReactants(multimap<string, double> reactants)
{
    reactants_ = reactants;
    checkForThirdBody(reactants);
}

void IO::Reaction::setProducts(multimap<string, double> products)
{
    products_ = products;
    checkForThirdBody(products);
}

void IO::Reaction::checkForThirdBody(const multimap<string, double>& species)
{
    multimap<string,double>::const_iterator iter;
    for (iter = species.begin(); iter != species.end(); ++iter)
    {
        if(iter->first == "M")
        {
            flagThirdBody_ = true;
        }
    }
}

void IO::Reaction::setThirdBodies(const multimap<string, double>& thirdBodies)
{
    thirdBodies_ = thirdBodies;
}

namespace IO
{

    ostream& operator<<(ostream& output, const Reaction& reaction)
    {
        multimap<string,double>::const_iterator iter;

        output << "    Reaction Data\n"
               << "    (\n"
               << "        Reversible : " << reaction.reversible_ << "\n"
               << "        Reactants\n"
               << "        (\n";
       for (iter = reaction.reactants_.begin(); iter != reaction.reactants_.end(); ++iter)
       {
        output << "            Name : " << setw(10) <<iter->first << " | Stoich : " << iter->second << "\n";
       }
        output << "        )\n"
               << "        Products\n"
               << "        (\n";
       for (iter = reaction.products_.begin(); iter != reaction.products_.end(); ++iter)
       {
        output << "            Name : " << setw(10) <<iter->first << " | Stoich : " << iter->second << "\n";
       }
        output << "        )\n"
               << "        Arrhenius\n"
               << "        (\n"
               << "            A = " << reaction.A_ << "\n"
               << "            n = " << reaction.n_ << "\n"
               << "            E = " << reaction.E_ << "\n"
               << "        )\n"
               << "        Third Bodies\n"
               << "        (\n"
               << "            Third Body : " << reaction.flagThirdBody_ << "\n";
       for (iter = reaction.thirdBodies_.begin(); iter != reaction.thirdBodies_.end(); ++iter)
       {
        output << "            Name : " << setw(10) <<iter->first << " | Efficiency Factor : " << iter->second << "\n";
       }
        output << "        )\n"
               << "    )";
        return output;
    }

}
