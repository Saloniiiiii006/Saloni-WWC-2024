A financial technology company needs to process real-time stock market data consisting of millions of trades every minute. Each trade record 
includes the timestamp, stock symbol, trade price, and trade volume. To identify patterns and generate analytics, the trades must be sorted by 
timestamp. For deeper insights, the company also requires sorting by stock symbol and grouping by trading volume trends.
large-scale data efficiently is crucial for providing timely analytics to clients.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// Define a struct to represent a Trade
struct Trade {
    string timestamp;        // Format: "YYYY-MM-DD HH:MM:SS"
    string stockSymbol;
    double tradePrice;
    double tradeVolume;

    // Constructor to initialize a trade
    Trade(string ts, string symbol, double price, double volume)
        : timestamp(ts), stockSymbol(symbol), tradePrice(price), tradeVolume(volume) {}
};

// Comparison function to sort by timestamp, then by stock symbol, then by trading volume
bool compareTrades(const Trade& a, const Trade& b) {
    if (a.timestamp != b.timestamp)
        return a.timestamp < b.timestamp; // Sort by timestamp
    if (a.stockSymbol != b.stockSymbol)
        return a.stockSymbol < b.stockSymbol; // Sort by stock symbol
    return a.tradeVolume > b.tradeVolume; // Sort by trading volume in descending order
}

// Quick Sort algorithm to sort a vector of trades based on multiple criteria
void quickSort(vector<Trade>& trades, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(trades, low, high);

        // Recursively sort the two subarrays
        quickSort(trades, low, pivotIndex - 1);
        quickSort(trades, pivotIndex + 1, high);
    }
}

// Partition function for Quick Sort
int partition(vector<Trade>& trades, int low, int high) {
    Trade pivot = trades[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (compareTrades(trades[j], pivot)) {
            i++;
            swap(trades[i], trades[j]);
        }
    }

    swap(trades[i + 1], trades[high]);
    return i + 1;
}

// Function to generate a random trade for simulation
Trade generateRandomTrade(int id) {
    string timestamp = "2024-12-24 12:34:56"; // Simulate a timestamp
    string stockSymbol = "AAPL";  // Simulate a stock symbol (e.g., AAPL)
    double price = (rand() % 1000) / 10.0 + 100.0; // Random trade price between 100 and 200
    double volume = rand() % 1000; // Random volume between 0 and 1000
    return Trade(timestamp, stockSymbol, price, volume);
}

// Function to display the trades
void displayTrades(const vector<Trade>& trades) {
    for (const auto& t : trades) {
        cout << "Timestamp: " << t.timestamp
             << ", Stock Symbol: " << t.stockSymbol
             << ", Price: " << t.tradePrice
             << ", Volume: " << t.tradeVolume << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Generate a large number of trades for simulation
    int numTrades = 1000000;  // Example: 1 million trades
    vector<Trade> trades;

    for (int i = 0; i < numTrades; ++i) {
        trades.push_back(generateRandomTrade(i));
    }

    // Measure time taken for sorting
    clock_t start = clock();

    // Sort trades based on timestamp, stock symbol, and volume (Quick Sort)
    quickSort(trades, 0, trades.size() - 1);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken to sort " << numTrades << " trades: " << duration << " seconds" << endl;

    // Optionally, display the sorted trades (this would print a huge output for large datasets)
    // displayTrades(trades); // Uncomment to print the sorted trades

    return 0;
}
