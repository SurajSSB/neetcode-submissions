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
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto mid = slow;
        auto secList = slow->next;
        auto firstList = head;
        slow->next = nullptr;
        
        cout<<"mid is = " << mid->val << "\n";
        cout<<"firstList is = "; PrintList(firstList);
        cout<<"secondList is = "; PrintList(secList);

        //reverse seconfd list
        auto revSecList = reverse(secList);
        cout<<"Reversed secondList is = "; PrintList(revSecList);

        //merge
        ListNode* fNode = head;
        ListNode* sNode = revSecList;
        while(fNode && sNode)
        {
            auto ftemp = fNode->next;
            auto stemp = sNode->next;
            fNode->next = sNode;
            sNode->next = ftemp;
            fNode = ftemp;
            sNode = stemp;
            
        }
        cout<<"Output is = "; PrintList(head);

    }
    void PrintList(ListNode* head)
    {
        auto node = head;
        while(node)
        {
            cout<<node->val <<", ";
            node = node->next;
        }
         cout<<"\n";
    }
    ListNode* reverse(ListNode* head)
    {
        auto node = head; 
        ListNode* preNode = nullptr;       
        while(node)
        {            
            auto nextNode = node->next;
            node->next = preNode;
            preNode = node;
            node = nextNode;
        }
         return preNode;
    }
};
