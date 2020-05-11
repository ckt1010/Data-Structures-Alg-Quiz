#pragma once
#include "list_singly.hpp"
#include <vector>

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

template <typename T> void sort_select(T &in, uint32_t size) {
    uint32_t loopCount = 0, swapCount = 0;
    for (uint32_t i = 0; i < size - 1; i++) {
        uint32_t minC = i;
        for (uint32_t j = i + 1; j < size; j++) {
            loopCount++;
            if (in[minC] > in[j]) {
                minC = j;
            }
        }

        if (minC != i) {
            swapCount++;
            /* swap */
            uint32_t tmp = in[minC];
            in[minC] = in[i];
            in[i] = tmp;
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

template <typename T>
uint32_t sort_insert(T &in, const uint32_t size, const uint32_t gap = 1,
                 const uint32_t offset = 0) {
    uint32_t loopCount = 0, swapCount = 0;
    int32_t j, i;
    for (i = gap + offset; i < size; i += gap) {
        uint32_t compareValue = in[i];
        for (j = i; j > offset; j -= gap) {
            loopCount++;
            if (in[j - gap] > compareValue) {
                swapCount++;
                in[j] = in[j - gap];
            } else {
                break;
            }
        }
        in[j] = compareValue;
    }
    return loopCount;
}

template <typename T> void sort_shell(T &in, const uint32_t size) {
    uint32_t loopCount = 0;
    uint32_t j;
    for (uint32_t gap = size / 3; gap > 0; gap = gap / 3) {
        for (uint32_t i = 0; i < gap; i++) {
            loopCount += sort_insert(in, size - i, gap, i);
        }
    }
    cout << "Loop time: " << loopCount << endl;
}

template <typename T>
void merge(T begin1, const uint32_t size1, T begin2,
           const uint32_t size2) {
    uint32_t q1 = size1 / 2, q2 = size2 / 2;
    if (q1 != 0) {
        merge(begin1, q1, begin1 + q1, size1 - q1);
    }

    if (q2 != 0) {
        merge(begin2, q2, begin2 + q2, size2 - q2);
    }

    //two array merge together
    vector<uint64_t> arryTmp(size1 + size2);
    size_t i1 = 0, i2 = 0;
    while (i1 < size1 && i2 < size2) {
        if (*(begin1 + i1) < *(begin2 + i2)) {
            arryTmp[i1 + i2] = *(begin1 + i1);
            i1++;
        } else {
            arryTmp[i1 + i2] = *(begin2 + i2);
            i2++;
        }
    }
    
    if(i1 != size1) {
        std::copy(begin1 + i1, begin1 + size1, arryTmp.begin() + i1 + i2);
        i1 = size1;
    }
    std::copy(arryTmp.begin(), arryTmp.begin() + i1 + i2, begin1);
}

template <typename T> void sort_merge(T &in, const uint32_t size) {
    uint32_t q = size / 2;
    merge(in.begin(), q, in.begin()+q, size-q);
}

template <typename T> void sort_quick(T &in, const uint32_t size) {
    uint32_t q = size / 2;
    merge_quick(in.begin(), q, in.begin()+q, size-q);
}