/*
 * chemkinReader.h
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 *
 *  \todo The element and species parsers currently cannot handle:
 *  SPEC H2
 *  spec O2
 *
 *  ELEM H
 *  elem H
 *
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
#include <sstream>

#include "element.h"
#include "species.h"

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

    std::string regex_escape
    (
        const std::string& string_to_escape
    );

    std::string replaceComments(std::string stringToReplace);

    std::string convertToCaps(const std::string &str);

    std::string trim(const std::string &str);

    class ChemkinReader
    {

            static const boost::regex elementListRegex;
            static const boost::regex elementSingleRegex;
            static const boost::regex speciesListRegex;
            static const boost::regex speciesSingleRegex;
            static const boost::regex reactionListRegex;
            static const boost::regex reactionSingleRegex;

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

            std::vector<Species>& species()
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


    template <class T>
    T from_string
    (
        const std::string& s,
        std::ios_base& (*f)(std::ios_base&) = std::dec
    )
    {
      std::istringstream iss(s);
      T t;
      iss >> f >> t;
      return t;
    }

} // namespace IO

#endif /* CHEMKINREADER_H_ */
