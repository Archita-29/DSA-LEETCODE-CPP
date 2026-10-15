class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            unordered_set<int>distinctElement;
            for(int j=i;j<n;j++){
                distinctElement.insert(nums[j]);
                int count=distinctElement.size();
                totalSum+=count*count;
            }
        }
        return totalSum;
    }
};