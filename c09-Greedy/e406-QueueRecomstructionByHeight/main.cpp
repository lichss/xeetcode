#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {

        std::sort(people.begin(),people.end(),cmp);
        std::vector< vector<int>> ret;
        for(int i=0;i<people.size();i++){
            ret.insert(ret.begin() + people[i][1],people[i]);
        }
        
        // ret.shrink_to_fit();
        return ret;
    }
};





int main(){


    return 0;
}
