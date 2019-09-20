#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> ans(A.size());
    int odd = 1,even = 0;
    map<int,int> cnt;
    for (auto i : A)
        cnt[i]++;
    for (auto i : cnt) {
        for (int j = 0; j < i.second; j++) {
            if (i.first % 2) {
                ans[odd] = i.first;
                odd += 2;
            }
            else {
                ans[even] = i.first;
                even += 2;
            }
        }
    }
    return ans;
}