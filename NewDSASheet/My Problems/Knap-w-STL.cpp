#include <iostream>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items by their value-to-weight ratio in descending order
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to sort items array by decreasing order value-to-weight ratio
void sortItems(struct Item* items, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!cmp(items[j], items[j + 1])) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, struct Item* items, int n) {
    // Sort items by decreasing order value-to-weight ratio
    sortItems(items, n);

    cout << "Items array after sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << "Value: " << items[i].value << ", Weight: " << items[i].weight << endl;
    }

    int currentWeight = 0;   // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding Item[i] doesn't overflow, add it completely
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        // If we can't add current item, add fractional part of it
        else {
            int remain = W - currentWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    // Return final value
    return finalValue;
}

int main() {
    int n; // Number of items
    int W; // Maximum weight of knapsack

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    // Allocate memory for items array
    struct Item* items = new Item[n];

    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Value of item " << i + 1 << ": ";
        cin >> items[i].value;
        cout << "Weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
    }

    double maxValue = fractionalKnapsack(W, items, n);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    // Free memory
    delete[] items;

    return 0;
}
