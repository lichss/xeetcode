#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
#include <numeric>
// #include "../leetcodeStruct/treenode"


/* 草 大彻大悟了。 刚开始怎么样想不明白 能重复的情况下*/
class Solution {

private:
    std::vector<int> candidates;
    int target;

    std::vector<std::vector<int>> combs;
    std::vector<int> path;

    void backtrack(int sindex, int sum){
        // auto sum = std::accumulate(path.begin(),path.end(),0);
        if( sum > target ){
            return ;    /*这里可以优化 当前path合计超过 上一轮就可以 continue了*/
        }
        if(sum == target){         
            combs.push_back(path);/* 我觉得这里可以优化。事实上应该可以传递一个参数作为当前path的累加和。对降低复杂是很有好处的*/
            return;
        }
        for(int i=sindex;i<candidates.size();i++){
            path.push_back(candidates[i]);
            backtrack(i,sum+candidates[i]);
            path.pop_back();
            
        }
        return ;
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->target = target;
        std::sort(this->candidates.begin(),this->candidates.end());
        

        backtrack(0,0);

        return combs;
    }
};

int main() {

    return 0;
}