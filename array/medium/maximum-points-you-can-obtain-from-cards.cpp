class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int currSum=0;
        int maxSum=0;
        int n=cardPoints.size();
        for(int i=0; i<k; i++){
            currSum +=cardPoints[i];
        }
        maxSum=currSum;
        int left=k-1;
        int right=n-1;
        while(left>=0){
            currSum = currSum - cardPoints[left] + cardPoints[right];
            maxSum=max(maxSum, currSum);
            left--;
            right--;
        }
        return maxSum;
    }
};