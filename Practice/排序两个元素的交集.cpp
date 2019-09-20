#include<iostream>
#include<set>
#include<vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> ans1, ans2;
    vector<int> ans;
    for (auto i : nums1)
        ans1.insert(i);
    for (auto i : nums2)
        ans2.insert(i);
    for (auto i : ans1) {
        if (ans2.count(i))
            ans.push_back(i);
    }
    return ans;
}