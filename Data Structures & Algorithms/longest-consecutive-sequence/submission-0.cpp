class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int maxCnt = 0;
        for(int x : st){
            if(!st.count(x-1)){
                int cnt = 0;
                int element = x;
                while(st.count(element)){
                    cnt++;
                    element++;
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};
