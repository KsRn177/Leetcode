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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        stack<int> s;
        ListNode dummy(0);
        dummy.next = head;

        int i = 1;
        while(head != nullptr)
        {
            if ( i >= left && i <= right)
            {
                cout << head -> val << endl;
                s.push(head -> val);
            }
            
            head = head -> next;
            i++;
        }
        head = dummy.next;
        i = 1;
        while(head != nullptr)
        {
            if ( i >= left && i <= right)
            {
                head -> val = s.top();
                s.pop();
            }
            
            head = head -> next;
            i++;
        }
        return dummy.next;
    }
};
