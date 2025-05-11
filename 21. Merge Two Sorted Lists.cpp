class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode t(0);
        ListNode *ans = &t;

        while ( list1 != nullptr && list2 != nullptr)
        {
            if ( list1 -> val > list2 -> val)
            {
                ans -> next = list2;
                list2 = list2 -> next; 
            }
            else
            {
                ans -> next = list1 ;
                list1 = list1 -> next;
            }
            ans = ans -> next;
        }

        if ( list1 != nullptr)
        {
            ans -> next = list1;
        }
        else if(list2 != nullptr)
        {
            ans -> next = list2;
        }
        return t.next;
    }
};
