#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> mats(numRows);
        int col=0;int row=0;
        bool down = true;
        for(auto &c:s){
            if(down && row<=numRows){
                mats[col][row++] = c;
                if(row==numRows) down = false;
            }else{
                mats[++col][--row] = c;
                if(row == 0) down = true;
            }
        }

    }
};




int main(){


    return 0;
}
