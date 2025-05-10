#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {

        std::unordered_map<char,int> hash;

        for(int i=0;i<s.size();i++){
            hash[s[i]] = i;
        }
        int keep = 0;
        std::vector<int> splitVec;
        int prevSplit = -1;
        for(int i=0;i<s.size();i++){
            keep = std::max(keep,hash[s[i]]);
            if(keep == i){
                splitVec.push_back(i-prevSplit);
                prevSplit = i;
                keep = 0;
            }

        }
        return splitVec;

    }
};

int main(){


    return 0;
}
