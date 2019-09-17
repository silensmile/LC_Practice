#include<vector>
#include<stack>

using std::vector;
using std::stack;

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> ans(nums.size(),-1);
    stack<int> st;
    for (int i = 0; i < nums.size()*2-1; i++) {
        while (!st.empty() && nums[i%nums.size()] > nums[st.top()]) {
            int tmp = st.top();
            st.pop();
            ans[tmp] = nums[i%nums.size()];
        }
        st.push(i%nums.size());
    }
    
    return ans;
}

void nextGreaterElementsTest() {
    vector<int> nums = { 1,2,1 };
    nextGreaterElements(nums);
}