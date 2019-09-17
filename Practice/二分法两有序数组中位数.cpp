#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) {
        int tmp = n; n = m; m = tmp;
        swap(nums1, nums2);
    }
    int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
    while (iMin <= iMax) {
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if (i < iMax && nums2[j - 1] > nums1[i]) {
            iMin = i + 1; // i is too small
        }
        else if (i > iMin && nums1[i - 1] > nums2[j]) {
            iMax = i - 1; // i is too big
        }
        else { // i is perfect
            int maxLeft = 0;
            if (i == 0)
                maxLeft = nums2[j - 1];
            else if (j == 0) {
                maxLeft = nums1[i - 1];
            }
            else {
                maxLeft = (nums1[i - 1] >= nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
            }
            if ((m + n) % 2 == 1) 
                return maxLeft;

            int minRight = 0;
            if (i == m)
                minRight = nums2[j];
            else if (j == n)
                minRight = nums1[i];
            else
                minRight = (nums2[j] <= nums1[i]) ? nums2[j] : nums1[i];

            return (maxLeft + minRight) / 2.0;
        }
    }
    return 0;
}

void findMedianSortedArraysTest() {
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { -1,3 };
    cout<<findMedianSortedArrays(nums1, nums2);
}