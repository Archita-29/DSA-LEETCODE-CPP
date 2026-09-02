class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddVal=-1;
        for(int num:nums1){
            if(num%2!=0){
                oddVal=num;
                break;
            }
        }
        if(oddVal==-1){
            return true;
        }
        return true;
    }
};