#pragma once
#include "list_singly.hpp"

using namespace std;

typedef list_signly<uint32_t>::pNode pNodeI;

template <typename T> void sort_bobble(T &in, uint32_t size) {
    uint32_t loopCount = 0, swapCount = 0;
    for (uint32_t i = size; i > 1; i--) {
        for (uint32_t j = 0; j < i - 1; j++) {
            loopCount++;
            if (in[j] > in[j + 1]) {
                swap(in[j], in[j + 1]);
                swapCount++;
            }
        }
    }
    cout << "Loop time: " << loopCount << " , Swap time: " << swapCount << endl;
}

template <typename T> void sort_bobble1(T &in, uint32_t size) {
    uint32_t loopCount = 0, swapCount = 0;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            loopCount++;
            if (in[i] > in[j]) {
                swap(in[i], in[j]);
                swapCount++;
            }
        }
    }
    cout << "Loop time: " << loopCount << " , Swap time: " << swapCount << endl;
}

template <typename T> void sort_insert(T &in, uint32_t size) {
    uint32_t loopCount = 0, swapCount = 0;
    int32_t j, i;
    for (i = 1; i < size; i++) {
        uint32_t compareValue = in[i];
        for (j = i; j > 0; j--) {
            loopCount++;
            if (in[j - 1] > compareValue) {
                swapCount++;
                in[j] = in[j - 1];
            } else {
                break;
            }
        }
        in[j] = compareValue;
    }
    cout << "Loop time: " << loopCount << " , Swap time: " << swapCount << endl;
}


template <typename T> void sort_shell(T &in, uint32_t size) {
    uint32_t loopCount = 0, swapCount = 0;
    for (uint32_t gap = size / 3; gap > 0; gap = gap / 3) {
        uint32_t remainder = size % gap;
        for (size_t i = 0; i < size - (gap + remainder); i++) {
            for (size_t j = i + gap; j < size; j += gap) {
                loopCount++;
                if (in[i] > in[j]) {
                    swap(in[i], in[j]);
                    swapCount++;
                }
            }
        }
    }
    cout << "Loop time: " << loopCount << " , Swap time: " << swapCount << endl;
}