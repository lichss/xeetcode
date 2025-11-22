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

/**
 * reply in 2025-11-21
 * 可能没有暑期实习，但你还是可以做一点你擅长的事情
 */

using namespace std;

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();

        unordered_map<char,int> hash;
        int left=0,righ = 1;
        int max = 1;
        hash[s[0]] = 1;

        while(righ < s.size()){
            if(hash[s[righ]] == 0){
                hash[s[righ]]++;
                righ++;
                max = std::max(righ - left,max);
            }else{
                while(s[righ] != s[left]){
                    hash[s[left]] = 0;
                    left++;
                }
                hash[s[left]] = 0;
                left++;
            }
        }        
        return max;
    }
};



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