class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(cnt1 == 0 && ele2 != nums[i]) {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && ele1 != nums[i]) {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(ele1 == nums[i]) {
                cnt1++;
            }
            else if(ele2 == nums[i]) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> l;
        int c1=0, c2=0;
        for(int i=0; i<n ;i++) {
            if(nums[i] == ele1)
                c1++;
            if(nums[i] == ele2)
                c2++;
        }
        if(c1 > (n/3)) l.push_back(ele1);
        if(c2 > (n/3)) l.push_back(ele2);
        return l;
    }
};
