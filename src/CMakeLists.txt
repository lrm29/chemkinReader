# Specification file for the CMake build system
#
# Laurence R. McGLashan
# 22 June 2011

project (CHEMKINREADER)

add_library(chemkinReader 
            stringFunctions.cpp
            element.cpp 
            transport.cpp
            species.cpp
            thermo.cpp 
            thermoParser.cpp 
            transportParser.cpp
            chemkinReader.cpp)
            