#pragma once
#include "list_singly.hpp"

using namespace std;

typedef list_signly<uint32_t>::pNode pNodeI;

template <typename T> void sort_bobble(T &in, uint32_t size) {
    for (uint32_t i = size; i > 1; i--) {
        for (uint32_t j = 0; j < i - 1; j++) {
            if (in[j] > in[j + 1]) {
                swap(in[j], in[j + 1]);
            }
        }
    }
}

template <typename T> void sort_shell(T &in, uint32_t size) {
    for (uint32_t gap = size / 3; gap > 0; gap = gap / 3) {
        uint32_t remainder = size % gap;
        for (size_t i = 0; i < size - (gap + remainder); i++) {
            for (size_t j = i + gap; j < size; j += gap) {
                if (in[i] > in[j]) {
                    swap(in[i], in[j]);
                }
            }
        }
    }
}