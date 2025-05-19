#include <iostream>
#include <vector>
#include <algorithm>

/*  好简单一道题 
    康复训练
    
*/

class Solution {
public:
    int addRungs(std::vector<int>& rungs, int dist) {
        int curr=0;
        int addCount = 0;        
        
        for(int i=0;i<rungs.size();){
            if(curr + dist < rungs[i]){ /*够不到*/
                int gap = rungs[i] - curr;
                int times = (gap - 1) / dist;;
                addCount += times;
                curr += dist * times;
            }else{             /*够得到*/
                curr = rungs[i];
                i++;
            }
        }
        return addCount;
    }
};


int main(){


    return 0;
}
