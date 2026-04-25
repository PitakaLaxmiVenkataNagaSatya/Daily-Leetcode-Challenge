class Solution {
public:
    void generateParenthesis(vector<string> & ans, string s, int open, int close, int n){
       if(open==n && close==n){
           ans.push_back(s);
           return;
        }    
        if(open<n) generateParenthesis(ans, s+"(", open+1, close, n);
        if(close<open) generateParenthesis(ans, s+")", open, close+1, n);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesis(ans,"",0,0,n);
        return ans;
    }
};