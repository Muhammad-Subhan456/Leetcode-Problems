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
        vector<int>store;
        while(temp->next!= NULL){
            int ele = gcd(temp->val,temp->next->val);
            ListNode* node = new ListNode(ele);
            node->next = temp->next;
            temp->next = node;
            temp = temp->next->next;
        }
        return head;
    }
};