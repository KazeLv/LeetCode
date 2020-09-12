/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int i = 0, j = 0;
        int pre, now;
        double res;
        for(int cnt = 1; cnt <=len/2+1 ;cnt++){
            if(i < nums1.size() && j < nums2.size()){
                if(nums1[i] < nums2[j]) now = nums1[i++];
                else now = nums2[j++];
            }else if(i < nums1.size() && j == nums2.size()) now = nums1[i++];
            else if(i == nums1.size() && j < nums2.size()) now = nums2[j++];
            if(cnt == len/2) pre = now;
        }
        if(len%2 == 0) res = (pre + now) / 2.0;
        else res = now;
        return res;
    }
};
// @lc code=end

