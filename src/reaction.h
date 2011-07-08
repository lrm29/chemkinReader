/*
 * reaction.h
 *
 *  Created on: Jun 25, 2011
 *      Author: lrm29
 */

#ifndef REACTION_H_
#define REACTION_H_

#include <string>
#include <iostream>
#include <map>
#include <vector>

namespace IO
{

    struct Arrhenius
    {
        //! Forward and reverse Arrhenius parameters.
        double A; // Pre-exponential factor.
        double n; // Temperature exponent.
        double E; // Activation energy.
    };

    class Reaction
    {

            //! Is the reaction reversible or not?
            bool flagReversible_;

            //! Is this reaction a duplicate?
            bool flagDuplicate_;

            //! reactant & product stoichiometry.
            std::multimap<std::string, double> reactants_, products_;

            //! Total stoichiometry changes.
            //double dstoich_, dreac_, dprod_;

            Arrhenius forwardArrhenius_, reverseArrhenius_;

            // Third bodies.
            //! Set to true if this reaction requires third bodies.
            bool flagThirdBody_;
            //! Set if (+M) or e.g. (+H2O) is found.
            bool flagPressureDependent_;
            //! Reaction third bodies and their coefficients.
            std::multimap<std::string, double> thirdBodies_;

            std::vector<double> LOW_, TROE_, SRI_;

        public:

            Reaction();

            ~Reaction(){}

            void setReversible(const bool flag);
            const bool& getReversible() const;

            void setArrhenius(double A, double n, double E, bool reverse=false);
            const Arrhenius& getArrhenius(bool reverse=false) const;

            void setReactants(std::multimap<std::string, double> reactants);

            void setProducts(std::multimap<std::string, double> products);

            void setThirdBodies(const std::multimap<std::string, double>& thirdBodies);

            void checkForThirdBody(const std::multimap<std::string, double>& species);

            bool hasThirdBody() const {return flagThirdBody_;}

            void setLOW(const std::vector<double>& LOW);

            void setTROE(const std::vector<double>& TROE);

            void setSRI(const std::vector<double>& SRI);

            void setPressureDependent();
            const bool& getPressureDependent() const;

            void setDuplicate();

            friend std::ostream& operator<<(std::ostream& output, const Reaction& reaction);

    };


} // namespace IO

#endif /* REACTION_H_ */
