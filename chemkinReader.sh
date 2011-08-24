#!/bin/bash

EXECUTABLE=`find . -name chemkinReaderTest`

echo $EXECUTABLE

$EXECUTABLE test/hardchem.inp test/therm-abf.dat test/tran.dat
