// question 2

#include <bits/stdc++.h>
using namespace std;

int maxGoodSubsequence(vector<int>& A) {
    sort(A.begin(), A.end());

    int i = 0, ans = 0;

    for (int j = 0; j < A.size(); j++) {
        while (A[j] - A[i] > 10) i++;
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main() {
    vector<int> A = {1, 5, 9, 12, 15};

    cout << maxGoodSubsequence(A);
    return 0;
}
