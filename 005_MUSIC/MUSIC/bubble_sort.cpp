#include <iostream>
#include "bubble_sort.h"
using namespace std;


void bubble_sort(std::vector<Song> &data) {
	int n = 0;
	bool sortirano;
	for (int i = 0; i < data.size()-1; i++) {
		sortirano = true;
		for (int j = 0; j < data.size() - 1 - i; j++) { // Jer je ostatak liste sortiran.
			if (data[j].get_title() < data[j + 1].get_title()) {
				swap(data[j], data[j + 1]);
				sortirano = false;
				n++;
			}
		}

		if (sortirano) {
			std::cout << "Bubble swap: " << n << std::endl;
			break;
		}
	}
}