class Solution {
public:
    vector<int> helper(int row) {
        vector<int> ans;
        long num = 1;
        ans.push_back((int)num);
        for(int i=1; i<=row-1; i++) {
            num = num*(row-i);
            num = num/i;
            ans.push_back((int)num);
        }
        return ans;
    }

    vector<int> getRow(int rowIndex) {
        return helper(rowIndex+1);
    }
};
