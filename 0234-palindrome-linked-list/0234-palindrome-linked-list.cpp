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
    private:
    ListNode * reversell(ListNode*head){
        if(head == NULL || head->next ==NULL){
            return head;
        }
        ListNode* newhead= reversell(head->next);
        ListNode* front = head->next;
        front->next=head;
        head ->next = nullptr;
        return newhead;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        }
        ListNode* newhead = reversell(slow->next);
        ListNode* first = head;
        ListNode* scnd = newhead;
        while(scnd!= NULL){
            if(first->val !=scnd->val){
            reversell(newhead);
            return false;
            }
        first = first->next;
        scnd = scnd->next;
        }
        reversell(newhead);
        return true;
    }
};