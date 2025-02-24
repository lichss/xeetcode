#include <vector>
#include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

class Solution {
private:
    std::vector<std::vector<int>> combs = {};
    std::vector<int> path;

    void backtrack(int n,int k,int startIdx){
        if(path.size() == k){
            combs.push_back(path);
            
            return;
        }
        for(int i = startIdx;i<=n;i++){
            path.push_back(i);
            backtrack(n,k,i+1);
            path.pop_back();
        }
        return;
    }
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        backtrack(n,k,1);
        return combs;
    }
};



int main() {
    // for(;;)
    auto print = [](std::vector<std::vector<int>> vv){
        for(auto v:vv){
            for(auto e:v)
                std::cout<<e<<"-";
            std::cout<<"\n";
        }
    };
    Solution s;
    auto vv = s.combine(9,3);
    print(vv);
    return 0;
}