#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>



/* 
    人生海海 山山而川
    有没有暑期实习,我只想做点自己擅长的事
*/
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char,int> map;
        int curr = 0, ans=0;
        int tail = 0;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i]) != map.end()){
                int chop = map[s[i]];
                ans = std::max(ans,curr);
                while(tail <= chop){
                    map.erase(s[tail]);
                    tail++;
                    curr--;
                }
            }
            map[s[i]] = i;
            curr++;
            
        }

        return std::max(ans,curr);
    }
};


int main(){

    std::cout << "returned\n";

    return 0; 
}