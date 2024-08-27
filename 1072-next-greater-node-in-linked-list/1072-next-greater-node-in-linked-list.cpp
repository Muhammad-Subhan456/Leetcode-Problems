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
    vector<int> nextLargerNodes(ListNode* head) {
    vector<int>ans;
    ListNode* temp = head;
    int length=0;
    while(temp)
    temp = temp->next,length++;

    for(int i=1; i < length;++i){
    ListNode* nextnode = head->next;
    int d=-1;

        while(nextnode){
            if(head->val < nextnode->val){
                d=1;
                ans.push_back(nextnode->val);
                break;
            }
        nextnode=nextnode->next;
        }
        if(d==-1)
        ans.push_back(0);
        head = head->next;
    }
    ans.push_back(0);
    return ans;
    }
};