#include<vector>
#include<stack>

using std::vector;
using std::stack;

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> max;
    vector<int> ans(T.size(),0);
    for (int i = 0; i < T.size(); i++) {
        while (!max.empty() && T[i] > T[max.top()]) { //不大就先记录位置，看下一个好了
            int tmp = max.top();
            max.pop();
            ans[tmp] = i - tmp;
        }
        max.push(i);
    }
    return ans;
}

void dailyTemperaturesTest() {
    vector<int> T = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> TJ = dailyTemperatures(T);
}