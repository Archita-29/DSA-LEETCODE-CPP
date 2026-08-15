class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int resultXor=0;
        bool allZeros=true;

        for(int &x:nums){
            resultXor ^= x;
            if(x!=0){
                allZeros=false;
            }
        }
        if(allZeros){
            return 0;
        }
        return (resultXor==0)?n-1:n;
    }
};