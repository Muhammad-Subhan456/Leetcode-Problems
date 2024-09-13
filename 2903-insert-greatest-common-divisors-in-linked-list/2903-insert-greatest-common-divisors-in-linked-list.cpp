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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = head;
        while(temp->next!= NULL){
            ListNode* node = new ListNode(gcd(temp->val,temp->next->val));
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        return head;
    }
};