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
#include <streambuf>

#include "element.h"
#include "species.h"

using namespace boost;

namespace IO
{

    //! Read a file into a std::string.
    const std::string fileToString(const std::string& fileName);

    /**
     * Private self-contained function. It does exactly what is named.
     *
     * @param file
     * @return
     */
    const std::vector<std::string> fileToStrings(const std::string file);

    class ChemkinReader
    {

            static const regex elementListRegex;
            static const regex elementSingleRegex;
            static const regex speciesListRegex;
            static const regex speciesSingleRegex;
            static const regex reactionListRegex;
            static const regex reactionSingleRegex;

            const std::string chemfile_;
            const std::string thermfile_;
            const std::string transfile_;

            std::string chemfilestring_;

            std::vector<Element> elements_;
            std::vector<Species> species_;



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

            void readReactions();

            const std::vector<Species> species() const
            {
                return species_;
            }

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
