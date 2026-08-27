class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();
        vector<int>count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        vector<int>current_count=count;
        int max_match=0;
        while(max_match<n){
            int char_idx=target[max_match]-'a';
            if(current_count[char_idx]>0){
                current_count[char_idx]--;
                max_match++;
            }else{
                break;
            }
        }
        for(int i=max_match;i>=0;i--){
            vector<int>freq=count;
            for(int j=0;j<i;j++){
                freq[target[j]-'a']--;
            }
            int target_char=(i<n)?(target[i]-'a'):-1;
            for(int c=target_char+1;c<26;c++){
                if(freq[c]>0){
                    string result=target.substr(0,i);
                    result+=(char)('a'+c);
                    freq[c]--;
                    for(int k=0;k<26;k++){
                        while(freq[k]>0){
                            result+=(char)('a'+k);
                            freq[k]--;
                        }
                    }
                    return result;
                }
            }
        }
        return "";
    }
};