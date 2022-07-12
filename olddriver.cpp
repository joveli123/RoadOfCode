#include "head.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> consum(n, 0);
        for(int i = 0; i < n; i++){
            consum[i] = gas[i] - cost[i];
        }
        int gasRes = 0;
        int gasMin = 0;
        int start = 0;
        for (int i = 0; i < n; i++){
            gasRes += consum[i];
            if (gasRes < gasMin){
                start = i + 1;
                gasMin = gasRes;
            }
        }
        if(gasRes < 0){
            return -1;
        }

        return start == n ? 0 : start;
    }
};