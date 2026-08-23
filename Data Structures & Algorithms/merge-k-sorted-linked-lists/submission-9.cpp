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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
     //Algo2 - minHeap
     if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            cur->next = node;
            cur = cur->next;

            node = node->next;
            if (node != nullptr) {
                minHeap.push(node);
            }
        }
        return res->next;

     
     //Algo 1 - 
        ListNode* merged = nullptr;
        if(lists.empty())
        return merged;

        merged = lists[0];
    for(int i = 1; i < lists.size(); ++i )
    {
        merged = MergeList(merged, lists[i]);
        //PrintList(merged);
    }    

    return merged;
    }

    ListNode* MergeList(ListNode* list1,ListNode* list2)
    {
        //ListNode* merged = nullptr;
        auto node1 = list1;
        auto node2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* merged = dummy;
       
       // int count =0;
        while(node1 && node2)
        {
            if(node1->val <= node2->val)
            {
                merged->next = node1;
                node1 = node1->next;
            }
            else
            {
                merged->next = node2;
                node2 = node2->next;
            }
            merged = merged->next;
            //cout<<merged->val << ", ";
            //count++;
            //if(count > 5)
              //  break;
        }

        if(node1 != nullptr)
        {
            merged->next = node1;
        }
        else
        {
            merged->next = node2;
        }
        return dummy->next;
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
};
