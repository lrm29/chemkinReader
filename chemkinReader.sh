#!/bin/bash

EXECUTABLE=`find . -name chemkinReaderTest`

echo $EXECUTABLE

$EXECUTABLE test/hardchem.inp test/therm.dat test/tran.dat
