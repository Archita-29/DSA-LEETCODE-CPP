class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.length();
        int half_len=n/2;
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        int odd_count=0;
        int mid_char=-1;
        for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                odd_count++;
                mid_char=i;
            }
        }
        if(odd_count>1) return "";
        vector<int>half_freq(26,0);
        for(int i=0;i<26;i++){
            half_freq[i]=freq[i]/2;
        }
        auto buildPalindrome=[&](const string& half)->string{
            string full=half;
            if(n%2!=0){
                full+=(char)('a'+mid_char);
            }
            string rev=half;
            reverse(rev.begin(),rev.end());
            full+=rev;
            return full;
        };
        for(int i=half_len;i>=0;i--){
            vector<int>cur_freq=half_freq;
            bool valid_prefix=true;
            string prefix="";
            for(int k=0;k<i;k++){
                int char_idx=target[k]-'a';
                if(cur_freq[char_idx]>0){
                    cur_freq[char_idx]--;
                    prefix+=target[k];
                }else{
                    valid_prefix=false;
                    break;
                }
            }
            if(!valid_prefix) continue;
            if(i==half_len){
                string full=buildPalindrome(prefix);
                if(full>target) return full;
                continue;
            }
            int target_char=target[i]-'a';
            for(int c=target_char+1;c<26;c++){
                if(cur_freq[c]>0){
                    string candidate_half=prefix;
                    candidate_half+=(char)('a'+c);

                    vector<int>rem_freq=cur_freq;
                    rem_freq[c]--;
                    for(int ch=0;ch<26;ch++){
                        while(rem_freq[ch]>0){
                            candidate_half+=(char)('a'+ch);
                            rem_freq[ch]--;
                        }
                    }
                    string res=buildPalindrome(candidate_half);
                    if(res>target) return res;
                }
            }
        }
        return "";
    }
};