#include <vector>
// #include <iostream>
#include <queue>
#include "../../leetcodeStruct/treenode.h"
#include <algorithm>
// #include "../leetcodeStruct/treenode"

#if 0
/* 我觉得复杂度很高的方法。力扣上居然是100% */
class Solution {
private:
    std::vector<std::vector<int>> combs;
    std::vector<int> path;

    void backtrack(std::vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if( std::find(path.begin(),path.end(),nums[i]) == path.end() ){ /*暂时想不到很好的方法*/
                path.push_back(nums[i]);
                backtrack(nums);
                if(path.size() == nums.size())
                    combs.push_back(path);

                path.pop_back();

            }
        }
        return;
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        backtrack(nums);
        return combs;

    }
};
#endif


/*这个明显要好*/
class Solution {
    private:
        std::vector<std::vector<int>> combs;
        std::vector<int> path;
        std::vector<bool> used;

        void backtrack(std::vector<int>& nums){

            //used.reserve( nums.size());
            for(int i=0;i<nums.size();i++){
                if(!used[i]){
                    path.push_back(nums[i]);
                    used[i] = true;
                    if(path.size() == nums.size())
                        combs.push_back(path);
                    else
                        backtrack(nums);
                    path.pop_back();
                    used[i] = false;
                }
            }

            return;
        }
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums) {
            used.resize(nums.size(),false);
            for (auto&& e : used) {
                e = false; // 使用通用引用修改
            }
            
            backtrack(nums);
            return combs;
    
        }
    };
int main() {

    return 0;
}