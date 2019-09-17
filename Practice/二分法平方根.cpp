#include<iostream>

int mySqrt(int x) {
    if (x == 1) return x;
    int low = 1, high = x;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int sqrt = x / mid;
        if (mid == sqrt)
            return sqrt;
        else if (mid < sqrt)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low-1;
}

void mySqrtTest() {
    int a = 0;
    std::cin >> a;
    std::cout << mySqrt(a);
}