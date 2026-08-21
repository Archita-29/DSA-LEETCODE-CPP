class Solution {
    long long gcd(long long a,long long b){
        while(b){
            a%=b;
            swap(a,b);
        }
        return a;
    }
    long long lcm(long long a,long long b){
        if(a==0 || b==0) return 0;
        return (a/gcd(a,b))*b;
    }
    long long countValidAmounts(long long target,const vector<int>&coins){
        int n=coins.size();
        long long totalCount=0;
        for(int mask=1;mask<(1<<n);mask++){
            long long currentLcm=1;
            int setBits=0;
            bool overflow=false;

            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    setBits++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > target) {
                        overflow = true;
                        break;
                    }
                }
            }
            if(overflow) continue;
            if(setBits%2==1){
                totalCount+=target/currentLcm;
            }else{
                totalCount-=target/currentLcm;
            }
        }
        return totalCount;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int minCoin=coins[0];
        for(int c:coins){
            minCoin=min(minCoin,c);
        }
        long long low=1;
        long long high=1LL*minCoin*k;
        long long result=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(countValidAmounts(mid,coins)>=k){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
};