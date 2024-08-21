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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    ListNode* moveHeadByK(ListNode* head, int k){
        ListNode*ptr = head;
        while(k--)
            ptr=ptr->next;    
        return ptr;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* ptr1=headA;
    ListNode* ptr2=headB;
    int LL1 = getLength(headA);
    int LL2 = getLength(headB);
    if(LL1 > LL2){
        int k = LL1-LL2;
        ptr1 = moveHeadByK(headA,k);
        ptr2 = headB;
    }
    else{
        int k = LL2-LL1;
        ptr1 = headA;
        ptr2 = moveHeadByK(headB,k);
    }
    while(ptr1){
        if(ptr1==ptr2)
            return ptr1;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
    }
};