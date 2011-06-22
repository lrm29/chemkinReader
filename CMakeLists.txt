# The name of this project is "MOPSSUITE". CMakeLists files in this project can
# refer to the root source directory of the project as ${MOPSSUITE_SOURCE_DIR} and
# to the root binary directory of the project as ${MOPSSUITE_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (CHEMKINREADER)

find_package(Boost 1.43.0 REQUIRED COMPONENTS regex)

enable_testing()

# Turn off line breaks in error messages so that IDEs can parse the errors properly
IF(CMAKE_COMPILER_IS_GNUCC)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0 -Wall -O3")
ENDIF(CMAKE_COMPILER_IS_GNUCC)
IF(CMAKE_COMPILER_IS_GNUCXX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0 -Wall -O3")
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

add_executable(chemkinReaderTest test/chemkinReaderTest.cpp)
target_link_libraries(chemkinReaderTest chemkinReader ${Boost_REGEX_LIBRARY})

# Subsidiary libraries for the solvers
add_subdirectory(src)

# All the header files we have written
include_directories(src)
