class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int>diff(n+1,0);
        for(const auto& shift:shifts){
            int start=shift[0];
            int end=shift[1];
            int direction=shift[2];

            int val=(direction==1)?1:-1;
            diff[start]+=val;
            diff[end+1]-=val;
        }
        int current_shift=0;
        for(int i=0;i<n;i++){
            current_shift+=diff[i];
            int net_shift=(current_shift%26+26)%26;
            s[i]='a'+(s[i]-'a'+net_shift)%26;
        }
        return s;
    }
};