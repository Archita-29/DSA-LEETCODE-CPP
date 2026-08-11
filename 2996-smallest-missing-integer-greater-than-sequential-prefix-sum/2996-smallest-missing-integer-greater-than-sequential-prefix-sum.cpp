class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int seqSum=nums[0];
        for(int j=1;j<n;j++){
            if(nums[j]==nums[j-1]+1){
                seqSum+=nums[j];
            }
            else{
                break;
            }
        }
        sort(nums.begin(),nums.end());
        for(int x:nums){
            if(x==seqSum){
                seqSum++;
            }
        }
        return seqSum;
    }
};