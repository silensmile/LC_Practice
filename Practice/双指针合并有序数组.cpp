#include<iostream>
#include<vector>

using std::vector;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, l = m + n - 1;
    while (i>=0&&j>=0) {
        if (nums1[i] >= nums2[j])
            nums1[l--] = nums1[i--];
        else
            nums1[l--] = nums2[j--];
    }
    if (i == -1) {
        while (j >= 0) {
            nums1[l--] = nums2[j--];
        }
    }
    else if (j == -1) {
        while (i >= 0) {
            nums1[l--] = nums1[i--];
        }
    }
}

void mergeTest() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
}