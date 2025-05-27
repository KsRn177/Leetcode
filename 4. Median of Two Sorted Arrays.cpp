class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                merge.push_back(nums1[i++]);
            } else {
                merge.push_back(nums2[j++]);
            }
        }

        while (i < n) {
            merge.push_back(nums1[i++]);
        }

        while (j < m) {
            merge.push_back(nums2[j++]);
        }

        int size = merge.size();
        if (size % 2 == 1) {
            return double(merge[size / 2]);
        } else {
            double x = merge[size / 2 - 1] + merge[size / 2];
            return x / 2;
        }
    }
};
