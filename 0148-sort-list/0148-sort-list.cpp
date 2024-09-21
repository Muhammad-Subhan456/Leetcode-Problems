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
    ListNode* sortList(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    if(!head) return nullptr;
    ListNode* temp = head;
    vector<int>ans;
    while(temp){
        ans.push_back(temp->val);
        temp = temp->next;
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i < ans.size(); ++i){
        res->next = new ListNode(ans[i]);
        res=res->next;
    }
    return dummy->next;
    }
};