#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        
        int p1=0,p2=0;
        std::vector<int> retVec;
        while(p1!=m&&p2!=nums2.size()){
            if(nums1[p1]<=nums2[p2])
                retVec.push_back(nums1[p1++]);
            else
                retVec.push_back( nums2[p2++]);
            
        }
        while(p1!=m)
            retVec.push_back(nums1[p1++]);       
        while(p2!=nums2.size())
            retVec.push_back(nums2[p2++]);
        
        nums1 = retVec;
        return;
    }
};


int main(){


    return 0;
}
