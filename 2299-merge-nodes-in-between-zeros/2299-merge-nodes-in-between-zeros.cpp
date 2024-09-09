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
    ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    ListNode* temp = head;
    vector<int>arr;
    while(temp->next!=NULL){
        temp = temp->next;
        int ele=0;
        while(temp->val!=0){
            ele+=temp->val;
            temp = temp->next;
        }
        arr.push_back(ele);
    }
    for(auto ele : arr){

       res->next = new ListNode(ele);
       res=res->next;
    }
    return dummy->next;
    }

};