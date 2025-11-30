#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
public:
    vector<int> heap;

    // Function to swap two values
    void swapVals(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Push an element (insert)
    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Up-heap bubbling
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swapVals(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    // Pop the highest priority element
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }

        // Move last element to root
        heap[0] = heap.back();
        heap.pop_back();

        // Down-heap trickle
        heapify(0);
    }

    // Heapify function (max-heap)
    void heapify(int i) {
        int size = heap.size();
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swapVals(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // Return highest priority element
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty.\n";
            return -1;
        }
        return heap[0];
    }

    // Display the heap
    void display() {
        if (heap.empty()) {
            cout << "Priority Queue is empty.\n";
            return;
        }
        cout << "Priority Queue (Heap): ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, val;

    while (true) {
        cout << "\n--- PRIORITY QUEUE MENU ---\n";
        cout << "1. Insert (Push)\n";
        cout << "2. Delete Highest Priority (Pop)\n";
        cout << "3. Peek (Top Element)\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            pq.push(val);
            break;

        case 2:
            pq.pop();
            break;

        case 3:
            cout << "Top element: " << pq.top() << endl;
            break;

        case 4:
            pq.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
