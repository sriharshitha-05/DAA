#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // Sort according to finish time
    sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });

    int count = 1;
    int last = a[0].second;

    cout << a[0].first << " " << a[0].second << endl;

    for (int i = 1; i < n; i++) {
        if (a[i].first >= last) {
            cout << a[i].first << " " << a[i].second << endl;
            last = a[i].second;
            count++;
        }
    }

    cout << "Maximum activities: " << count << endl;

    return 0;
}
