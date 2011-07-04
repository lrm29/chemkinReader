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
   flagReversible_(true),
   flagDuplicate_(false),
   reactants_(),
   products_(),
   forwardArrhenius_(),
   reverseArrhenius_(),
   flagThirdBody_(false),
   flagPressureDependent_(false),
   thirdBodies_()
{}

void IO::Reaction::setIrreversible()
{
    flagReversible_ = false;
}

void IO::Reaction::setArrhenius
(
    double A,
    double n,
    double E,
    bool reversible
)
{
    if (reversible)
    {
        reverseArrhenius_.A_ = A;
        reverseArrhenius_.n_ = n;
        reverseArrhenius_.E_ = E;
    }
    else
    {
        forwardArrhenius_.A_ = A;
        forwardArrhenius_.n_ = n;
        forwardArrhenius_.E_ = E;
    }
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

void IO::Reaction::setLOW(const vector<double>& LOW)
{
    LOW_ = LOW;
}

void IO::Reaction::setTROE(const vector<double>& TROE)
{
    TROE_ = TROE;
}

void IO::Reaction::setPressureDependent()
{
    flagPressureDependent_ = true;
}

void IO::Reaction::setDuplicate()
{
    flagDuplicate_ = true;
}

namespace IO
{

    ostream& operator<<(ostream& output, const Reaction& reaction)
    {
        multimap<string,double>::const_iterator iter;
        vector<double>::const_iterator iterVec;

        output << "    Reaction Data\n"
               << "    (\n"
               << "        Reversible  : " << reaction.flagReversible_ << "\n"
               << "        P Dependent : " << reaction.flagPressureDependent_ << "\n"
               << "        Duplicate : " << reaction.flagDuplicate_ << "\n"
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
               << "            Forward A = " << reaction.forwardArrhenius_.A_ << "\n"
               << "                    n = " << reaction.forwardArrhenius_.n_ << "\n"
               << "                    E = " << reaction.forwardArrhenius_.E_ << "\n"
               << "            Reverse A = " << reaction.reverseArrhenius_.A_ << "\n"
               << "                    n = " << reaction.reverseArrhenius_.n_ << "\n"
               << "                    E = " << reaction.reverseArrhenius_.E_ << "\n"
               << "        )\n"
               << "        Third Bodies\n"
               << "        (\n"
               << "            Third Body : " << reaction.flagThirdBody_ << "\n";
       for (iter = reaction.thirdBodies_.begin(); iter != reaction.thirdBodies_.end(); ++iter)
       {
        output << "            Name : " << setw(10) <<iter->first << " | Efficiency Factor : " << iter->second << "\n";
       }
       for (iterVec = reaction.LOW_.begin(); iterVec != reaction.LOW_.end(); ++iterVec)
       {
        output << "            LOW : " << *iterVec << "\n";
       }
       for (iterVec = reaction.TROE_.begin(); iterVec != reaction.TROE_.end(); ++iterVec)
       {
        output << "            TROE : " << *iterVec << "\n";
       }
        output << "        )\n"
               << "    )";
        return output;
    }

}
