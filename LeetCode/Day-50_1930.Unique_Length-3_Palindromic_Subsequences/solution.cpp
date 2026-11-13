class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<bool>vis(26,0);
        vector<int>v;
        int count=0;
        for(auto &c:s){
            if(!vis[c-'a']){
                count++;
                vis[c-'a']=1;
            }
            v.push_back(count);
            cout<<count<<" ";
        }
        vector<int>f(26,-1),l(26,-1);
        for(int i=0;i<s.size();i++){
            if(f[s[i]-'a']==-1)f[s[i]-'a']=i;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(l[s[i]-'a']==-1)l[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int r=l[i]-1,l=f[i]+1;
            vector<bool>temp(26,0);
            for(int j=l;j<=r;j++){
                if(!temp[s[j]-'a']){
                    ans++;
                    temp[s[j]-'a']=1;
                }
            }
        }
        return ans;
    }
};
