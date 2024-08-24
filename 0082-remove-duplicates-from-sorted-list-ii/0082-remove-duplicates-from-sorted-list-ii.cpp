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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>s;
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        ListNode* temp = head;
        while(temp){
            s[temp->val]++;
            temp = temp->next;
        }
        for(auto pair : s){
            if(pair.second == 1){
            res->next = new ListNode(pair.first);
            res = res->next;
            }
        }
        return dummy->next;

    }
};