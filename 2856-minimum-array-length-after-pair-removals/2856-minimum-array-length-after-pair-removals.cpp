class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n/2;
        int c=0;
        while(i<n/2 && j<n){
            if(nums[i]<nums[j]){
                i+=1;
                j+=1;
                c+=2;
            }
            else{
                j+=1;
            }
        }
        return n-c;
    }
};