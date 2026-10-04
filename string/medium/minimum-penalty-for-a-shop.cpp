class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int> prefixSufixsum(n+1, 0);
        int pre=0;
        int suf=0;
        int count;
        int ans=n;
        for(int i=0; i<=n; i++){
            prefixSufixsum[i] += pre;
            if(i!=n && customers[i]=='N') pre += 1;
        }
        count = prefixSufixsum[n];
        for(int i=n-1; i>=0; i--){
            prefixSufixsum[i] += suf;
            if(customers[i]=='Y'){
                suf += 1;
                prefixSufixsum[i]++;
            }
            if(prefixSufixsum[i]<=count){
                ans=i;
                count = prefixSufixsum[i];
            }
        }
        return ans;
    }
};