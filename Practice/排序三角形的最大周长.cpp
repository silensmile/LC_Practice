#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static bool cmp(const int a, const int b) {
    return a < b;
}

int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end(), cmp);
    int i = A.size() - 3;
    while (!(A[i] + A[i + 1] > A[i + 2])) {
        i--;
        if (i < 0)
            return 0;
    }
    return A[i] + A[i + 1] + A[i + 2];
}

void llargestPerimeterTest() {
    vector<int> A = { 2,1,1 };
    int a = largestPerimeter(A);
}