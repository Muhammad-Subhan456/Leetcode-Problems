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
    int pairSum(ListNode* head) {
    int sum = INT_MIN;
    ListNode* fast=head;
        ListNode* slow=head;
        while(fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        ListNode* prev = slow;
        slow->next = NULL;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        ListNode* head1 = head;
        ListNode* head2 = prev;
        while(head1->next){
            sum = max(sum,head1->val+head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }
    return sum;
    }
};