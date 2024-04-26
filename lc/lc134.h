#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = static_cast<int>(gas.size());
        int i = 0;
        while (i < n) {
            if (gas[i] < cost[i]) {
                i++;
                continue;
            }

            int rest = gas[i] - cost[i];
            int j = (i + 1) % n;
            bool whole_loop = true;
            while (j != i) {
                if (gas[j] + rest < cost[j]) {
                    if (j < i) {
                        return -1;
                    }
                    i = j;
                    whole_loop = false;
                    break;
                }
                rest = rest + gas[j] - cost[j];
                j = (j + 1) % n;
            }
            if (whole_loop) {
                i = j +1;
                return i;
            }
        }
        return -1;
    }
};