//optimal O(n) time complexity

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : nums) {
            freq[num]++;
        }
        
        for (auto &[_, f] : freq) {
            count += f * (f - 1) / 2;
        }
        
        return count;
    }
};
