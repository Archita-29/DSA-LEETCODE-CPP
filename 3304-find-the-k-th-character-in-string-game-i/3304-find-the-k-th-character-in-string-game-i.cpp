class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            int n=s.length();
            for(int i=0;i<n;i++){
                char ch=s[i]=='z'?'a':s[i]+1;
                s.push_back(ch);
            }
        }
        return s[k-1];
    }
};