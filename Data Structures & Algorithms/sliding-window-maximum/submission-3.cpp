class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        int l = 1;

        for(int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});

            while(pq.top().second < l) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
            l++;
        }

        return ans;
    }
};