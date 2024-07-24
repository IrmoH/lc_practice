#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> window;

        int left = 0;
        int right = 0;
        int max_len = 0;
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            right++;

            while (left < right && window[c] > 1) {
                char a = s[left];
                window[a]--;
                left++;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
//最长字串