#include "my_bogo_sort.h"
#include <iostream>
#include <algorithm>

bool is_sorted(std::vector<Song>& data) {

    for (int i = 1; i < data.size(); ++i)
    {
        if (data[i].get_title() > data[i - 1].get_title())
        {
            return false;
        }
    }
    return true;
}


void my_bogo_sort(std::vector<Song>& data) {

    int n = 0;
    while (!is_sorted(data))
    {
        n++;
        std::random_shuffle(data.begin(), data.end());
    }
    std::cout << "Bogo swap: " << n << std::endl;
}