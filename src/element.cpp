/*
 * element.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "element.h"

IO::Element::Element
(
    const std::string name,
    const double atomicWeight
)
:
    name_(name),
    atomicWeight_(atomicWeight)
{}

namespace IO {

    std::ostream& operator<<(std::ostream& stream, const Element& element)
    {
        stream << "(" << element.name_ << ", " << element.atomicWeight_ << ")";
        return stream;
    }

}
