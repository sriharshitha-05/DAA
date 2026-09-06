#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n, a[100];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = a[0], y = a[1];
    int minDiff = abs(a[0] - a[1]);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int diff = abs(a[i] - a[j]);

            if(diff < minDiff) {
                minDiff = diff;
                x = a[i];
                y = a[j];
            }
        }
    }

    cout << "Closest pair: " << x << " " << y;

    return 0;
}
