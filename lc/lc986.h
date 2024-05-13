#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            auto first = firstList[i];
            auto second = secondList[j];
            if (first[0] <= second[0]) {
                if (first[1] < second[1]) {
                    if (first[1] >= second[0]) {
                        ans.push_back({second[0], first[1]});
                    }
                    i++;
                } else {
                    ans.push_back({second});
                    j++;
                }
            } else {
                if (second[1] < first[1]) {
                    if (second[1] >= first[0]) {
                        ans.push_back({first[0], second[1]});
                    }
                    j++;
                } else {
                    ans.push_back(first);
                    i++;
                }
            }
        }
        return ans;
    }
};