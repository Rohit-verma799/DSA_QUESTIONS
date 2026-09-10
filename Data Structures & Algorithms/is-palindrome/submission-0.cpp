class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(char x : s){
            if(isalnum(x)){

                s1.push_back(tolower(x));
            }
        }
        cout << s1;
        int i = 0;
        int j = s1.size()-1;
        while(i < j){
            if(s1[i] != s1[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
};
