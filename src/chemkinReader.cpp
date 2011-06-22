/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"

using namespace std;

IO::ChemkinReader::ChemkinReader(const string chemfile, const string thermfile, const string transfile)
: chemfile_(chemfile), thermfile_(thermfile), transfile_(transfile)
{
}

void IO::ChemkinReader::read()
{
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;
    // let's do the thermo file first. easiest.
    // Propose to read the whole file into string and ignore the
    // little performance cost.
    // 1. Read the whole file into string.
    // 2. Use regex to capture the content of THER (THERMO) and its end tags.
    // 3. Ignore the default temperature line for now.
    // 4. For NASA 7 coefficient polynomials, here is the snipplet
//H2                TPIS78H   2               G  200.0     3500.0    1000.0      1
//+3.3372792E+00 -4.9402473E-05 +4.9945678E-07 -1.7956639E-10 +2.0025538E-14     2
//-9.5015892E+02 -3.2050233E+00 +2.3443311E+00 +7.9805208E-03 -1.9478151E-05     3
//+2.0157209E-08 -7.3761176E-12 -9.1793517E+02 +6.8301024E-01                    4
    //    create regex(es) which match each line
    // 5. if the 4 regex(es) match the 4 lines in a row then 


}

void IO::ChemkinReader::check()
{
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: " << thermfile_ << endl;
    cout << "Trans file: " << transfile_ << endl;

    string seq = "foo@helloworld.com";
    regex rgx("(.*)@(.*)");
    smatch result;
    regex_search(seq, result, rgx);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    if (result.size() == 0) {
        cout << "Regex library not working yet!" << endl;
    }

}
