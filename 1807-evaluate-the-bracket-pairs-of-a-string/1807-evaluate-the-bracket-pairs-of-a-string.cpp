class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>dict;
        for(const auto& pair:knowledge){
            dict[pair[0]]=pair[1];
        }
        string result="";
        string key="";
        bool in_bracket=false;
        for(char c:s){
            if(c=='('){
                in_bracket=true;
                key="";
            }else if(c==')'){
                in_bracket=false;
                auto it=dict.find(key);
                if(it!=dict.end()){
                    result+=it->second;
                }else{
                    result+='?';
                }
            }else if(in_bracket){
                key+=c;
            }else{
                result+=c;
            }
        }
        return result;
    }
};