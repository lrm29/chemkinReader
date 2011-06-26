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

namespace IO
{

    class Reaction
    {

            //! Is the reaction reversible or not?
            bool reversible_;

            //! reactant & product stoichiometry.
            std::multimap<std::string, double> reactants_, products_;

            //! Total stoichiometry changes.
            double dstoich_, dreac_, dprod_;

            //! Forward and reverse Arrhenius parameters.
            double A_; // Pre-exponential factor.
            double n_; // Temperature exponent.
            double E_; // Activation energy.

            // Third bodies.
            //! Set to true if this reaction requires third bodies.
            bool flagThirdBody_;
            //! Reaction third bodies and their coefficients.
            std::multimap<std::string, double> thirdBodies_;

        public:

            Reaction
            (
            );

            ~Reaction(){}

            void setIrreversible();

            void setArrhenius(double A, double n, double E);

            void setReactants(std::multimap<std::string, double> reactants);

            void setProducts(std::multimap<std::string, double> products);

            friend std::ostream& operator<<(std::ostream& output, const Reaction& reaction);

    };


} // namespace IO

#endif /* REACTION_H_ */
