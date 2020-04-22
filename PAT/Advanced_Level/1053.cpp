/*
   问题描述：
   解题思路： 
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int n = dim[0];
        int m = dim[1];
        int res = n;
        for (int i=0; i<n; i++) {
            int L = 0;
            int R = m;
            while (L<R) {
                int M = (L+R)/2;
                if (1 <= binaryMatrix.get(i,M)) {
                    R = M;
                } else {
                    L = M + 1;
                }
            }
            res = min(L,res);
        }
        return res == m?-1 : res;
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}