class Solution {
public:
    int palin(string s,int l,int r){
        while((l>=0 && r<s.length()) && (s[l] == s[r])){
            l--;
            r++;            
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        if(n < 2) return s;
        int start = 0, end = 0, len;;
        for(int i=0;i<n;i++){
            int l1=palin(s,i,i);
            int l2=palin(s,i,i+1);
            len=max(l1,l2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
