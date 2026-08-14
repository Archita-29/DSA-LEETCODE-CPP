class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long long sum=0;
        while(x>0){
            int rem=x%10;
            sum=sum*10+rem;
            x=x/10;
        }
        if(sum==temp){
            return true;
        }
        return false;
    }
};