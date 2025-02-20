#include <vector>
#include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

class Solution {
private:
    std::vector<std::vector<int>> combs = {};

    void backt(std::vector<int> vec, std::vector<int> subCombs,int k){
        
        if(k==1){
            for(auto e:vec){
                subCombs.push_back(e);
                combs.push_back(subCombs);
                subCombs.pop_back();
            }
            return;
        }
        while(!vec.empty()){
            subCombs.push_back(vec.back());
            vec.pop_back();
            backt(vec,subCombs,k-1);
            subCombs.pop_back();            
        }
        return;

    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> vec;
        for(int i=0;i<n;i++){
            vec.push_back(i+1);
        }
        if(k==1){
            for(auto e:vec){
                std::vector<int> single={};
                single.push_back(e);
                combs.push_back(single);
            }
            return combs;
        }
        std::vector<int> subCombs = {};
        while(!vec.empty()){
            subCombs.clear();
            subCombs.push_back(vec.back());
            vec.pop_back();
            backt(vec,subCombs,k-1);
        }
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