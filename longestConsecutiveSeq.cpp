#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    unordered_set<int> s;

    for (int i = 0; i < n; i++) 
        cin >> arr[i];
		s.insert(arr[i]);
    }

    int longest = 0;

    for (int i = 0; i < n; i++) {
        if (s.find(arr[i] - 1) == s.end()) {

            int count = 1;
            int x = arr[i];

            while (s.find(x + 1) != s.end()) {
                x++;
                count++;
            }

            if (count > longest) {
                longest = count;
            }
        }
    }

    cout << "Longest consecutive sequence length: " << longest;

    return 0;
}
