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

using namespace boost;

namespace IO
{

    typedef std::vector<std::string> stringVector;

    class ChemkinReader
    {
            stringVector elements_;

            const std::string chemfile_;
            const std::string thermfile_;
            const std::string transfile_;

        public:

            ChemkinReader
            (
                const std::string chemfile,
                const std::string thermfile,
                const std::string transfile
            );

            ~ChemkinReader(){}
            
            void read();

            void check();

    };

} // namespace IO

#endif /* CHEMKINREADER_H_ */
