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

    ListNode* mergesort(ListNode* head, ListNode* tail,int left,int right)
    {
           if (left >= right) {
            head->next = nullptr; // Ensure the list ends properly
            return head;
        }
        
         int mid = (left + right) / 2;
        ListNode* MID = head;
        int T_left = left;
        
        while (T_left < mid) {
            MID = MID->next;
            T_left++;
        }

        ListNode* next_part = MID->next;
        ListNode* LEFT = mergesort(head, MID, left, mid);
        ListNode* RIGHT = mergesort(next_part, tail, mid + 1, right);

        ListNode dummy(0);
        ListNode* ans = &dummy; 

        

        while (LEFT && RIGHT) 
        {
            if (LEFT->val <= RIGHT->val) 
            {
                ans->next = LEFT;
                LEFT = LEFT->next;
            } 
            else 
            {
                ans->next = RIGHT;
                RIGHT = RIGHT->next;
            }
            ans = ans->next;
        }
        
        // Attach remaining elements
        ans->next = LEFT ? LEFT : RIGHT;
        
        return dummy.next;

    }
    ListNode* sortList(ListNode* head) 
    {

        if (!head || !head->next) return head;
        
        int size = 0;
        ListNode* temp = head;
        ListNode* tail = head;
        while (temp) {
            tail = temp;
            temp = temp->next;
            size++;
        }
        
        return mergesort(head, tail, 0, size - 1);
    }
};
