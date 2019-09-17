#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++)
        cnt[nums[i]]++;
    int ans = 0;
    for (auto mem : cnt) {
        if (cnt.find(mem.first + 1) != cnt.end())
            ans = (mem.second + cnt[mem.first + 1]) > ans ? (mem.second + cnt[mem.first + 1]) : ans;
    }
    return ans;
}

void findLHSTest() {
    vector<int> nums = { 1,3,2,2,5,2,3,7 };
    findLHS(nums);
}