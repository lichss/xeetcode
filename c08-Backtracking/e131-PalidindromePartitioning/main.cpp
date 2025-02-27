#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"
#include <string>

using namespace std;

/*  感觉回溯的题目越来越难。。。
    这一题做的就挺费劲的
    应该说分割和组和性质有所不同
*/

class Solution {

private:
    vector<vector<string>> combs;
    vector<string> path;
    std::string s;

    bool isPalindrome(std::string str) {
        bool palindrome = true;
        for (int i = 0, j = str.size() - 1; i < j; i++, j--) { // 更新 i 和 j
            if (str[i] != str[j]) {
                palindrome = false;
                break;
            }
        }
        return palindrome;
    }

    void backtrack(int startIndex){
        if(startIndex >= s.size()){
            combs.push_back(path);
            return;
        }

        std::string localS;    
        for(int i=startIndex;i < s.size();i++){
            localS += s[i];
            if(!isPalindrome(localS))
                continue;
            path.push_back(localS);
            backtrack(i+1);
            path.pop_back();
        }

        return;
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        backtrack(0);

        return combs;
    
    }
};


int main() {

    return 0;
}