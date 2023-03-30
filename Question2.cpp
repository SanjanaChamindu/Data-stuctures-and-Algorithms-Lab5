#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100000;  // maximum size of the input array

void running_median(int a[], int n) {
    priority_queue<int> max_heap;  // stores the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> min_heap;  // stores the larger half of the numbers
    double median = 0.0;  // current median

    for (int i = 0; i < n; i++) {
        if (max_heap.empty() || a[i] <= max_heap.top()) {
            max_heap.push(a[i]);  // add to max heap
        }
        else {
            min_heap.push(a[i]);  // add to min heap
        }

        // balance the heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        // update the median
        if (max_heap.size() == min_heap.size()) {
            median = (max_heap.top() + min_heap.top()) / 2.0;
        }
        else if (max_heap.size() > min_heap.size()) {
            median = max_heap.top();
        }
        else {
            median = min_heap.top();
        }

        // print the current median
        cout << fixed << setprecision(1) << median << endl;
    }
}

int main() {
    int a[] = { 7, 3, 5, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    running_median(a, n);
    return 0;
}
