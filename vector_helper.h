#ifndef __VECTOR_HELPER_H__
#define __VECTOR_HELPER_H__

#include <vector>

template <typename T> T get_vector_value(std::vector<T> data, int index, T defValue)
{
    int maxValidIndex = data.size() - 1;

    return index >= 0 && index <= maxValidIndex
        ? data[index]
        : defValue;
}

#endif