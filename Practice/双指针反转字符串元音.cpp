#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using std::cout;
using std::find;
using std::vector;
using std::string;

string reverseVowels(string s) {
    string list = "aeiouAEIOU";
    int i = 0, j = s.size()-1;
    while (i<j) {
        if (list.find(s[i]) == list.npos)
            i++;
        if (list.find(s[j]) == list.npos)
            j--;
        if (list.find(s[i]) != list.npos&&list.find(s[j]) != list.npos) {
            std::swap(s[i], s[j]);
            i++, j--;
        }
    }
    return s;
}

void reverseVowelsTest() {
    string s = "hello";
    cout << reverseVowels(s);
}