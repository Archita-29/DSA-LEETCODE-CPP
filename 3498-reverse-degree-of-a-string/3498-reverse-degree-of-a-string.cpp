class Solution {
public:
    int reverseDegree(string s) {
        string rev="zyxwvutsrqponmlkjihgfedcba";
        int total=0;
        for(int i=0;i<(int)s.size();++i){
            int k=(int)rev.find(s[i]);
            total=total+((k+1)*(i+1));
        }
        return total;
    }
};