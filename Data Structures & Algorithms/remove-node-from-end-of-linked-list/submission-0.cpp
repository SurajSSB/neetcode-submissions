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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        auto revList = reverse(head);
        ListNode* prevNode = nullptr;
        ListNode* nodeToRemove = revList; 
        for(int i = 1; i< n; ++i )
        {
            prevNode = nodeToRemove;
            nodeToRemove = nodeToRemove->next;
        }

        if(nodeToRemove && prevNode)
        {
            prevNode->next = nodeToRemove->next;
        }
        
        if(!prevNode)
        {
           // if(revList->next)
                revList = revList->next;
           //return nullptr;   
        }
        auto res = reverse(revList);

        return res;
        
    }
    ListNode* reverse(ListNode* head)
    {
        auto cur = head;
        ListNode* prev = nullptr;
        while(cur)
        {
            auto temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};
