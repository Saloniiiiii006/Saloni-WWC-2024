A social media platform runs advertisements for multiple advertisers, each targeting specific user demographics. Ads are prioritized based on factors like bid amount, engagement rates, and the remaining budget. To maximize revenue and user satisfaction, the platform must sort and schedule ads
in real-time for millions of users while balancing competing priorities. Efficient sorting directly impacts ad visibility and revenue generation.
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <ctime>

using namespace std;

// Define a struct to represent an Advertisement
struct Ad {
    int adID;              // Unique identifier for the ad
    double bidAmount;      // Bid amount for the ad
    double engagementRate; // Engagement rate (CTR or similar)
    double remainingBudget;// Remaining budget for the ad campaign

    // Constructor to initialize the ad
    Ad(int id, double bid, double engagement, double budget)
        : adID(id), bidAmount(bid), engagementRate(engagement), remainingBudget(budget) {}

    // Comparison operator to prioritize ads in max-heap (priority queue)
    bool operator<(const Ad& other) const {
        // Prioritize based on bidAmount > engagementRate > remainingBudget
        if (bidAmount != other.bidAmount)
            return bidAmount < other.bidAmount; // Higher bid amount has higher priority
        if (engagementRate != other.engagementRate)
            return engagementRate < other.engagementRate; // Higher engagement rate has higher priority
        return remainingBudget < other.remainingBudget; // Higher remaining budget has higher priority
    }
};

// Function to simulate the sorting and scheduling of ads
void scheduleAds(vector<Ad>& ads) {
    // Use a priority queue (max-heap) to schedule ads
    priority_queue<Ad> adQueue;

    // Push all ads into the priority queue
    for (const auto& ad : ads) {
        adQueue.push(ad);
    }

    // Display ads in the order they will be shown (highest priority first)
    cout << "Ads Scheduled (Highest Priority First):" << endl;
    while (!adQueue.empty()) {
        const Ad& ad = adQueue.top();
        cout << "Ad ID: " << ad.adID
             << ", Bid: " << ad.bidAmount
             << ", Engagement Rate: " << ad.engagementRate
             << ", Remaining Budget: " << ad.remainingBudget << endl;
        adQueue.pop();
    }
}

// Function to generate a random ad for simulation
Ad generateRandomAd(int id) {
    double bid = (rand() % 10000 + 1000) / 100.0;  // Random bid amount between 10.00 and 100.00
    double engagement = (rand() % 5000 + 500) / 100.0; // Random engagement rate between 5.00 and 50.00
    double budget = (rand() % 10000 + 1000) / 100.0; // Random remaining budget between 10.00 and 100.00
    return Ad(id, bid, engagement, budget);
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Generate a large number of ads for simulation
    int numAds = 1000000;  // Example: 1 million ads
    vector<Ad> ads;

    for (int i = 0; i < numAds; ++i) {
        ads.push_back(generateRandomAd(i));
    }

    // Measure time taken for sorting and scheduling
    clock_t start = clock();

    // Schedule ads based on their priority
    scheduleAds(ads);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken to schedule " << numAds << " ads: " << duration << " seconds" << endl;

    return 0;
}

