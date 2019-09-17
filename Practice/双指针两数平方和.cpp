#include<iostream>
#include<math.h>


bool judgeSquareSum(int c) {
    int i = 0, j = std::sqrt(c);
    while (i <= j) {
        double s = (double)(i*i) + (double)(j*j);
        if (s == c)
            return true;
        else if (s > c)
            j--;
        else
            i++;
    }
    return false;
}

void judgeSquareSumTest() {
    int a = 0;
    std::cin >> a;
    std::cout << judgeSquareSum(a);
}