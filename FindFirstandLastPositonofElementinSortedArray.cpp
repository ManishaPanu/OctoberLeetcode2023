class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int first = -1, last = -1;

        while(l <= h) {
            int mid = l+(h-l)/2;
            if(nums[mid] == target) {
                first = mid;
                last = mid;
                while(first > 0 && nums[first-1] == target) {
                    first--;
                }
                while(last < nums.size()-1 && nums[last+1] == target) {
                    last++;
                }
                return {first, last};
            }
            else if(nums[mid] > target) {
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        return {first, last};
    }
};
