class Solution {
public:
    string sum(string s){
        int sum=0;
        for(auto u:s){
            sum+=u-'0';
        }
        return to_string(sum);
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            string r;
            for(int i=0;i<s.size();i+=k){
                r+=sum(s.substr(i,k));
            }
            s=r;
        }
        return s;
    }
};