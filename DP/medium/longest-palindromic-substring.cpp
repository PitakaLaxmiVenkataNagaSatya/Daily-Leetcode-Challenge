class Solution {
public:
    // bool isPalindrome(int i, int j, string s){
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;
    //         else{
    //             i++;
    //             j--;
    //         }
    //     }
    //     return true;
    // }
    string longestPalindrome(string s) {
        //BRUTE FORCE
        // int maxLen=0;
        // string result;
        // for(int i=0; i<s.size(); i++){
        //     for(int j=i; j<s.size(); j++){
        //         if(isPalindrome(i,j,s)){
        //             if(j-i+1>maxLen){
        //                 maxLen=j-i+1;
        //                 result.clear();
        //                 for (int k = i; k <= j; k++) {
        //                     result += s[k];
        //                 }
        //             }
        //         }
        //     }
        // }
        // return result;
        int n=s.size();
        int start=0;
        int maxLen=1;
        for(int i=0; i<n; i++){
            //odd
            int l=i-1;
            int r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxLen){
                    maxLen=max(maxLen, r-l+1);
                    start=l;
                }                
                l--;
                r++;
            }
            //even
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxLen){
                    maxLen=max(maxLen, r-l+1);
                    start=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};