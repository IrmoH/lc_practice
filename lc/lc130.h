#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        //parent[0]表示边界
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            parent[i] = i;
        }
    }

    int find(int pos) {
        if (parent[pos] != pos) {
            parent[pos] = find(parent[pos]);
        }
        return parent[pos];
    }

    void unite(int pos1, int pos2) {
        parent[find(pos1)] = find(pos2);
    }

private:
    vector<int> parent;
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = static_cast<int>(board.size());
        int col = static_cast<int>(board[0].size());
        UnionFind uf(row * col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                char c = board[i][j];
                if (c == 'O') {
                    int cur_pos = i * col + j + 1;
                    if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                        uf.unite(cur_pos, 0);
                    }
                    if (i > 0 && board[i - 1][j] == 'O') {
                        uf.unite(cur_pos, (i - 1) * col + j + 1);
                    }
                    if (j > 0 && board[i][j - 1] == 'O') {
                        uf.unite(cur_pos, i * col + (j - 1) + 1);
                    }
                    if (j < col - 1 && board[i][j + 1] == 'O') {
                        uf.unite(cur_pos, i * col + (j + 1) + 1);
                    }
                    if (i < row - 1 && board[i + 1][j] == 'O') {
                        uf.unite(cur_pos, (i + 1) * col + j + 1);
                    }
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                char c = board[i][j];
                if (c == 'O') {
                    if (uf.find(i * col + j + 1) != uf.find(0)) {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};
//并查集