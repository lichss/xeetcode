#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long a=0;
        while(x){
           a *= 10;
           a += x%10;
           x /= 10; 
        }
        if(a > INT_MAX || a < INT_MIN)
            return 0;
        return (int)a;
    }
};


int main(){
    
    Solution s;
    // cout << s.reverse(1023);
    int t;
    while(1){
        cin >> t;
        cout << endl;
        cout << s.reverse(t) << endl;
    }
    return 0;
}
