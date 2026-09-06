#include <iostream>
using namespace std;

int main() {
    int n, a[100], ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans = ans ^ a[i];
    }

    cout << "Single number = " << ans;

    return 0;
}
