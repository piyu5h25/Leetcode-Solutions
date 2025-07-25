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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* ans = newNode();
        int carry =0;
        ListNode* dummyhead = new ListNode(0);
        ListNode* temp = dummyhead;
        while(l1 != nullptr || l2!=nullptr || carry!=0){

            int val1 = (l1!=nullptr)? l1->val : 0;
            int val2 = (l2!=nullptr)? l2->val : 0;

            int sum = (carry + (val1 + val2));
            carry = sum /10;
            int new_digit = sum%10;

            temp->next = new ListNode(new_digit);

            temp = temp->next;
            if(l1 !=nullptr)l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        ListNode* result = dummyhead->next;
        delete(dummyhead);
        return result;
    }
};