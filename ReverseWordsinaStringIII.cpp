class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i=0;
        int n = s.length();
        while(i<n) {
            int j=i;
            string str = "";

            while(j<n && s[j] != ' ') {
                str += s[j];
                j++;
            }

            reverse(str.begin(), str.end());
            ans += str;

            while(j<n && s[j] == ' ') {
                ans += s[j];
                j++;
            }
            i = j;
        }
        return ans;
    }
};
