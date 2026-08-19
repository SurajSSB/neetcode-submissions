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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        auto node1 = list1;
        auto node2 = list2;
        ListNode* mergedL = nullptr;
        if (node1 == nullptr)
            return node2;
        if(node2 == nullptr)
            return node1;

        if(node1->val < node2->val)
        {
            mergedL = node1;
            node1 = node1->next;
        }
        else
        {
            mergedL = node2;
            node2 = node2->next;
        }
        auto mergedLNext = mergedL;
        cout<< mergedL->val << "\n";
        while (node1 != nullptr && node2 != nullptr)
        {
            cout<< "node1->val = "<< node1->val << ", node2->val = " <<node2->val <<"\n";            
            if(node1->val < node2->val)
            {
                mergedLNext->next =  node1;
                node1 = node1->next;
            }
            else
            {
                mergedLNext->next =  node2;
                node2 = node2->next;
            }
            mergedLNext = mergedLNext->next;
            cout<< mergedLNext->val << ",";
        }

        if(node1 == nullptr)
        {   
            cout<< "node1 == nullptr";
            mergedLNext->next = node2;
        }
        if(node2 == nullptr)
        {
            cout<< "node2 == nullptr";
            mergedLNext->next = node1;
        }

        return mergedL;
    }
};
