#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {

        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int content=0;
        for(int i=0,j=0;i<g.size() && j<s.size();j++){
            if(s[j]>=g[i]){
                content++;
                i++;
            }
        }
        return content;
    }
};





int main(){


    return 0;
}
