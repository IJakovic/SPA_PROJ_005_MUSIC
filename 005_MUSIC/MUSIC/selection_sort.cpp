#include <iostream>
#include "selection_sort.h"
using namespace std;


void selection_sort(std::vector<Song>& data) {
	int ss = 0;
	for (int i = 0; i < data.size() - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < data.size(); j++) {
			if (data[j].get_title() > data[min_index].get_title()) {
				min_index = j;
			}
		}
		swap(data[min_index], data[i]);
		ss++;
	}
	std::cout << "Selection swap: " << ss << std::endl;
}