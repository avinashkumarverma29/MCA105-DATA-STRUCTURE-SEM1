#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) throw underflow_error("Queue is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    int top() {
        if (heap.empty()) throw underflow_error("Queue is empty");
        return heap[0];
    }

    bool empty() { return heap.empty(); }
};

int main() {
    PriorityQueue pq;
    pq.push(15);
    pq.push(40);
    pq.push(25);
    pq.push(10);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}