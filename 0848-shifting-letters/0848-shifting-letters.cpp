class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        long long currentShift=0;
        for(int i=n-1;i>=0;i--){
            currentShift=(currentShift+shifts[i])%26;
            s[i]='a'+(s[i]-'a'+currentShift)%26;
        }
        return s;
    }
};