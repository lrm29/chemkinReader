/*
 * thermo.h
 *
 *  Created on: Jun 24, 2011
 *      Author: gigadot
 */

#ifndef THERMO_H_
#define THERMO_H_

#include <string>
#include <iostream>
#include <vector>

namespace IO {

    class Thermo {

    public:

        explicit Thermo(const std::string species_name);

        ~Thermo(){}

        const std::string getSpeciesName() const;

        void setNote(std::string note);
        std::string getNote();

        void setPhase(std::string phase);
        std::string getPhase();

        void setTLow(double T_low);
        double getTLow();

        void setTCommon(double T_common);
        double getTCommon();

        void setTHigh(double T_high);
        double getTHigh();

        void setElementsCounts(std::string elements_counts);
        std::string getElementsCounts();

        void setUpperTemperatureCoefficients(
                double ah1, double ah2, double ah3,
                double ah4, double ah5, double ah6,
                double ah7);
        void setLowerTemperatureCoefficients(
                double al1, double al2, double al3,
                double al4, double al5, double al6,
                double al7);

        friend std::ostream& operator<<(std::ostream& output, const Thermo& thermo);

    private:
        std::string species_name_;
        std::string note_;
        std::string phase_;
        double T_low_;
        double T_common_;
        double T_high_;
        std::string elements_counts_;
        std::vector<double> al_;
        std::vector<double> ah_;

    };

} // namespace IO

#endif /* THERMO_H_ */
