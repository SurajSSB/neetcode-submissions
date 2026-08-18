/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = head;
        ListNode* node = nullptr;
        while(newHead != nullptr)
        {
            auto temp = newHead->next;
            newHead->next = node;            
            node = newHead;
            newHead = temp;
        }
        return node;
    }
};
