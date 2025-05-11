class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        bool isfalse = true; 
        for ( int i = 0; i < 10001; i++)
        {
            if ( head  == nullptr)
            {
                isfalse = false;
                break;
            }
            head = head -> next;
            
        }
        return isfalse;
    }
};
