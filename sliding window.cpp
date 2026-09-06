#include <iostream>
using namespace std;

int main() {
    int n, k, a[100];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> k;

    int maxSum = 0;

    for(int i = 0; i < k; i++)
        maxSum += a[i];

    int sum = maxSum;

    for(int i = k; i < n; i++) {
        sum = sum + a[i] - a[i-k];

        if(sum > maxSum)
            maxSum = sum;
    }

    cout << "Maximum sum = " << maxSum;

    return 0;
}
