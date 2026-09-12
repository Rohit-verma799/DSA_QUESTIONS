class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int l = 0;
        int cnt = 0;
        int maxLen = 0;

        for(int i = 0; i<fruits.size(); i++){
            if(map[fruits[i]] == 0){
                cnt++;
            }
            map[fruits[i]]++;

            while(cnt > 2){
                map[fruits[l]]--;
                if(map[fruits[l]] == 0){
                    cnt--;
                }
                l++;
            }

            maxLen = max(maxLen, i-l+1);
        }
        return maxLen;
    }
};