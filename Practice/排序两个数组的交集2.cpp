#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(const int a, const int b) {
    return a < b;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end(), cmp);
    sort(nums2.begin(), nums2.end(), cmp);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++, j++;
            continue;
        }
        if (nums1[i] > nums2[j]) {
            j++;
            continue;
        }
        if (nums1[i] < nums2[j]) {
            i++;
            continue;
        }
    }
    return ans;
}