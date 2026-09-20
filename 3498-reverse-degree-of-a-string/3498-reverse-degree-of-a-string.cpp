class Solution {
public:
    int reverseDegree(string s) {
        int rank[26];
        for(int c=0;c<26;++c){
            rank[c]=26-c;
        }
        int total=0;
        for(int i=0;i<(int)s.size();++i){
            total+=rank[s[i]-'a']*(i+1);
        }
        return total;
    }
};