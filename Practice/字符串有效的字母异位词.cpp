#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    unordered_map<char, int> a, b;
    for (int i = 0; i < s.size(); i++)
        a[s[i]]++;
    for (int i = 0; i < t.size(); i++)
        b[t[i]]++;
    for (auto i : a) {
        if (i.second != b[i.first])
            return false;
    }
    return true;
}