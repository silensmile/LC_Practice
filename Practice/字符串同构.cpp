#include<string>
#include<unordered_map>

using std::string;
using std::unordered_map;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;
    unordered_map<char, char> mp1,mp2;
    for (int i = 0; i < s.size(); i++)
        mp1[s[i]] = t[i];
    for (int i = 0; i < t.size(); i++)
        mp2[t[i]] = s[i];
    for (int i = 0; i < s.size(); i++) {
        if (mp1[s[i]] != t[i]|| mp2[t[i]] != s[i])
            return false;
    }
    
    return true;
}

void isIsomorphicTest() {
    string s = "paper";
    string t = "title";
    isIsomorphic(s, t);
}