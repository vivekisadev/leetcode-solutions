class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {-1, -1};
        if (!head || !head->next || !head->next->next) return res;

        int firstCPI = -1;
        int prevCPI = -1;
        int currIndex = 1;
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;

            bool isLocalMax = (curr->val > prev->val && curr->val > nextNode->val);
            bool isLocalMin = (curr->val < prev->val && curr->val < nextNode->val);

            if (isLocalMax || isLocalMin) {
                if (prevCPI == -1) {
                    firstCPI = currIndex;
                    prevCPI = currIndex;
                } else {
                    minDist = min(minDist, currIndex - prevCPI);
                    prevCPI = currIndex;
                }
            }

            prev = curr;
            curr = curr->next;
            currIndex++;
        }

        if (firstCPI != -1 && minDist != INT_MAX) {
            res[0] = minDist;
            res[1] = prevCPI - firstCPI;
        }

        return res;
    }
};