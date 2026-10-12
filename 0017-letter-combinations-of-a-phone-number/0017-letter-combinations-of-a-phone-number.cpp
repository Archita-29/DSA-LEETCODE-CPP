class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> phoneMap={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        queue<string>q;
        q.push("");
        for(char digit:digits){
            string letters=phoneMap[digit-'0'];
            int n=q.size();
            for(int i=0;i<n;i++){
                string current=q.front();
                q.pop();

                for(char letter:letters){
                    q.push(current+letter);
                }
            }
        }
        vector<string>result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};