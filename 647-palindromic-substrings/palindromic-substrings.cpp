class Solution {
public:

    bool Palindrome(int i,int j,string s){
        while(i<j){
             if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
       
    

    int countSubstrings(string s) {
        int i = 0;
        int j = 0;
        int ans =0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
            if(Palindrome(i,j,s)){
                ans++;
            }
        }
        }
        return ans;

    };
};