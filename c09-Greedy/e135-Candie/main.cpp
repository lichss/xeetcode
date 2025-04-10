#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
/*
    首次ac的困难题目. 值得纪念
    另外比起标准解法,至少在空间复杂度上胜出了.
    但是整体透漏出一种修修补补笨拙感
*/
class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int giveyou=1;
        int totalLoss = 0;
        int prevRating = INT_MAX;  //include climits
        int localPeak = 0;
        int morepay = 0;
        int peakPay = 0;
        for(int i=0;i<ratings.size();i++){
            if(ratings[i] < prevRating){
                // giveyou = std::max(1,giveyou-1);
                if(giveyou == 1 && i!=0){   /*群体补偿*/
                    totalLoss += i - localPeak;
                    morepay ++;
                    if(peakPay > morepay+1){
                        totalLoss--;    /*补多了.收回一块*/
                    }
                }
                
                giveyou = 1;
            }else if(ratings[i] > prevRating){
                giveyou++;
                localPeak = i;
                morepay = 0;
                peakPay = giveyou;
            }else{
                giveyou = 1;
                localPeak = i;
                morepay = 0;
                peakPay = giveyou;
            }

            totalLoss += giveyou;

            prevRating = ratings[i];
        }

        return totalLoss;

    }
};




int main(){
    Solution s;
    std::vector<int> t ={1,6,10,8,7,3,2};

    std::cout<< 2;

    int a = s.candy(t);
    a-1; 
    return 0;
}
