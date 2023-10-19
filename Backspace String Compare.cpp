class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1, st2;
        for(int i=0; i<s.length(); i++) {
            if(!st1.empty() && s[i] == '#') {
                st1.pop();
                continue;
            }
            if(s[i] == '#') continue;
            st1.push(s[i]);
        }

        for(int i=0; i<t.length(); i++) {
            if(!st2.empty() && t[i] == '#') {
                st2.pop();
                continue;
            }
            if(t[i] == '#') continue;
            st2.push(t[i]);
        }

        if(st1.empty()) return st2.empty();

        if(st1.size() != st2.size()) return false;

        while(!st1.empty() && !st2.empty()) {
            int t1 = st1.top();
            int t2 = st2.top();
            st1.pop();
            st2.pop();
            if(t1 != t2) return false;
        }
        return true;
    }
};
