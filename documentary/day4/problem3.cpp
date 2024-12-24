A video streaming platform generates recommendations for users based on the popularity of movies and TV shows. Each item in the catalog has attributes like total views, user ratings, and release year. The system must sort the catalog to prioritize trending content by combining popularity and recency. Furthermore, personalized
  recommendations require sorting by relevance to each user's viewing history, making the sorting process dynamic and computationally intensive 

  #include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <ctime>

using namespace std;

// Define a struct to represent a Catalog Item (Movie/TV Show)
struct CatalogItem {
    string title;
    int totalViews;          // Total views (popularity)
    double userRating;       // User ratings (popularity)
    int releaseYear;         // Release year (recency)
    double relevanceScore;   // Personalized relevance (for user-specific sorting)

    // Constructor to initialize a catalog item
    CatalogItem(string t, int views, double rating, int year, double relevance = 0.0)
        : title(t), totalViews(views), userRating(rating), releaseYear(year), relevanceScore(relevance) {}
};

// Comparison function to sort catalog items by total views, user rating, release year, and relevance score
bool compareCatalogItems(const CatalogItem& a, const CatalogItem& b) {
    // First, compare by total views (popularity)
    if (a.totalViews != b.totalViews)
        return a.totalViews > b.totalViews; // Sort in descending order (more views = more popular)

    // If views are equal, compare by user rating (popularity)
    if (a.userRating != b.userRating)
        return a.userRating > b.userRating; // Higher ratings are better

    // If views and ratings are equal, compare by release year (recency)
    if (a.releaseYear != b.releaseYear)
        return a.releaseYear > b.releaseYear; // Newer releases are better

    // If views, ratings, and release year are equal, compare by relevance score (personalized)
    return a.relevanceScore > b.relevanceScore; // Higher relevance score is better
}

// Quick Sort algorithm to sort catalog items based on multiple criteria
void quickSort(vector<CatalogItem>& catalog, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(catalog, low, high);

        // Recursively sort the two subarrays
        quickSort(catalog, low, pivotIndex - 1);
        quickSort(catalog, pivotIndex + 1, high);
    }
}

// Partition function for Quick Sort
int partition(vector<CatalogItem>& catalog, int low, int high) {
    CatalogItem pivot = catalog[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (compareCatalogItems(catalog[j], pivot)) {
            i++;
            swap(catalog[i], catalog[j]);
        }
    }

    swap(catalog[i + 1], catalog[high]);
    return i + 1;
}

// Function to generate a random catalog item for simulation
CatalogItem generateRandomCatalogItem(int id) {
    string title = "Movie_" + to_string(id);
    int views = rand() % 1000000 + 1000;  // Random views between 1000 and 1,000,000
    double rating = (rand() % 500 + 500) / 100.0;  // Random rating between 5.0 and 10.0
    int releaseYear = rand() % 40 + 1980;  // Random release year between 1980 and 2020
    double relevance = (rand() % 1000) / 10.0;  // Random relevance score for personalized sorting
    return CatalogItem(title, views, rating, releaseYear, relevance);
}

// Function to display the sorted catalog
void displayCatalog(const vector<CatalogItem>& catalog) {
    for (const auto& item : catalog) {
        cout << "Title: " << item.title
             << ", Views: " << item.totalViews
             << ", Rating: " << item.userRating
             << ", Release Year: " << item.releaseYear
             << ", Relevance Score: " << item.relevanceScore << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Generate a large number of catalog items for simulation
    int numItems = 1000000;  // Example: 1 million items in the catalog
    vector<CatalogItem> catalog;

    for (int i = 0; i < numItems; ++i) {
        catalog.push_back(generateRandomCatalogItem(i));
    }

    // Simulate a user (we can add a personalized relevance score based on user history)
    // In a real application, this score would be dynamically calculated based on the user's viewing history
    for (auto& item : catalog) {
        item.relevanceScore += (rand() % 500);  // Add some random personalized relevance
    }

    // Measure time taken for sorting
    clock_t start = clock();

    // Sort the catalog items based on multiple criteria (Quick Sort)
    quickSort(catalog, 0, catalog.size() - 1);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken to sort " << numItems << " catalog items: " << duration << " seconds" << endl;

    // Optionally, display the sorted catalog (printing millions of items might not be feasible)
    // displayCatalog(catalog); // Uncomment to print the sorted catalog

    return 0;
}
