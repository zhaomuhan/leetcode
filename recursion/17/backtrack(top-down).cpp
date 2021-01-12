/* 
traditional backtrack, use top-down permutation.
*/
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<string> > my_map;
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        my_map = construct_map();
        perm("", digits);
        return res;
    }
    unordered_map<string, vector<string> > construct_map() {
        unordered_map<string, vector<string> > map;
        map["2"] = {"a", "b", "c"};
        map["3"] = {"d", "e", "f"};
        map["4"] = {"g", "h", "i"};
        map["5"] = {"j", "k", "l"};
        map["6"] = {"m", "n", "o"};
        map["7"] = {"p", "q", "r", "s"};
        map["8"] = {"t", "u", "v"};
        map["9"] = {"w", "x", "y", "z"};
        return map;
    }
    void perm(string combination, string digits) {
        if(digits == "") {
            if(combination != "") {
                res.push_back(combination);
            }
        } else {
            string first_digit = string(1, digits[0]);
            vector<string> letters = my_map[first_digit];
            for(string i : letters) {
                perm(combination + i, digits.substr(1));
            }
        }
    }
};