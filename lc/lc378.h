#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    struct Item {
        int num_;
        int row_;
        int col_;
        bool operator<(const Item &other) const {
            return num_ > other.num_;
        }
    };
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        priority_queue<Item> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({matrix[i][0], i, 0});
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            k--;
            if (k == 0) {
                return cur.num_;
            }
            int col = cur.col_ + 1;
            if (col != n) {
                pq.push({matrix[cur.row_][col], cur.row_, col});
            }
        }
        return 0;
    }
};