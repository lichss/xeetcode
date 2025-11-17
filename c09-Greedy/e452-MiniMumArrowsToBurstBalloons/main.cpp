#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


class Solution {
public:
    
    int findMinArrowShots(std::vector<std::vector<int>>& points) {

        int totalBurst = 0;
        int arrow = 0;
        std::vector<int> bao(points.size());

        auto cmp =[](std::vector<int>& v1, std::vector<int>& v2){
            return v1[0] < v2[0];
        };

        std::sort(points.begin(),points.end(),cmp);

        while(totalBurst != points.size()){
            int min = INT_MIN,max = INT_MAX;
            for(int i=0;i<points.size();i++){
                if(bao[i]) 
                    continue;
                if(points[i][0] <= max && points[i][1] >=min){
                    min = std::max(min,points[i][0]);
                    max = std::min(max,points[i][1]);
                    bao[i] = 1;
                    totalBurst++;
                }
            }
            arrow++;
        }
        return arrow;
    }
};
    



int main(){


    return 0;
}
