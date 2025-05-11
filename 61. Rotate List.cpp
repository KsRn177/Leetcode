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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr)
        return head;

        if ( head -> next == nullptr)
        return head;

        int size = 0;

        ListNode* temp = head;
        while(temp != nullptr )
        {
            size++;
            temp = temp -> next;  
        }

       

        for ( int i = 0; i < (k%size); i++)
        {
             ListNode* first = head;
            ListNode* last;
             ListNode* oneBlast;
            
            while ( head -> next -> next != nullptr)
            {
                head = head -> next;
            }
            
            oneBlast = head;
            last = head -> next;


            last -> next = first;
            oneBlast -> next = nullptr;
            head = last;
        }
        return head;
        
    }
};
