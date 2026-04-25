class Solution {
public:
    void helper(string& digits, vector<string>& mapping, int idx, string& subset, vector<string>&ans){
        if(idx==digits.size()){
            ans.push_back(subset);
            return;
        }
        int digit=digits[idx]-'0';
        //THIS IS ALSO CORRECT
        // for(int i=0; i<mapping[digit].size(); i++){
        //     subset.push_back(mapping[digit][i]);
        //     helper(digits, mapping, idx+1, subset, ans);
        //     subset.pop_back();
        // }

        //SIMPLE LOOP
        for(char c: mapping[digit]){
            subset.push_back(c);
            helper(digits, mapping, idx+1, subset, ans);
            subset.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> result;
        string subset;
        helper(digits, mapping, 0, subset, result);
        return result;
    }
};