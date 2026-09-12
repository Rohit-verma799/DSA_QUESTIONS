class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int match = 0;

        for (int i = 0; i < 26; i++) {
            if (count1[i] == count2[i]) {
                match++;
            }
        }

        int l = 0;

        for (int i = s1.size(); i < s2.size(); i++) {

            if (match == 26) return true;

            // Add right character
            int idx = s2[i] - 'a';

            count2[idx]++;

            if (count1[idx] == count2[idx]) {
                match++;
            }
            else if (count1[idx] + 1 == count2[idx]) {
                match--;
            }

            // Remove left character
            idx = s2[l] - 'a';

            count2[idx]--;

            if (count1[idx] == count2[idx]) {
                match++;
            }
            else if (count1[idx] - 1 == count2[idx]) {
                match--;
            }

            
            l++;
        }

        return match == 26;
    }
};