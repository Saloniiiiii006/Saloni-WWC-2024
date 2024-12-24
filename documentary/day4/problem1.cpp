A banking institution monitors transactions for potential fraud by analyzing patterns in transaction size, frequency, and geographical location
The transactions are sorted by suspiciousness score, calculated using a combination of these factors. High-risk transactions are flagged for
immediate review by analysts, requiring a robust and scalable sorting mechanism to handle millions of records daily.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Define a struct to represent a Transaction
struct Transaction {
    int transactionID;
    double suspiciousnessScore;
    double transactionSize;
    int transactionFrequency;
    string geographicalLocation;

    // Constructor to initialize a transaction
    Transaction(int id, double score, double size, int freq, const string& location)
        : transactionID(id), suspiciousnessScore(score), transactionSize(size), 
          transactionFrequency(freq), geographicalLocation(location) {}
};

// Comparison function for sorting based on suspiciousness score
bool compareTransactions(const Transaction& a, const Transaction& b) {
    return a.suspiciousnessScore > b.suspiciousnessScore;  // Sort in descending order
}

// Quick Sort algorithm to sort a vector of transactions based on the suspiciousness score
void quickSort(vector<Transaction>& transactions, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(transactions, low, high);

        // Recursively sort the two subarrays
        quickSort(transactions, low, pivotIndex - 1);
        quickSort(transactions, pivotIndex + 1, high);
    }
}

// Partition function for Quick Sort
int partition(vector<Transaction>& transactions, int low, int high) {
    double pivot = transactions[high].suspiciousnessScore;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (transactions[j].suspiciousnessScore > pivot) {
            i++;
            swap(transactions[i], transactions[j]);
        }
    }

    swap(transactions[i + 1], transactions[high]);
    return i + 1;
}

// Function to generate a random transaction for simulation
Transaction generateRandomTransaction(int id) {
    double score = (rand() % 1000) / 10.0; // Random suspiciousness score between 0 and 100
    double size = (rand() % 10000) / 10.0; // Random transaction size
    int freq = rand() % 50; // Random transaction frequency
    string location = "Location_" + to_string(rand() % 100); // Random location
    return Transaction(id, score, size, freq, location);
}

// Function to display the transactions
void displayTransactions(const vector<Transaction>& transactions) {
    for (const auto& t : transactions) {
        cout << "Transaction ID: " << t.transactionID
             << ", Suspiciousness Score: " << t.suspiciousnessScore
             << ", Size: " << t.transactionSize
             << ", Frequency: " << t.transactionFrequency
             << ", Location: " << t.geographicalLocation << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Generate a large number of transactions for simulation
    int numTransactions = 1000000;  // Example: 1 million transactions
    vector<Transaction> transactions;

    for (int i = 0; i < numTransactions; ++i) {
        transactions.push_back(generateRandomTransaction(i));
    }

    // Measure time taken for sorting
    clock_t start = clock();

    // Sort transactions based on suspiciousness score using Quick Sort
    quickSort(transactions, 0, transactions.size() - 1);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken to sort " << numTransactions << " transactions: " << duration << " seconds" << endl;

    // Optionally, display the sorted transactions
    // displayTransactions(transactions); // Uncomment to print the sorted transactions

    return 0;
}
