#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);  // Dummy node to simplify result construction
    ListNode* current = dummyHead;          // Pointer to build the result list
    int carry = 0;

    // Traverse both lists until both are exhausted
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;  // Start with the carry from the previous step

        if (l1 != nullptr) {
            sum += l1->val;  // Add value from the first list if available
            l1 = l1->next;   // Move to the next node in the first list
        }
        if (l2 != nullptr) {
            sum += l2->val;  // Add value from the second list if available
            l2 = l2->next;   // Move to the next node in the second list
        }

        // Calculate the new carry for the next iteration
        carry = sum / 10;

        // Create a new node for the current digit (sum mod 10)
        current->next = new ListNode(sum % 10);
        current = current->next;  // Move to the next node in the result list
    }

    // Return the next of the dummy head, which is the actual result list
    return dummyHead->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (int i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage:
    vector<int> num1 = {2, 4, 3};  // Represents the number 342 (in reverse order)
    vector<int> num2 = {5, 6, 4};  // Represents the number 465 (in reverse order)

    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);  // Expected output: 7 -> 0 -> 8 (which represents 807)

    return 0;
}
