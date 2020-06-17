#include <iostream>
#include <fstream>
#include "counting_sort.h"
using namespace std;

int max_element(std::vector<int> &data) {
	int max = data[0];
	for (int i = 1; i < data.size(); i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	return max;
}

int* napravi_polje(int n) {
	int* polje = new int[n];
	for (int i = 0; i < n; i++) {
		polje[i] = 0;
	}
	return polje;
}

void prebroji_ponavljanje(std::vector<int> &data, int* sljedeci_indeks, int max) {

	std::ofstream dat("funkcionalnost46.txt");
	if (!dat)
	{
		std::cout << "Greska pri kreiranju datoteke.";
		return;
	}

	int element;
	for (int i = 0; i < data.size(); i++) {
		element = data[i];

		//
		for (int j = 0; j < max; j++)
		{
			dat << sljedeci_indeks[j] << " ";
		}
		dat << std::endl;
		//

		sljedeci_indeks[element]++;
	}

	for (int j = 0; j < max; j++)
	{
		dat << sljedeci_indeks[j] << " ";
	}
	dat.close();
}

void pretvori_ponavljanje_u_indekse(int* sljedeci_indeks, int n) {
	sljedeci_indeks[0]--;
	for (int i = 1; i < n; i++) {
		sljedeci_indeks[i] += sljedeci_indeks[i - 1];
	}
}

void prepisi_u_sortirano(std::vector<int> &data, int* sljedeci_indeks, int* sortirano) {
	for (int i = data.size() - 1; i >= 0; i--) {
		int element = data[i];
		int stavi_na_indeks = sljedeci_indeks[element]--;
		sortirano[stavi_na_indeks] = element;
	}
}

void prekopiraj(int* sortirano, std::vector<int> &data) {
	for (int i = 0; i < data.size(); i++) {
		data[i] = sortirano[i];
	}
}

void counting_sort(std::vector<int> &data) {
	// Pronalazak najveæeg elementa.
	int max = max_element(data);
	
	// Priprema polja za èuvanje podataka o broju ponavljanja i indeksima na koje doðu sortirani elementi.
	int* sljedeci_indeks = napravi_polje(max + 1);

	// Pomoæno polje koje æe sadržavati sortirane podatke.
	int* sortirano = napravi_polje(data.size());

	// Brojanje ponavljanja.
	prebroji_ponavljanje(data, sljedeci_indeks, max+1);

	// Pretvaranje broja pojavljivanja u indekse sortiranog polja. Trenutno nam sljedeci_indeks sadržava BROJ PONAVLJANJA, a nakon petlje æe sadržavati INDEKSE u sortiranom polju.
	pretvori_ponavljanje_u_indekse(sljedeci_indeks, max + 1);

	// Smještanje elemenata u sortirano polje na izraèunate indekse.
	prepisi_u_sortirano(data, sljedeci_indeks, sortirano);
	
	// Kopiranje iz pomoænog u glavno.
	prekopiraj(sortirano, data);
	
	delete[] sljedeci_indeks;
	delete[] sortirano;
}
