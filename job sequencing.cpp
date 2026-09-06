#include <iostream>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cin >> n;

    Job job[20];

    for(int i = 0; i < n; i++)
        cin >> job[i].id >> job[i].deadline >> job[i].profit;

    // Sort by profit
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(job[i].profit < job[j].profit)
                swap(job[i], job[j]);
        }
    }

    int slot[20];

    for(int i = 0; i < 20; i++)
        slot[i] = -1;

    int profit = 0;

    for(int i = 0; i < n; i++) {

        for(int j = job[i].deadline; j > 0; j--) {

            if(slot[j] == -1) {
                slot[j] = i;
                profit += job[i].profit;
                break;
            }
        }
    }

    cout << "Jobs: ";

    for(int i = 1; i < 20; i++) {
        if(slot[i] != -1)
            cout << job[slot[i]].id << " ";
    }

    cout << "\nProfit = " << profit;

    return 0;
}
