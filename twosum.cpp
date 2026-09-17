#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout<<"Enter array size:";
    cin >> n;

    int arr[100];
    cout<<"Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Enter target:";
    cin >> target;
    int count=0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Indices: " << i << ", " << j << endl;
                count++;
            }
        }
    }

    if(count==0)
    {
    	cout << "No valid pair found.";
	}
    return 0;
}

 
