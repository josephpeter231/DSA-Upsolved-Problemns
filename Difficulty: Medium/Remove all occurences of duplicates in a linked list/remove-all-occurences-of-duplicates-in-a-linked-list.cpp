//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
public:
    Node* removeAllDuplicates(Node* head) {
        if (!head) return nullptr;

        // First pass: Count occurrences of each value
        Node* temp = head;
        std::unordered_map<int, int> up;
        while (temp != nullptr) {
            up[temp->data]++;
            temp = temp->next;
        }

        // Dummy node to simplify edge case handling
        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        temp = head;

        // Second pass: Remove duplicates
        while (temp != nullptr) {
            if (up[temp->data] > 1) {
                // Skip the current node
                prev->next = temp->next;
            } else {
                // Move prev forward if not a duplicate
                prev = temp;
            }
            temp = temp->next;
        }

        return dummy.next;
    }
};


//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends