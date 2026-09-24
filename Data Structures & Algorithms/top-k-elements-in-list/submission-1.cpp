class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int x : nums){
            map[x]++;
        }
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        for(auto x : map){
            freq[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i = freq.size()-1; i>0; i--){
            if(!freq[i].empty()){
                for(int j = 0; j<freq[i].size(); j++){
                    ans.push_back(freq[i][j]);
                    k--;
                    if(k == 0) return ans;
                }
            }
        }
        return {};
    }
};
