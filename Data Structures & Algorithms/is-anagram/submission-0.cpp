class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> multiset1(s.begin(), s.end()),
            multiset2(t.begin(), t.end());
        return multiset1 == multiset2;
    }
};