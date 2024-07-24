#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        vector<int> windowCharCount(26);
        int windowMaxChar = 0;
        int res = 0;
        while (right < s.length()) {
            windowCharCount[s[right] - 'A']++;
            windowMaxChar = max(windowMaxChar, windowCharCount[s[right] - 'A']);
            right++;

            while (right - left - windowMaxChar > k) {
                windowCharCount[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};