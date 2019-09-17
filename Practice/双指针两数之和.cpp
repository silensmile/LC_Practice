#include<iostream>
#include<vector>
using std::vector;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size()-1;
    vector<int> ans = {0,0};
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target)
            return ans = { i + 1,j + 1 };
        else if (sum > target)
            j--;
        else
            i++;
    }
    return ans;
}

void twoSumTest() {
    vector<int> a = { 2,7,11,15 };
    int b = 9;
    std::cout << twoSum(a,b)[0]<< twoSum(a, b)[1];
}