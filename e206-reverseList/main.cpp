#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;

        ListNode* node = head;        
        ListNode* tonext = head;
        ListNode* prev = nullptr;

        while (node)
        {
            tonext = node->next;
            node->next = prev;
            prev = node;
            node = tonext;
            /* code */
        }
        // head->next = nullptr;

        return prev;
    }
};