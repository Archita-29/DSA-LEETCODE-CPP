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
        if(!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        int firstIdx=-1;
        int prevIdx=-1;
        int minD=INT_MAX;

        ListNode* prev=head;
        ListNode* curr=head->next;
        int idx=1;
        while(curr->next){
            bool isMaxima=(curr->val > prev->val) && (curr->val > curr->next->val);
            bool isMinima=(curr->val < prev->val) && (curr->val<curr->next->val);
            if(isMaxima || isMinima){
                if(firstIdx==-1){
                    firstIdx=idx;
                }else{
                    minD=min(minD,idx-prevIdx);
                }
                prevIdx=idx;
            }
            prev=curr;
            curr=curr->next;
            idx++;
        }
        if(firstIdx==-1 || prevIdx==firstIdx){
            return {-1,-1};
        }
        return {minD,prevIdx-firstIdx};
    }
};