class Solution {
public:
    long long ceil(long long a, long long b) {
        return (a + b - 1) / b;
    }

    long long isMinK(int x, vector<int>& piles) {
        long long time = 0;

        for(int i = 0; i < piles.size(); i++) {
            time += ceil(piles[i], x);
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int maxEle = INT_MIN;

        for(int i = 0; i < piles.size(); i++) {
            sum += piles[i];
            maxEle = max(maxEle, piles[i]);
        }

        long long Lb = ceil(sum, h);

        int s = (int)Lb;
        int e = maxEle;

        while(s < e) {
            int mid = s + (e - s) / 2;

            if(isMinK(mid, piles) <= h) {
                e = mid;
            }
            else {
                s = mid + 1;
            }
        }

        return s;
    }
};