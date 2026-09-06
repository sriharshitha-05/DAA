#include <iostream>
using namespace std;

int main() {
    int n, a[100];
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        int ans = -1;

        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[i]) {
                ans = a[j];
                break;
            }
        }

        cout << ans << " ";
    }

    return 0;
}
