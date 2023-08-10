#include <bits/stdc++.h>

using namespace std;

auto compare = [](const int v1, const int v2) {
    return v1 > v2;
};

class MedianFinder {
public:
    MedianFinder() {
        maxHeap = new int[50000];
        minHeap = new int[50000];
        maxSize = 0;
        minSize = 0;
    }

    ~MedianFinder() {
        delete[] maxHeap;
        delete[] minHeap;
    }

    void addNum(int num) {
        if (maxSize == 0 || num <= maxHeap[0]) {
            maxHeap[maxSize++] = num;
            push_heap(maxHeap, maxHeap + maxSize);
        } else {
            minHeap[minSize++] = num;
            push_heap(minHeap, minHeap + minSize, compare);
        }

        if (maxSize > minSize + 1) {
            minHeap[minSize++] = maxHeap[0];
            push_heap(minHeap, minHeap + minSize, compare);
            pop_heap(maxHeap, maxHeap + maxSize--);
        } else if (minSize > maxSize) {
            maxHeap[maxSize++] = minHeap[0];
            push_heap(maxHeap, maxHeap + maxSize);
            pop_heap(minHeap, minHeap + minSize--, compare);
        }
    }

    double findMedian() {
        return minSize == maxSize ? (double)(maxHeap[0] + minHeap[0]) / 2 : maxHeap[0];
    }

private:
    int *maxHeap, *minHeap;
    int maxSize, minSize;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */