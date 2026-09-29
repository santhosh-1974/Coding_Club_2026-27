class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string,string>m;
        for(auto &vec:knowledge){
            m[vec[0]]=vec[1];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int st=i+1;
                while(s[i]!=')')i++;
                string key=s.substr(st,i-st);
                if(m.contains(key))ans+=m[key];
                else ans+='?';
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};