/* 
first intuition, use bottom-up permutation.
*/
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<string> > my_map;
public:
    vector<string> letterCombinations(string digits) {
        my_map = construct_map();
        vector<string> res = perm(digits);
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
    vector<string> perm(string digits) {
        //cout << digits;
        vector<string> new_vec;
        if(digits == "") return new_vec;
        string first_digit = string(1, digits[0]);     
        vector<string> letters = my_map[first_digit];
        if(digits.length() == 1) return letters;  
        for(string i : letters) {
            vector<string> vec = perm(digits.substr(1));
            for(string j : vec) {
                new_vec.push_back(i + j);
            }
        }
        return new_vec;
    }
};