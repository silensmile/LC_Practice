#include<vector>
#include<stack>
#include<unordered_map>

using std::vector;
using std::stack;
using std::unordered_map;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp; //faster than map
    vector<int> ans(nums1.size(),-1);
    stack<int> st;
    for (int i = 0; i < nums2.size(); i++) {
        while (!st.empty() && nums2[i] > st.top()) {
            int tmp = st.top();
            st.pop();
            mp[tmp] = nums2[i];
        }
        st.push(nums2[i]);
    }
    while (!st.empty()) {
        mp[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < nums1.size();i++) {
        ans[i] = mp[nums1[i]];
    }
    return ans;
}

void nextGreaterElementTest() {
    vector<int> nums1 = { 4, 1, 2 };
    vector<int> nums2 = { 1, 3, 4, 2 };
    nextGreaterElement(nums1, nums2);
}