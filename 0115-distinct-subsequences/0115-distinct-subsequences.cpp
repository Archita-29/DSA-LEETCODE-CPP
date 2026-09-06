class Solution {
public:
    int numDistinct(string s, string t) {
        int sourceLen=s.length();
        int targetLen=t.length();
        if(targetLen>sourceLen){
            return 0;
        }
        vector<unsigned long long>matchCounts(targetLen+1,0);
        matchCounts[0]=1;
        for(int i=1;i<=sourceLen;i++){
            char currentSourceChar=s[i-1];
            for(int j=targetLen;j>=1;j--){
                if(currentSourceChar==t[j-1]){
                    matchCounts[j]+=matchCounts[j-1];
                }
            }
        }
        return static_cast<int>(matchCounts[targetLen]);
    }
};