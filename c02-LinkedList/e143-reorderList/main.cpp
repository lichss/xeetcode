
#include <iostream>
/*
    hint:
        1. See also middleList. reverseList
        2. try creat a vector to put listnote in, so can random access elements. 
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include <stack>
#include <vector>

/*天下武功，此乃线性表法*/
class Solution_v{
public:
    void reorderList(ListNode* head){
        std::vector<ListNode*> v;
        ListNode* node = head;

        while(node){
            v.push_back(node);
            node = node->next;
        }
        int n = v.size();
        if(n<2)
            return;
        n--;    //减一个是因为size()返回的是元素数量，之后n要用作下标访问

        int i=0;
        ListNode* origin_next;
        while(n-i > i){
            origin_next = v[i]->next;
            v[i]->next = v[n-i];
            v[n-i]->next = origin_next;
            i++;
        }
        (n-i)>(i) ? v[n-i]->next=nullptr:v[i]->next=nullptr;

        return;
    }



};

/*这是初见这题的思路。比较不好*/
class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* node = head;
        int lenth=0;
        int mid;
        while(node){    /*自然数量*/
            lenth++;
            node = node->next;
            // std::cout<<"lenth:"<<lenth<<"\n";
        }
        if(lenth < 3){
            return;
        }
        else if(lenth == 3){
            ListNode* secd = head->next;
            ListNode* thrd = secd->next;

            head->next = thrd;
            thrd->next = secd;
            secd->next = nullptr;

            return;
        }
        mid = (lenth+1)/2;      /*这里仔细考虑一些*/
        node = head;
        while(mid--){
            node = node->next;
            // std::cout<<"mid:"<<mid<<"\n";
        }
        std::stack<ListNode*> st;
        while(node){
            st.push(node);
            node = node->next;
        }
        node = head;

        ListNode* nnext;
        while(!st.empty() && node){
            nnext = node->next;
            node->next = st.top();
            st.pop();
            node->next->next = nnext;
            node = nnext;
        }
        if(st.empty()){
            node->next = nullptr;
        }
        else{
            node->next = st.top();
            node->next->next = nullptr;
        }
        return ;
        
    }
};

#if 1

int printList(ListNode* head){

    ListNode* node = head;
    int cn = 10;
    while(node && --cn){
        std::cout<<node->val<<" -> ";
        node =node->next;
    }
    std::cout<<"\n";
    return 0;
}

int main(){
    // Solution s;
    Solution_v s;
    ListNode n1;
    n1.val = 1;
    ListNode n2;
    n2.val = 2;
    ListNode n3;
    n3.val = 3;
    ListNode n4;
    n4.val = 4;
    ListNode n5;
    n5.val = 5;
    ListNode n6;
    n6.val = 6;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = nullptr;
    n4.next = &n5;
    n5.next = nullptr;
    n6.next = nullptr;

    std::vector<int> v;
    v.push_back(1);
    // std::cout<<"v.size:"<<v.size()<<"\n";



    printList(&n1);
    s.reorderList(&n1);
    printList(&n1);


    return 0;
}

#endif