#include <iostream>
#include <vector>
#include <algorithm>


using namespace  std;

class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    
    std::vector<std::vector<int>> merged;
    auto cmp = [](std::vector<int>& v1,std::vector<int>& v2){
        return v1[0] < v2[0];
    };
    std::sort(intervals.begin(),intervals.end(),cmp);
    int left,right;
    left = intervals[0][0];
    right = intervals[0][1];
    for(int i=0;i<intervals.size();i++){
        if(right >= intervals[0][0])
            right = std::max(right,intervals[0][1]);
        else{
            merged.push_back(std::vector<int> {left,right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    return merged;

    }
};


int main(){


    return 0;
}
