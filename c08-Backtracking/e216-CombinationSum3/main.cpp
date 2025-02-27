#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include <numeric>
// #include "../leetcodeStruct/treenode"

class Solution {
private:
    std::vector<std::vector<int>> combs;
    std::vector<int> path;

    void backtrack(int k,int n,int start){
        if(path.size() == k){
            if(std::accumulate(path.begin(),path.end(),0) == n)
                combs.push_back(path);
            return;
        }

        for(int i = start;i<10;i++){
            path.push_back(i);
            backtrack(k,n,i+1);
            path.pop_back();

        }
        return;
    }
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,1);
        return combs;
    }
};

int main() {

    return 0;
}