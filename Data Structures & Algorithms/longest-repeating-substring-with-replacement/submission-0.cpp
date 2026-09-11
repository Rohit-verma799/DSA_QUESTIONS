class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int maxCnt = 0;
        int j = 0;
        vector<int> freq(26,0);
        for(int i = 0; i<s.size(); i++){
            freq[s[i] - 'A']++;
            maxCnt = max(maxCnt, freq[s[i] - 'A']);

            int need = (i - j + 1) - maxCnt;
            while(need > k){
                freq[s[j] - 'A']--;
                j++;
                need = (i - j + 1) - maxCnt;
            }

            maxLen = max(maxLen , i-j+1);
        }
        return maxLen;
    }
};
