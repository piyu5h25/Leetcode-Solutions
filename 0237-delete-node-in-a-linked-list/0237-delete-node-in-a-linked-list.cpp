/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
      node -> val = node -> next ->val;
      node -> next = node -> next -> next;  

    // ListNode* temp=node;
    // ListNode* front=node->next;
    // temp->next=nullptr;
    // free(temp);
    // node=front;
    // delete(front);



    }
};