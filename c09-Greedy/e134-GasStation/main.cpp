#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int startStation=0;
        int total=0;
        int remain =0;
        int firstFailStation = -1;

        for(int i=0;i<gas.size()-1;i++){
            remain += (gas[i]-cost[i]);
            total += (gas[i]-cost[i]);
            if(remain<0){ 
                startStation = i+1;
                remain = 0;               
            }

        }
        if(total < 0)
            return -1;
        return startStation;
            
    }
    
    
};




int main(){


    return 0;
}
