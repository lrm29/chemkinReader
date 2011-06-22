/*
 * chemkinReader.h
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#ifndef CHEMKINREADER_H_
#define CHEMKINREADER_H_

#include "boost/regex.hpp"
#include <string>
#include <map>
#include <vector>
#include <iostream>

#include "element.h"

using namespace boost;

namespace IO
{

    class ChemkinReader
    {

            const std::string chemfile_;
            const std::string thermfile_;
            const std::string transfile_;

            std::vector<Element> elements_;

        public:

            ChemkinReader
            (
                const std::string chemfile,
                const std::string thermfile,
                const std::string transfile = ""
            );

            ~ChemkinReader(){}
            
            void read();

            void check();

            void readElements();

    };

    template <class T>
    std::ostream& operator<< (std::ostream& output, const std::vector<T>& v)
    {
        output << "[\n";
        for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            output << " " << *ii << std::endl;
        }
        output << "]";
        return output;
    }


} // namespace IO

#endif /* CHEMKINREADER_H_ */
