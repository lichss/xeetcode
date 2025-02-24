#include <iostream>

#if 0
/*这个方法有点没技术含量了。不过就是简单好想*/
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(!nums.size())
            return 0;
        std::vector<int> nodu;
        nodu.reserve(nums.size());
        
        nodu.push_back(nums[0]);
        for(auto& e:nums)
            if(e!=nodu.back())
                nodu.push_back(e);                
            
        int i=0;
        for(auto& e:nodu)
            nums[i++] = e;
        
        return nodu.size();
    }
};
#endif
#if 1
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return n;
        
        int fast = 0,slow = 0;
        while(fast < n){
            if (nums[slow] == nums[fast])
                fast++;
            else 
                nums[++slow] = nums[fast++];        

        }
        return ++slow;
    }
};
#endif


int main(){

    std::vector<int> nums;
    nums.reserve(6);
    std::cout<<nums.size()<<"\n";

    return 0;
}