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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;
        while(b--){
            temp1 = temp1->next;
        }
        ListNode* temp2 = list2;
        while(temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp1->next;
        temp1->next = NULL;
        ListNode* temp3 = list1;
        while(--a)
            temp3 = temp3->next;
        temp3->next = list2;
        return list1;
    }
};