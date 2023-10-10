class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        //sort and unique
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());

        for(int i=0; i<temp.size(); i++) {
            int L = temp[i];
            int R = L + (n-1); 

            int j = upper_bound(temp.begin(), temp.end(), R) - temp.begin();

            int within_bound = j - i;
            int out_of_bound = n - within_bound; 
            
            result = min(result, out_of_bound);
        }
        return result;
    }
};
