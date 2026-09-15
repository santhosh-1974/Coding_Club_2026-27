class Solution {
public:
    bool isValid(string str){
        if(str.empty()) return false;
        if(str.size()>1 && str[0]=='0')return false;
        int num=stoi(str);
        return num>=0 && num<=255;
    }
    void helper(string s,vector<string>&ans,string temp,int index,int c){
        if(c==0){
            string last=s.substr(index);
            if(isValid(last)){
                ans.push_back(temp+last);
            }
            return;
        }
        if(index==s.size())return;
        for(int i=index;i<s.size();i++){
            int remaining = s.size()-index;
            int needed = c + 1;
            if(remaining < needed || remaining > needed * 3)return;
            string left=s.substr(index,i-index+1);
            if(left.size()>3)break;
            if(isValid(left)){
                helper(s,ans,temp+left+'.',i+1,c-1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        helper(s,ans,"",0,3);
        return ans;
    }
};