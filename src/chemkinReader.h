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
#include <fstream>

#include "element.h"
#include "species.h"

using namespace boost;

namespace IO
{

    class ChemkinReader
    {

            static const regex elementListRegex;
            static const regex elementSingleRegex;
            static const regex speciesListRegex;
            static const regex speciesSingleRegex;

            const std::string chemfile_;
            const std::string thermfile_;
            const std::string transfile_;

            std::vector<Element> elements_;
            std::vector<Species> species_;

            //! Read a file into a std::string.
            std::string fileToString(const std::string& fileName);

        public:

            ChemkinReader
            (
                const std::string chemfile,
                const std::string thermfile,
                const std::string transfile = "NOT READ"
            );

            ~ChemkinReader(){}

            void check();

            void readElements();

            void readSpecies();

    };

    //! Output a vector.
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
