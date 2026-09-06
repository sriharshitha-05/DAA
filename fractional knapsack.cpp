#include <iostream>
using namespace std;

int main() {
    int n, W;
    int weight[20], value[20];
	cout<<"Enter number of objects:";
    cin >> n;
	cout<<"Enter objects weight:";
    for(int i = 0; i < n; i++)
        cin >> weight[i];
	cout<<"Enter profit:";
    for(int i = 0; i < n; i++)
        cin >> value[i];
    cout<<"Enter max size of knap sack:";
    cin >> W;

    int dp[20][100];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {

            if(i == 0 || w == 0)
                dp[i][w] = 0;

            else if(weight[i-1] <= w)
                dp[i][w] =
                max(value[i-1] + dp[i-1][w-weight[i-1]],
                    dp[i-1][w]);

            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum value = " << dp[n][W];

    return 0;
}
