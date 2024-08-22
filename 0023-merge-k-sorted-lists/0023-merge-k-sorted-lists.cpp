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
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Dummy = new ListNode(-1); 
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* ptr3 = Dummy;
        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                ptr3->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                ptr3->next = ptr2;
                ptr2=ptr2->next;
            }
            ptr3 = ptr3->next;
        }
         if(ptr1)
            ptr3->next = ptr1;
        else
            ptr3->next=ptr2;
        return Dummy->next;}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        while(lists.size()>1){
            ListNode* mergedHead = mergeTwoLists(lists[0],lists[1]);
            lists.push_back(mergedHead);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
    return lists[0];
    }
};