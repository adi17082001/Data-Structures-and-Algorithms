#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int value;
    int weight;

    Item(int val, int w) {
        value = val;
        weight = w;
    }
};

// Comparator function for sorting by value/weight ratio
bool comp(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item> &arr, int W) {
    sort(arr.begin(), arr.end(), comp);
    double totalVal = 0.0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].weight <= W) {
            totalVal += arr[i].value;
            W -= arr[i].weight;
        } else {
            totalVal += ((double)arr[i].value / arr[i].weight) * W;
            break;
        }
    }

    return totalVal;
}

int main() {
    vector<Item> arr;
    int W = 90;

    arr.push_back(Item(60, 10));
    arr.push_back(Item(100, 20));
    arr.push_back(Item(200, 50));
    arr.push_back(Item(100, 50));

    double res = fractionalKnapsack(arr, W);
    cout << fixed << setprecision(2) << res << endl;

    return 0;
}
