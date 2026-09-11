class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int maxLen = 0;
        int j = 0;
        for(int i = 0; i<s.size(); i++){
            map[s[i]]++;

            while(map[s[i]] > 1){
                map[s[j]]--;
                j++;
            }
            maxLen = max(maxLen, i-j+1);
        }
        return maxLen;
    }
};
