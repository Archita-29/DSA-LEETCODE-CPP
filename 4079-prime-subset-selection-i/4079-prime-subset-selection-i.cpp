class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool>isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<int>primes;
        vector<long long>pref(1,0);
        for(int i=2;i<=n;i++){
            if(isPrime[i]){
                primes.push_back(i);
                pref.push_back(pref.back()+i);
            }
        }
        int k=upper_bound(pref.begin(),pref.end(),s)-pref.begin()-1;
        return vector<int>(primes.begin(),primes.begin()+k);
    }
};