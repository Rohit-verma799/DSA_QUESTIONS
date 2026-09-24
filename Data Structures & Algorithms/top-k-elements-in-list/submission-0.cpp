class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
       return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int x : nums){
            map[x]++;
        }
        vector<pair<int,int>> freq;
        for(auto x : map){
            freq.push_back({x.first, x.second});
        }
        sort(freq.begin(), freq.end(), cmp);
        vector<int> ans;
        for(int i = 0; i<k; i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
