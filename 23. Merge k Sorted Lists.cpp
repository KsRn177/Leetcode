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
    ListNode* sort(vector <ListNode*>& list,int left, int right)
    {

        if ( left == right)
        return list[left];

        int mid = (left+right)/2;
        ListNode* T1 =sort(list,left,mid);
        ListNode* T2 =sort(list,mid+1,right);

        ListNode dummy(0);
        ListNode* merg = &dummy;


        while ( T1 != nullptr || T2 != nullptr)
        {
            if ( T1 == nullptr)
            {
                merg -> next = T2;
                T2 = T2 -> next;
            }
            else if ( T2 == nullptr)
            {
                merg -> next = T1;
                T1 = T1 -> next;
            }
            else if (T1 -> val <= T2 -> val)
            {
                merg -> next = T1;
                T1 = T1 -> next;
            }
            else if (T1 -> val > T2 -> val)
            {
                merg -> next = T2;
                T2 = T2 -> next;
            } 
            merg = merg -> next; 
       
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if ( lists.size() == 0)
            return nullptr;

        return sort(lists,0,lists.size()-1);
    }
};
