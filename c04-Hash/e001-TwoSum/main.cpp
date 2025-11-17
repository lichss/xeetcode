#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int i=0;
        for(i=0;i<nums.size();i++){
            if(map.find(target - nums[i]) != map.end() && map[target - nums[i]] != i)
                break;
            map[nums[i]] = i;
        } 
        return {i, map[target - nums[i]]};
    }
};

int main(){


    return 0;
}
