// question 4 

#include <bits/stdc++.h>
using namespace std;

int specialtySum(vector<int>& A, int k) {
    int n = A.size();
    int sum = 0;

    for (int l = 0; l < n; l++) {
        bool special = false;

        for (int r = l; r < n; r++) {
            int greaterCount = 0;

            for (int i = l; i <= r; i++)
                if (A[i] > A[l]) greaterCount++;

            if (greaterCount == k) {
                special = true;
                break;
            }
        }

        if (special) sum += A[l];
    }
    return sum;
}

int main() {
    vector<int> A = {3, 1, 4, 2};
    int k = 1;

    cout << specialtySum(A, k);
    return 0;
}

