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

