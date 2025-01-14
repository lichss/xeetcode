#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node =list1;
        for(int i =0;i!=a-1;i++){
            node = node->next;
        }
        ListNode* startnode = node;
        for(int i=a-1;i!=b;i++){
            node = node->next;
        }
        ListNode* endnode = node;
        
        startnode->next = list2;
        for(node = list2;node->next;)
            node = node->next;
        node->next = endnode->next;
        
        return list1;
    }
};


int main(){


    auto printl = [](ListNode* node){
        while(node){
            std::cout << node->val <<"-> ";
        }
        std::cout<<"\n";
    };

    ListNode n1;
    n1.val = 1;
    ListNode n2;
    n1.val = 2;
    ListNode n3;
    n1.val = 3;
    ListNode n4;
    n1.val = 4;
    ListNode n5;
    n1.val = 5;
    ListNode n6;
    n1.val = 6;
    ListNode n7;
    n1.val = 7;



    return 0;
}