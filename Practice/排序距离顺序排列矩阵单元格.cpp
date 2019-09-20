#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> m;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            m.push_back({ i,j,abs(i-r0)+abs(j-c0)});
    }
    sort(m.begin(), m.end(), cmp);
    vector<vector<int>> ans;
    for (auto i : m)
        ans.push_back({ i[0],i[1] });
    return ans;
}