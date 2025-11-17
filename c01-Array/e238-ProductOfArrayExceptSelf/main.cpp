#include <iostream>
#include <vector>
#include <vector>


/*
*   没写 抄了
*/
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> left(n);
        std::vector<int> right(n);
        std::vector<int> prod(n);

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = nums[i - 1] * left[i - 1];
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = nums[i + 1] * right[i + 1];
        }

        for (int i = 0; i < n; i++) {
            prod[i] = left[i] * right[i];
        }

        return prod;
    }
};
int main(){


    return 0;
}
