#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string valid;
        bool havesined = false;
        int sign = 1;

        for (auto c : s) {
            if (c == ' ') {
                if (!havesined && valid.empty())
                    continue;
                else
                    break;
            }

            if (c == '+') {
                if (havesined || !valid.empty()) break;
                havesined = true;
                continue;
            }
            if (c == '-') {
                if (havesined || !valid.empty()) break;
                havesined = true;
                sign = -1;
                continue;
            }

            if (c >= '0' && c <= '9') {
                valid.push_back(c);
            } else {
                break;
            }
        }

        if (valid.empty()) 
            return 0;

        long long ans = 0;
        for (auto c : valid) {
            ans = ans * 10 + (c - '0');
            if (ans > INT_MAX) 
                break;
        }

        ans *= sign;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};

int main(){
    Solution s;

    string str;
    while(1){
        str.clear();
        cin >> str;
        cout << endl << s.myAtoi(str) << endl;  
    }
    return 0;
}
