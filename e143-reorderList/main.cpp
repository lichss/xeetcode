
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
    Solution s;
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

    n1.next = nullptr;
    n2.next = &n3;
    n3.next = nullptr;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = nullptr;



    printList(&n1);
    s.reorderList(&n1);
    printList(&n1);


    return 0;
}

#endif