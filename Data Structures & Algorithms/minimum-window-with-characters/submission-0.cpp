class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> map;

        for (int i = 0; i < t.size(); i++) {
            map[t[i]]++;
        }

        int cnt = t.size();

        int l = 0;
        int st = -1;
        int minWindow = INT_MAX;

        for (int i = 0; i < s.size(); i++) {

            // Include s[i]
            if (map[s[i]] > 0) {
                cnt--;
            }
            map[s[i]]--;

            // Try shrinking the window
            while (cnt == 0) {

                // Current window is valid
                if (i - l + 1 < minWindow) {
                    st = l;
                    minWindow = i - l + 1;
                }

                // Remove s[l]
                if (map.count(s[l])) {
                    map[s[l]]++;

                    if (map[s[l]] > 0)
                        cnt++;
                }

                l++;
            }
        }

        if (st == -1)
            return "";

        return s.substr(st, minWindow);
    }
};