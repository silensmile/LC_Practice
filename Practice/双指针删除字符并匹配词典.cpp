#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

string findLongestWord(string s, vector<string>& d) {
    string ans = {};
    if (d.empty() || s.empty())
        return ans;
    int di = 0, i = 0, j = 0;
    for (di = 0; di < d.size(); di++) {
        for (i = 0, j = 0; i < s.length() && j < d[di].length(); i++) {
            if (s[i] == d[di][j])
                j++;
            if (j == d[di].length()) { //found
                if (ans.length() < d[di].length() || (ans.length() == d[di].length() && d[di] < ans))
                    ans = d[di];
            }
        }
    }
    return ans;
}

void findLongestWord() {
    /*string s = "abpcplea";
    vector<string> d = { "ale", "apple", "monkey", "plea" };*/
    string s = "a";
    vector<string> d = { "a"};
    std::cout<<findLongestWord(s, d);
}