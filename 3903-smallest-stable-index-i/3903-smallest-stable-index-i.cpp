class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int prefix_max=nums[0];
            for(int j=0;j<=i;j++){
                prefix_max=max(prefix_max,nums[j]);
            }
            int suffix_min=nums[i];
            for(int j=i;j<n;j++){
                suffix_min=min(suffix_min,nums[j]);
            }
            if(prefix_max-suffix_min<=k){
                return i;
            }
        }
        return -1;
    }
};