class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st(dictionary.begin(),dictionary.end());
        string ans,temp;
        for(int i=0;i<sentence.size();i++){
            temp.push_back(sentence[i]);
            if(st.contains(temp)){
                ans+=temp+" ";
                temp="";
                while(i!=sentence.size()-1 && sentence[i]!=' ')i++;
            }
            else if(sentence[i]==' '){
                ans+=temp;
                temp="";
            }
        }
        if(temp.size())ans+=temp;
        if(ans.back()==' ')ans.pop_back();
        return ans;
    }
};