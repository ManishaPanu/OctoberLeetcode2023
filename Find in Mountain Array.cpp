/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeekIdx(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0;
        int r = n-1;
        while(l < r) {
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else r = mid;
        }
        return l;
    }

    int binarySearch(int start, int end, MountainArray &mountainArr, int target) {
        while(start <= end) {
            int mid = start+(end-start)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                start = mid+1;
            else end = mid-1;
        }
        return -1;
    }

    int reverseBinarySearch(int start, int end, MountainArray &mountainArr, int target) {
        while(start <= end) {
            int mid = start+(end-start)/2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) > target)
                start = mid+1;
            else end = mid-1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = findPeekIdx(mountainArr);

        int result_idx = binarySearch(0, idx, mountainArr, target);

        if(result_idx != -1) {
            return result_idx;
        }

        result_idx = reverseBinarySearch(idx+1, n-1, mountainArr, target);

        return result_idx;
    }
};
