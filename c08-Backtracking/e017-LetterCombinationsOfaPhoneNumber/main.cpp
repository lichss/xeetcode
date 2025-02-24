#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"
#include <string>
#include <map>

class Solution {
private:
    std::vector<std::string> combs;
    std::string path;
    std::string digit;
    
    std::map<char, std::vector<char>> m = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void backtrack(int index){
        if(index == digit.size()-1){       
            for(auto letter:m[digit[index]] ){
                path.push_back(letter);
                combs.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        auto number = digit[index];
        for(auto letter:m[number]){
            path.push_back(letter);
            backtrack(index+1);
            path.pop_back();
        }
        
        return;
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        digit = digits;
        backtrack(0);
        return combs;

    }
};

int main() {

    return 0;
}