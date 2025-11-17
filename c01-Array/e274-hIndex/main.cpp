#include <vector>



/*通过了，但是显然有更好的方法*/
/*先虎一手*/
#include <algorithm>
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        /*奥义*/
        std::sort(citations.begin(),citations.end());
        int n = citations.size();

        if(citations[n-1] == 0)
            return 0;
        for(int i=0; n > citations[i];){
            n--;i++;      
        }
        return n;

    }
};
int main(){


    return 0;
}