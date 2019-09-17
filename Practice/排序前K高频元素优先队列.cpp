#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<functional>

using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int>count;
    for (auto i : nums)
        count[i]++;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //创建小根堆，大数在下面先pop <functional>

    for (auto i : count) {
        if (pq.size() < k) {
            pq.push(make_pair(i.second,i.first));
        }
        else if(i.second>=pq.top().first){
            pq.pop();
            pq.push(make_pair(i.second, i.first));
        }
    }
    vector<int> ans(k,0);
    int i = 0;
    while (!pq.empty()) {
        ans[i++] = pq.top().second;
        pq.pop();
    }
    return ans;
}


void topKFrequentTest() {
    vector<int> nums = { 4,1,-1,2,-1,2,3 };
    int k = 2;
    topKFrequent(nums, k);
}