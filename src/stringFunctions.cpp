/*
 * stringFunctions.cpp
 *
 *  Created on: Jun 24, 2011
 *      Author: Laurence R. McGlashan
 */

#include "stringFunctions.h"
#include "boost/regex.hpp"

using namespace std;
using namespace boost;

const string
IO::fileToString(const string& fileName)
{
    ifstream fin(fileName.c_str(), ios::in);

    string fileInString((istreambuf_iterator<char>(fin)),
                         istreambuf_iterator<char>());

    return fileInString;
}

const vector<string>
IO::fileToStrings(const string fileName)
{
    vector<string> lines;
    ifstream fin(fileName.c_str(), ios::in);
    string line;
    while (getline(fin, line)) {
        lines.push_back(line);
    }
    return lines;
}

string
IO::regex_escape(const string& string_to_escape)
{
    static const regex re_boostRegexEscape("[\\^\\.\\$\\|\\(\\)\\[\\]\\*\\+\\?\\/\\\\]");
    const string rep("\\\\\\1&");
    string result = regex_replace(string_to_escape, re_boostRegexEscape, rep, match_default | format_sed);
    return result;
}


string
IO::replaceComments(string stringToReplace)
{
    regex commentRegex("(!.*?)\\n|(!.*?)$");
    string format_string = " \\n";
    stringToReplace = regex_replace(stringToReplace, commentRegex, format_string, match_default | format_sed);
    return stringToReplace;
}

string
IO::convertToCaps(const string &str)
{
    string::const_iterator i;
    string caps;

    for (i=str.begin(); i!=str.end(); i++) {
        switch (*i) {
            case 'a': caps.append("A"); break;
            case 'b': caps.append("B"); break;
            case 'c': caps.append("C"); break;
            case 'd': caps.append("D"); break;
            case 'e': caps.append("E"); break;
            case 'f': caps.append("F"); break;
            case 'g': caps.append("G"); break;
            case 'h': caps.append("H"); break;
            case 'i': caps.append("I"); break;
            case 'j': caps.append("J"); break;
            case 'k': caps.append("K"); break;
            case 'l': caps.append("L"); break;
            case 'm': caps.append("M"); break;
            case 'n': caps.append("N"); break;
            case 'o': caps.append("O"); break;
            case 'p': caps.append("P"); break;
            case 'q': caps.append("Q"); break;
            case 'r': caps.append("R"); break;
            case 's': caps.append("S"); break;
            case 't': caps.append("T"); break;
            case 'u': caps.append("U"); break;
            case 'v': caps.append("V"); break;
            case 'w': caps.append("W"); break;
            case 'x': caps.append("X"); break;
            case 'y': caps.append("Y"); break;
            case 'z': caps.append("Z"); break;
            default: caps.append(i,i+1); break;
        }
    }
    return caps;

}

string
IO::trim(const string &str)
{
    int b = str.find_first_not_of(" \t");
    if (b < 0)
        return "";
    int e = str.find_last_not_of(" \t");

    return str.substr(b, e - b + 1);
}
