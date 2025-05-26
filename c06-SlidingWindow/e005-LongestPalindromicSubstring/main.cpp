#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int left;
        int rigt;
        int size = s.size();
        int maxLengh = 1,begin = 0;

        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){ 
                left = i-1;
                rigt = i;
            }else{
                left = rigt = i;
            }
            while(left != -1 && rigt != size){
                left --;
                rigt ++;
                /*diaomao 不想做了*/
                if(s[left] == s[rigt]){
                    if(maxLengh < rigt-left){
                        maxLengh = rigt-left;
                        begin = left;
                    }
                }else{
                    maxLengh = 1;
                    break;
                }
            }
        }

        std::string r = s.substr(left,maxLengh); 
        return r;
    }
};



int main(){

    std::cout << "returned\n";

    return 0; 
}