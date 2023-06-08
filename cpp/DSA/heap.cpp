#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {60, 20, 40, 70, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int choice;
    while (true) {
        cout << "------ Menu ------" << endl;
        cout << "1. Heapify the array" << endl;
        cout << "2. Sort the array" << endl;
        cout << "3. Print the array" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = n / 2 - 1; i >= 0; i--) {
                    heapify(arr, n, i);
                }
                cout << "Array heapified successfully!" << endl;
                break;
            case 2:
                heapSort(arr, n);
                cout << "Array sorted successfully!" << endl;
                break;
            case 3:
                cout << "Array elements: ";
                printArray(arr, n);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
