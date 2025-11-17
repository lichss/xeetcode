#include <iostream>
#include <vector>

#include <queue>
/*diao方法 奇数可行 偶数分情况。*/
#if 1
class Solution {
public: 
    void rotate(std::vector<int>& nums, int k) {
    
        int lenth = nums.size();
        if(lenth<2)
            return;
        k = k%lenth;
        if(!k)
            return;    
        std::queue<int> q;

        q.push(nums[0]);
    
        int p=0;
        int n = lenth;
        while(n--){
            // std::cout<<n<<"-\n";
            // std::cout<<"p+k = "<<(p+k)%lenth<<"\n";
            q.push(nums[(p+k)%lenth]);
            nums[(p+k)%lenth] = q.front();
            q.pop();
            p+=k;
            // p = p%lenth;
        }
        return;
    }
};
#endif 

#if 0
/* 行不通。只好出此下策*/
class Solution {
public: 
    void rotate(std::vector<int>& nums, int k) {
        int lenth = nums.size();
        std::vector<int> news(lenth);
        k = k%lenth;
        for(int i=0;i<lenth;i++){
            news[(i+k)%lenth] = nums[i];
        }
        nums.assign(news.begin(),news.end());
    }
};
#endif
int main(){

    Solution s;
    std::vector<int> v = {1,2,3,4,5,6,7,8,9};
    auto print_v = [](std::vector<int> v){
        for(auto e:v){
            std::cout<<e<< " - ";
        }
        std::cout<<"\n";
    };
    // print_v(v);

    s.rotate(v,3);
    std::cout <<"v size:"<< v.size()<<"\n";
    print_v(v);

    return 0;
}