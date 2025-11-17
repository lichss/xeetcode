#include <iostream>
#include <vector>
#include <algorithm>


/*好像有更快的方法。感觉我这个思路有点呆板*/
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n =prices.size();
        if(n == 1)
            return 0;
        int buyday=0,sellday=1;
        int buyday_sub=0;
        for(int i=0;i!=n;i++){
            if(prices[i] - prices[buyday_sub]>prices[sellday] - prices[buyday]){
                sellday = i;
                buyday = buyday_sub;
            }
            if(prices[i]<prices[buyday] && prices[i]<prices[buyday_sub]){
                buyday_sub = i;
            }
            
        }
        if(prices[sellday]-prices[buyday] > 0)
            return prices[sellday]-prices[buyday];
        else
            return 0;

    }
};

int main(int argc, const char** argv) {



    return 0;
}