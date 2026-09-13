class Solution {
public:
    bool possible(vector<int>& nums, int hours, int h) {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
           cnt += ceil((double)nums[i] / hours);
            if(cnt > h) {
                return false;
            }
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = INT_MIN;
        int minHour = INT_MAX;

        for(int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }

        while(low <= high) {

            int mid = low + (high - low) / 2;

            bool flag = possible(piles, mid, h);

            if(flag) {
                minHour = min(minHour, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return minHour;
    }
};