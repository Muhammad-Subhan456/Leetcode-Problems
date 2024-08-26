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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    ListNode* temp=head;
    set<int>s;
    for(auto ele:nums)
        s.insert(ele);
    while(temp!=NULL){
        if(s.find(temp->val)==s.end()){
            res->next = new ListNode(temp->val);
            res=res->next;
        }
    temp=temp->next;
    }
    return dummy->next;
    }
};