#include <iostream>
#include <vector>
#include <stack>


class Solutiond {
public:
    void hanota(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
        
    }
};

class Solution {
public:
    
    void hanota(std::stack<int>& A, std::stack<int>& B, std::stack<int>& C) {
        auto recursion = [A,B,C](){
            

        };
    }
};

void show(std::vector<int>& A,std::vector<int>& B,std::vector<int>& C);

void recursion(int n,std::vector<int>& A,std::vector<int>& B,std::vector<int>& C){

    show(A,B,C);

    if(A.size()==2){
        B.push_back(A[1]);
        A.pop_back();
        show(A,B,C);
        C.push_back(A[0]);
        A.pop_back();
        show(A,B,C);

        C.push_back(B[0]);
        B.pop_back();
        show(A,B,C);
    }
    


}

void show(std::vector<int>& A,std::vector<int>& B,std::vector<int>& C){
    std::cout << "A -";
    for(auto e:A)
        std::cout<<e<<'-';
    std::cout<<'\n';

    std::cout << "B -";
    for(auto e:B)
        std::cout<<e<<'-';
    std::cout<<'\n';

    std::cout << "C -";
    for(auto e:C)
        std::cout<<e<<'-';
    std::cout<<'\n';
    std::cout<<'\n';

}

int main(){

    std::vector<int> A = {2,1};
    std::vector<int> B = {};
    std::vector<int> C = {};

    recursion(0,A,B,C);

    return 0;
}