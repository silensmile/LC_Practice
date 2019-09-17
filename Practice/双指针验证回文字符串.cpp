#include<iostream>
#include<string>

using std::string;

bool validPalindrome(string s) {
    unsigned int i = 0, j = s.size() - 1;
    bool del = 1;
    while (i < j) {
        if (del) {
            if (s[i] == s[j]) {
                i++; j--;
            }
            else {
                del = 0;
                bool a = 1, b = 1;
                unsigned int m = i + 1, n = j;
                while (m < n) {
                    if (s[m] == s[n]) {
                        m++; n--;
                    }
                    else {
                        a = 0;
                        break;
                    }
                }
                if (a == 1)
                    return true;

                m = i, n = j - 1;
                while (m < n) {
                    if (s[m] == s[n]) {
                        m++; n--;
                    }
                    else {
                        b = 0;
                        break;
                    }
                }
                if (b == 1)
                    return true;
                else
                    return false;
            }
        }
    }
    return true;
}

void validPalindromeTest() {
    string s = "abc";
    std::cout << validPalindrome(s);
}