#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        map<char, int> window;
        map<char, int> need;
        for (auto c: p) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s.size()) {
            char c = s[right];
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            right++;


            while (valid == need.size()) {
                char d = s[left];
                if (need.find(d) != need.end()) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                    if (right - left == p.size()) {
                        res.push_back(left);
                    }
                }
                left++;
            }
        }
        return res;
    }
};