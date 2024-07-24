#include <string>
using namespace std;

class Solution {
public:
    void swap_str(string &s, size_t start, size_t end) {
        for (size_t i = start; i <= (start + end) / 2; ++i) {
            swap(s[i], s[end - i + start]);
        }
    }

    string reverseWords(string s) {
        //移除前后空格
        auto first = s.find_first_not_of(' ');
        auto last = s.find_last_not_of(' ');
        s = s.substr(first, last - first + 1);

        //移除单词间的多个空格
        for (auto i = s.begin(); i != s.end();) {
            auto c = *i;
            if (c == ' ' && *(i - 1) == ' ') {
                s.erase(i);
                continue;
            }
            ++i;
        }
        //反转整个字符串
        swap_str(s, 0, s.length() - 1);
        size_t i = 0;
        size_t j = 0;
        while (j <= s.length()) {
            if (s[j] == ' ' || j == s.length()) {
                swap_str(s, i, j - 1);
                i = j + 1;
            }
            j++;
        }
        return s;
    }
};