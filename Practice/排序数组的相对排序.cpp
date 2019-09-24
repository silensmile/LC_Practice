#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

//1122. 数组的相对排序
//给你两个数组，arr1 和 arr2，
//
//arr2 中的元素各不相同
//arr2 中的每个元素都出现在 arr1 中
//对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/relative-sort-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> cnt;
    for (int i = 0; i < arr1.size(); i++)
        cnt[arr1[i]]++;
    vector<int> ans;
    for (int i = 0; i < arr2.size(); i++) {
        for (int j = cnt[arr2[i]]; j > 0; j--) {
            ans.push_back(arr2[i]);
            cnt[arr2[i]]--;
        }
    }
    for (auto a : cnt) {
        while (cnt[a.first] > 0) {
            ans.push_back(a.first);
            cnt[a.first]--;
        }
    }
    return ans;
}