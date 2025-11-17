#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {

        int dollar5 = 0;
        int dollar10 = 0;

        for(auto b:bills){
            int change = b - 5;
            if(change == 15){
                if(dollar10){
                    dollar10--;
                    dollar5+=2;
                }
                dollar5-=3;

            }else if(change == 5){
                dollar5--;
                dollar10++;
            }else
                dollar5++;
            if(dollar5<0)
                return false;
                    
        }
        return true;
    }
};



int main(){


    return 0;
}
