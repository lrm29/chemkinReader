/*
 * reaction.cpp
 *
 *  Created on: Jun 25, 2011
 *      Author: lrm29
 */

#include "reaction.h"

using namespace std;

IO::Reaction::Reaction()
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

namespace IO
{

    ostream& operator<<(ostream& output, const Reaction& reaction)
    {
        output << "    Reaction Data:\n"
               << "    (\n"
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
