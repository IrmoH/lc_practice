#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> window;
        map<char, int> search;
        for (auto c: t) {
            search[c]++;
        }

        int left = 0;
        int right = 0;

        int left_index = 0;
        auto min_len = s.size() + 1;

        int valid = 0;

        while (right < s.size()) {
            char c = s[right];
            if (search.count(c)) {
                window[c]++;
                if (window[c] == search[c]) {
                    valid++;
                }
            }
            right++;

            while (left < right && valid == search.size()) {
                auto len = right - left;
                if (len < min_len) {
                    min_len = len;
                    left_index = left;
                }

                char d = s[left];
                if (search.count(d)) {
                    if (window[d] == search[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
        }
        if (min_len == s.size() + 1) {
            return "";
        }
        return s.substr(left_index, min_len);
    }
};
//滑动窗口