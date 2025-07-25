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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tailA, *tailB, *ptrA, *ptrB;
        int lenA = 1, lenB = 1;
        tailA = headA;
        tailB = headB;
        ptrA = headA;
        ptrB = headB;
        while(tailA->next!=NULL){
            tailA = tailA->next;
            lenA++;
        }
        while(tailB ->next != NULL){
            tailB = tailB->next;
            lenB++;
        }
        if(tailA!=tailB){
            return NULL;
        }

        int diff = 0;
        if(lenA>=lenB){
            diff = lenA-lenB;
            while(diff--){
                ptrA = ptrA->next;
            }
        }
        else{
            diff = lenB-lenA;
            while(diff--){
                ptrB = ptrB ->next;
            }
        }
        while(ptrA!=ptrB){
            ptrA= ptrA->next;
            ptrB = ptrB->next;
        }
        return ptrA;
    }
};