#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> Words;
    rawWords = convToLower(rawWords);
    size_t size = rawWords.size();
    int loc = 0;
    for(size_t i = 0; i < size; i++){
        if(!isalpha(rawWords[i])){
            if(i-loc >= 2){
                std::string temp_string = rawWords.substr(loc, i-loc);
                Words.insert(temp_string);
            }
            loc = i + 1;
        }
    }
    if(isalpha(rawWords[size-1])){
        std::string temp_string = rawWords.substr(loc, size-loc);
        Words.insert(temp_string);
    }
    return Words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
