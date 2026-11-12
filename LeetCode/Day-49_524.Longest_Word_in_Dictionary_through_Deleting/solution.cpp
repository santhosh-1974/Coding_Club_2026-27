class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),[](const string &a,const string&b){
            if(a.size()==b.size())return a<b;
            return a.size()>b.size();
        });
        for(auto &str:dictionary){
            if(str.size()>s.size())continue;
            int i=0;
            for(int j=0;j<s.size();j++){
                if(str[i]==s[j])i++;
            }
            if(i==str.size())return str;
        }
        return "";
    }
};
