#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"
#include <string>

/* 
    挺迷糊的。自己都不知道怎么就做出来了。
    尤其剪枝策略部分

    
*/

class Solution {

private:
std::string s;
std::vector<std::string> combs;

std::vector<std::string> pathv;

auto isQualified(std::string str){
    if(str.empty())
        return false;

    bool qualif = true;
    long long int num = std::stoi(str);
    if(str[0] == '0' && str.size()>1)
        qualif = false;
    if(num>255){
        qualif = false;
    }


    return qualif;
}

void backtrack(int startIndex){

    if(pathv.size() > 4) return;
    if(startIndex == s.size() && pathv.size() == 4){
        std::string path;
        for(auto p:pathv){
            path += p;
            path += '.';
        }
        path.pop_back();
        combs.push_back(path);
        return;
    }
    std::string newNumberString;
    for(int i= startIndex;i<s.size();i++){
        newNumberString += s[i];

        if( newNumberString.size() >3 || !isQualified(newNumberString) ){
            continue;
        }

        pathv.push_back(newNumberString);
        backtrack(i+1);
        pathv.pop_back();
    }
    return;
}

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        this->s = s;
        backtrack(0);
        return combs;
        
    }
};

int main() {

    return 0;
}