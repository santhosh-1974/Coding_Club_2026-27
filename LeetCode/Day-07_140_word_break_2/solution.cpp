class Solution {
public:
    void helper(string &s,unordered_set<string>&st,vector<string>&ans,string temp,int index){
        if(index==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            string left=s.substr(index,i-index+1);
            if(st.contains(left)){
                helper(s,st,ans,temp+left+" ",i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<string>ans;
        helper(s,st,ans,"",0);
        return ans;
    }
};