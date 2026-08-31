class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int prev = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* left = head;
        ListNode* mid = head->next;

        int pos = 1;

        while (mid && mid->next) {
            ListNode* right = mid->next;

            // Check if mid is a critical point
            if ((mid->val > left->val && mid->val > right->val) ||
                (mid->val < left->val && mid->val < right->val)) {

                if (first == -1) {
                    // First critical point
                    first = pos;
                }

                if (prev != -1) {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);
                }

                prev = pos;

                // Distance from first to current (last) critical point
                maxDist = pos - first;
            }

            left = mid;
            mid = right;
            pos++;
        }

        // Need at least two critical points
        if (first == -1 || first == prev) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};