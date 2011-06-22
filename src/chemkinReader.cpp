/*
 * chemkinReader.cpp
 *
 *  Created on: Jun 22, 2011
 *      Author: lrm29
 */

#include "chemkinReader.h"

using namespace std;

IO::ChemkinReader::ChemkinReader
(
    const string chemfile,
    const string thermfile,
    const string transfile
)
:
  chemfile_(chemfile),
  thermfile_(thermfile),
  transfile_(transfile)
{}

void IO::ChemkinReader::check()
{
    cout << "Chemistry file: " << chemfile_ << endl;
    cout << "Thermo file: "<< thermfile_ << endl;
    if (transfile_ == "") cout << "No trans file.\n";
    cout << "Trans file: "<< transfile_ << endl;

    string seq = "foo@helloworld.com";
    regex rgx("(.*)@(.*)");
    smatch result;
    regex_search(seq, result, rgx);
    for(size_t i=0; i<result.size(); ++i)
    {
        cout << result[i] << endl;
    }
    if (result.size() == 0)
    {
        cout << "Regex library not working yet!" << endl;
    }

}
