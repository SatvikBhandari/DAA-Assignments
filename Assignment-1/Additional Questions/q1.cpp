// question 1

#include <bits/stdc++.h>
using namespace std;

bool canDivide(vector<int>& A, int M, int limit) {
    int segments = 1;
    int curOR = 0;

    for (int x : A) {
        if ((curOR | x) <= limit) curOR |= x;
        else {
            segments++;
            curOR = x;
        }
    }
    return segments <= M;
}

int minMaxOR(vector<int>& A, int M) {
    int low = 0, high = 0;

    for (int x : A) high |= x;

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canDivide(A, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main() {
    int N = 4, M = 2;
    vector<int> A = {1, 2, 3, 4};

    cout << minMaxOR(A, M);
    return 0;
}
