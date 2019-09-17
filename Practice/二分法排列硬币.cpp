#include<iostream>

int arrangeCoins(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int low = 1, high = n;
    while (low <= high) {
        int mid = (high - low) / 2 + low;
        double sum = (1 + mid)*mid / 2;
        if (sum <= n && sum - n + mid + 1 > 0)
            return mid;
        else if (sum > n)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

void arrangeCoinsTest() {
    int a = 0;
    std::cin >> a;
    std::cout << arrangeCoins(a);
}