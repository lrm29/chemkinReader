/*
 * thermo.cpp
 *
 *  Created on: Jun 24, 2011
 *      Author: gigadot
 */

#include "thermo.h"

IO::Thermo::Thermo(const std::string species_name)
:
species_name_(species_name) {
}

const std::string IO::Thermo::getSpeciesName() const {
    return species_name_;
}

void IO::Thermo::setNote(std::string note) {
    note_ = note;
}

std::string IO::Thermo::getNote() {
    return note_;
}

void IO::Thermo::setPhase(std::string phase) {
    phase_ = phase;
}

std::string IO::Thermo::getPhase() {
    return phase_;
}

void IO::Thermo::setTLow(double T_low) {
    T_low_ = T_low;
}

double IO::Thermo::getTLow() {
    return T_low_;
}

void IO::Thermo::setTCommon(double T_common) {
    T_common_ = T_common;
}

double IO::Thermo::getTCommon() {
    return T_common_;
}

void IO::Thermo::setTHigh(double T_high) {
    T_high_ = T_high;
}

double IO::Thermo::getTHigh() {
    return T_high_;
}

void IO::Thermo::setElementsCounts(std::string elements_counts) {
    elements_counts_ = elements_counts;
}

std::string IO::Thermo::getElementsCounts() {
    return elements_counts_;
}

void IO::Thermo::setUpperTemperatureCoefficients(
        double ah1, double ah2, double ah3,
        double ah4, double ah5, double ah6,
        double ah7) {

}

void IO::Thermo::setLowerTemperatureCoefficients(
        double al1, double al2, double al3,
        double al4, double al5,
        double al6, double al7) {

}

namespace IO {

    std::ostream& operator<<(std::ostream& output, const Thermo& thermo) {
        output << "(" << thermo.species_name_ << ")";
        return output;
    }
}
