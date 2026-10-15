#include <iostream>
using namespace std;
int main()
{
    int n, target;
    int arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter target sum: ";
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == complement)
            {
                cout << "Indices: " << j << ", " << i;
            }
        }
    }
    cout << "No valid pair found.";
    return 0;
}
