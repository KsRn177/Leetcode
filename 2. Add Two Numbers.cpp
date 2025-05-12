class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* l3 = &dummy;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
        }

        if (carry > 0) {
            l3->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
