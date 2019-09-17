#include<iostream>
#include<vector>

using std::vector;

int singleNonDuplicate(vector<int>& nums) {
    int l = 0, h = nums.size()-1;
    while (l < h) {
        int m = ((h - l) / 2 + l) / 2 * 2;
        if (nums[m] == nums[m + 1])
            l = m + 2;
        else
            h = m;
    }
    return nums[l];
}

void singleNonDuplicateTest() {
    vector<int> a = { 1,1,2,3,3 };
    std::cout << singleNonDuplicate(a);
}