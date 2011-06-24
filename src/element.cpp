/*
 * element.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "element.h"

using namespace std;

IO::Element::Element
(
    const string name,
    const double atomicWeight
)
:
    name_(name),
    atomicWeight_(atomicWeight)
{}

namespace IO
{

    ostream& operator<<(ostream& output, const Element& element)
    {
        output << "(" << element.name_ << ", " << element.atomicWeight_ << ")";
        return output;
    }

}
