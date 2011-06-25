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
   reversible_(-1),
   reactants_(),
   products_()
{}

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

void IO::Reaction::setReactants(map<string, double> reactants)
{
    reactants_ = reactants;
}

void IO::Reaction::setProducts(map<string, double> products)
{
    products_ = products;
}

namespace IO
{

    ostream& operator<<(ostream& output, const Reaction& reaction)
    {
        map<string,double>::const_iterator iter;

        output << "    Reaction Data:\n"
               << "    (\n";
        output << "        Reactants:\n"
               << "        (\n";
       for (iter = reaction.reactants_.begin(); iter != reaction.reactants_.end(); ++iter)
       {
        output << "            Name : " << setw(10) <<iter->first << " | Stoich : " << iter->second << "\n";
       }
        output << "        )\n"
               << "        Products:\n"
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
               << "    )";
        return output;
    }

}
