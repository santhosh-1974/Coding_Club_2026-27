class Solution {
public:
    bool helper(int n,int i){
        if(n==0)return true;
        if(n<pow(3,i))return false;
        return helper(n-pow(3,i),i+1)||helper(n,i+1);
    }
    bool checkPowersOfThree(int n) {
        return helper(n,0);
    }
};
