# Specification file for the CMake build system
#
# Laurence R. McGLashan
# 22 June 2011

project (CHEMKINREADER)

add_library(chemkinReader 
            chemkinReader.cpp 
            thermoParser.cpp 
            transportParser.cpp 
            element.cpp 
            species.cpp)
