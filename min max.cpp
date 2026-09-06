#include <iostream>
using namespace std;

int main() {
    int n, a[100];
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int min = a[0];
    int max = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] < min)
            min = a[i];

        if(a[i] > max)
            max = a[i];
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max;

    return 0;
}
