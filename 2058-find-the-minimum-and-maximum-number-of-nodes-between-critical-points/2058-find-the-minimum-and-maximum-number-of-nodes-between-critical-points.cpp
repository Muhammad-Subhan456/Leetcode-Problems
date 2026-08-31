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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        if(len <= 2) return {-1,-1};

        int i = 2;
        ListNode* prev = head;
        temp = head->next;
        ListNode* nex = temp->next;
        int mini = INT_MAX, maxi = INT_MIN;
        int sec = INT_MAX;
        int a = -1, b = -1;
        bool flag = true;
        while(nex){
            int x = prev->val, y = temp->val, z = nex->val;
            if((y > x && y > z) || (y < x && y < z)  ){
                // maximum
                mini = min(mini,i);
                maxi = max(maxi,i);
                // minimum
                if(flag){
                    flag = false;
                    a = i;
                }
                else {
                    flag = true;
                    b = i;
                }
                if( a!= -1 && b != -1) {
                    sec = min(abs(b-a),sec);
                }


            }
            i++;
            prev = prev->next;
            temp = temp->next;
            nex = nex->next;
            

        }
        vector<int>res;
        if(a == -1 || b == -1) return {-1,-1};
        else res.push_back(sec);
        if(mini == INT_MAX || maxi == INT_MIN) return {-1,-1};
        else res.push_back(maxi-mini);
        return res;
        
    }
};