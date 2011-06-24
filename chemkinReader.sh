#!/bin/bash

EXECUTABLE=`find . -name chemkinReaderTest`

echo $EXECUTABLE

$EXECUTABLE test/easychem.inp test/therm.dat test/tran.dat
