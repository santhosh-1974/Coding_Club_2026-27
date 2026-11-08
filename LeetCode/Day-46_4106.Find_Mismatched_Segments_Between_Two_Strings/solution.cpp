class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        int i=0,j=0;
        string temp1="",temp2="";
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                if(temp1!="" && temp2!="")ans.push_back({temp1,temp2});
                temp1=temp2="";
            }
            else{
                temp1+=s1[i];
                temp2+=s2[j];
            }
            i++;j++;
        }
        if(temp1!="" && temp2!="")ans.push_back({temp1,temp2});
        return ans;
    }
};
