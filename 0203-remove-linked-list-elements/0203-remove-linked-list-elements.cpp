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
    ListNode* removeElements(ListNode* head, int val) {
       ListNode* dummy = new ListNode(-1);
       ListNode* res = dummy;
       ListNode* temp = head;
       while(temp){
        if(temp->val != val){

            res->next = new ListNode(temp->val);
            res = res->next;
        }
       temp = temp->next;
       }
    return dummy->next;
    }
};