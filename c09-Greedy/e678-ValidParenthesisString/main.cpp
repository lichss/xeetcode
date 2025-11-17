#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
public:
    bool checkValidString(std::string s) {
        int stack = 0;
        int k=0;
        int i=0;
        for(int i=0;i<s.size();i++);{
            if(s[i] == '('){
                stack++;
            }else if(s[i] == ')'){
                stack--;
            }else{
                k++;
            }
            if()
        }

    }
};



int main(){


    return 0;
}
