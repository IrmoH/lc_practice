#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> window;
        map<char, int> need;

        for (auto c: s1) {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s2.size()) {
            char c = s2[right];
            if (need.find(c) != need.end()) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            right++;

            while (valid == need.size()) {
                char d = s2[left];
                if (need.find(d) != need.end()) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                    if (right - left == s1.size()) {
                        return true;
                    }
                }
                left++;
            }
        }
        return false;
    }
};
//滑动窗口