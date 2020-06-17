#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "Song.h"
#include "Stopwatch.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "counting_sort.h"
#include "my_bogo_sort.h"

int convert_int(std::string& s)
{
	std::stringstream converter(s);
	int n;
	converter >> n;
	converter.ignore();
	return n;
}

void load(std::ifstream& projekt, std::vector<Song>& original) {

	std::string line;
	std::getline(projekt, line);
	while (std::getline(projekt, line))
	{
		std::stringstream ss(line);
		std::string temp;

		std::getline(std::getline(ss, temp, '"'), temp, '"');
		int ID = convert_int(temp);

		std::string title;
		//std::getline(std::getline(ss, temp, '"'), title, '"');  //nije dobar, ima u title jos navodnika
		//maknut samo prvi i zadnji navodnik u title
		std::getline(ss, temp, '"');
		std::getline(ss, temp, ',');
		while (true)
		{
			title += temp;
			if ('"' != temp.back())
			{
				
				std::getline(ss, temp, ',');
			}
			else
			{
				break;
			}
		}
		title.pop_back();

		std::string artist;
		std::getline(std::getline(ss, temp, '"'), artist, '"');

		std::string top_genre;
		std::getline(std::getline(ss, temp, '"'), top_genre, '"');

		std::getline(ss, temp, ',');
		std::getline(ss, temp, ',');
		int year = convert_int(temp);

		std::getline(ss, temp, ',');
		int bpm = convert_int(temp);

		std::getline(ss, temp, ',');
		int nrgy = convert_int(temp);

		std::getline(ss, temp, ',');
		int dnce = convert_int(temp);

		std::getline(ss, temp, ',');
		int db = convert_int(temp);

		std::getline(ss, temp, ',');
		int live = convert_int(temp);

		std::getline(ss, temp, ',');
		int val = convert_int(temp);

		std::getline(ss, temp, ',');
		int dur = convert_int(temp);

		std::getline(ss, temp, ',');
		int acous = convert_int(temp);

		std::getline(ss, temp, ',');
		int spch = convert_int(temp);

		std::getline(ss, temp);
		int pop = convert_int(temp);

		original.emplace_back(ID, title, artist, top_genre, year, bpm, nrgy, dnce, db, live, val, dur, acous, spch, pop);
	}
	//Test ispis
	/*for (auto it = original.begin(); it != original.end(); ++it)
	{
		std::cout << it->all_to_string() << std::endl;
	}
	std::cout << std::endl;*/
}


//ISHOD 3
void funkcionalnost33_34(std::vector<Song> &original) {
	
	std::multimap<std::string, Song> mm;

	for (auto it = original.begin(); it != original.end(); ++it)
	{
		mm.emplace(it->get_top_genre(), *it);
	}

	std::string zanr;
	std::cout << "Unesite zanr: ";
	std::getline(std::cin, zanr);

	Stopwatch t_mm;
	t_mm.begin();
	auto fast = mm.find(zanr);
	t_mm.end();

	auto found = mm.equal_range(zanr);
	if (found.first != found.second)
	{
		for (auto it = found.first; it != found.second; ++it)
		{
			std::cout << it->second.all_to_string() << std::endl;
		}
	}
	else
	{
		std::cout << std::endl << "Ne postoji taj zanr!" << std::endl;
	}

	std::cout << std::endl;

	std::list<Song> l(original.begin(), original.end());
	std::vector<Song> v(original.begin(), original.end());

	Stopwatch t_l;
	t_l.begin();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		if (it->get_top_genre() == zanr)
		{
			break;
		}
	}
	t_l.end();

	std::cout << std::endl;

	Stopwatch t_v;
	t_v.begin();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (it->get_top_genre() == zanr)
		{
			break;
		}
	}
	t_v.end();

	if (t_mm.elapsed_time() <= t_l.elapsed_time() && t_mm.elapsed_time() <= t_v.elapsed_time())
	{
		std::cout << "Multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
		if (t_l.elapsed_time() <= t_v.elapsed_time())
		{
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
		}
		else
		{
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
		}
	}
	else if (t_l.elapsed_time() <= t_mm.elapsed_time() && t_l.elapsed_time() <= t_v.elapsed_time())
	{
		std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
		if (t_mm.elapsed_time() <= t_v.elapsed_time())
		{
			std::cout << "Multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
		}
		else
		{
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
			std::cout << "Multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
		}
	}
	else
	{
		std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
		if (t_mm.elapsed_time() <= t_l.elapsed_time())
		{
			std::cout << "Multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
		}
		else
		{
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
			std::cout << "Multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
		}
	}
}

void funkcionalnost35(std::vector<Song>& original) {

	std::priority_queue<Song, std::vector<Song>, compareYear_Song> pq(original.begin(), original.end());

	while (!pq.empty())
	{
		auto it = pq.top();
		std::cout << it.short_to_string() << std::endl;
		pq.pop();
	}
}

void funkcionalnost36(std::vector<Song>& original) {
	std::multimap<int, Song> mp;
	std::list<Song> l;

	for (auto it = original.begin(); it != original.end(); ++it)
	{
		mp.emplace(it->get_year(), *it);
	}

	bool da;
	do
	{
	int godina;
	std::cout << "Unesite godinu izdanja: ";
	std::cin >> godina;

	auto found = mp.equal_range(godina);
	if (found.first != found.second)
	{
		for (auto it = found.first; it != found.second; ++it)
		{
			l.emplace_back(it->second);
		}
		std::cout << "Uneseno!" << std::endl;
	}
	else
	{
		std::cout << "Ne postoji ta godina!" << std::endl;
	}

	std::cout << "Zelite li unijeti jos godina? (1 = DA / 0 = NE): ";
	std::cin >> da;
	} while (da);

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		std::cout << it->short_to_string() << std::endl;
	}

}

void funkcionalnost37(std::vector<Song>& original) {

	std::priority_queue<Song, std::vector<Song>, compareLetter_Song> pq(original.begin(), original.end());

	while (!pq.empty())
	{
		auto it = pq.top();
		std::cout << it.short_to_string() << std::endl;
		pq.pop();
	}
}


//ISHOD 4
void funkcionalnost42_43(std::vector<Song>& original) {

	std::vector<Song> v1(original.begin(), original.end());
	std::vector<Song> v2(original.begin(), original.end());

	Stopwatch t_bubble;
	t_bubble.begin();
	bubble_sort(v1);
	/*for (auto it = v1.begin(); it != v1.end(); ++it)
	{
		std::cout << it->short_to_string() << std::endl;
	}*/
	t_bubble.end();
	std::cout << "Bubble vrijeme: " << t_bubble.elapsed_time() << "us" << std::endl;

	Stopwatch t_selection;
	t_selection.begin();
	selection_sort(v2);
	/*for (auto it = v2.begin(); it != v2.end(); ++it)
	{
		std::cout << it->short_to_string() << std::endl;
	}*/
	t_selection.end();
	std::cout << "Selection vrijeme: " << t_selection.elapsed_time() << "us" << std::endl;


}

void funkcionalnost44() {

	srand(time(nullptr));
	int value;
	std::cout << "Unesite koliko mikrosekundi mislite da ce trajati" << std::endl;
	std::cout << "razbacivanje, sortiranje i binarno pretrazivanje" << std::endl;
	std::cout << "tog vektora u potrazi za brojem 13: ";
	std::cin >> value;

	unsigned long long n = rand() % 100000001;

	Stopwatch time;
	time.begin();
	std::vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	std::random_shuffle(v.begin(), v.end());
	std::sort(v.begin(), v.end());
	std::binary_search(v.begin(), v.end(), 13);
	time.end();
	std::cout << "Vrijeme potrage: " << time.elapsed_time() << "us" << std::endl;
	if (time.elapsed_time() < value)
	{
	std::cout << "Razlika: " << value - time.elapsed_time() << "us" << std::endl;
	}
	else if (time.elapsed_time() > value)
	{
		std::cout << "Razlika: " << time.elapsed_time() - value << "us" << std::endl;
	}
	else
	{
		std::cout << "Razlika: " << "0us" << std::endl;
		std::cout << "BRAVO!" << std::endl;
	}
}

void funkcionalnost45(std::vector<Song> &original) {

	std::vector<Song> vec(original.begin(), original.end());
	std::random_shuffle(vec.begin(), vec.end());
	std::vector<Song> b(vec.begin(), vec.begin() + 6);
	my_bogo_sort(b);
	for (auto it = b.begin(); it != b.end(); ++it)
	{
		std::cout << it->short_to_string() << std::endl;
	}

}

void funkcionalnost46() {

	srand(time(nullptr));

	int n;
	std::cout << "Unesite broj: ";
	std::cin >> n;

	std::vector<int> v;

	for (int i = 1; i <= 100000; i++)
	{
		v.push_back((rand() % n+1));
	}

	std::cout << "Counting, please wait..." << std::endl;
	counting_sort(v);
	std::cout << "Datoteka napravljena!" << std::endl;
}


//ISHOD 5
void funkcionalnost52_53(std::vector<Song>& original) {

	std::unordered_multimap<int, Song> mm;

	for (auto it = original.begin(); it != original.end(); ++it)
	{
		mm.emplace(it->get_year(), *it);
	}

	int godina;
	std::cout << "Unesite godinu: ";
	std::cin >> godina;

	Stopwatch t_mm;
	t_mm.begin();
	auto fast = mm.find(godina);
	t_mm.end();

	auto found = mm.equal_range(godina);
	if (found.first != found.second)
	{
		for (auto it = found.first; it != found.second; ++it)
		{
			std::cout << it->second.all_to_string() << std::endl;
		}
	}
	else
	{
		std::cout << std::endl << "Ne postoji ta godina!" << std::endl;
	}

	std::cout << std::endl;

	std::list<Song> l(original.begin(), original.end());
	std::vector<Song> v(original.begin(), original.end());

	Stopwatch t_l;
	t_l.begin();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		if (it->get_year() == godina)
		{
			break;
		}
	}
	t_l.end();

	std::cout << std::endl;

	Stopwatch t_v;
	t_v.begin();
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (it->get_year() == godina)
		{
			break;
		}
	}
	t_v.end();

	if (t_mm.elapsed_time() <= t_l.elapsed_time() && t_mm.elapsed_time() <= t_v.elapsed_time())
	{
		std::cout << "Unordered multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
		if (t_l.elapsed_time() <= t_v.elapsed_time())
		{
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
		}
		else
		{
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
		}
	}
	else if (t_l.elapsed_time() <= t_mm.elapsed_time() && t_l.elapsed_time() <= t_v.elapsed_time())
	{
		std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
		if (t_mm.elapsed_time() <= t_v.elapsed_time())
		{
			std::cout << "Unordered multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
		}
		else
		{
			std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
			std::cout << "Unordered multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
		}
	}
	else
	{
		std::cout << "Vector time: " << t_v.elapsed_time() << "us" << std::endl;
		if (t_mm.elapsed_time() <= t_l.elapsed_time())
		{
			std::cout << "Unordered multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
		}
		else
		{
			std::cout << "List time: " << t_l.elapsed_time() << "us" << std::endl;
			std::cout << "Unordered multimap time: " << t_mm.elapsed_time() << "us" << std::endl;
		}
	}
}

void funkcionalnost54(std::vector<Song>& original) {

	std::unordered_multimap<std::string, Song> mm;

	for (auto it = original.begin(); it != original.end(); ++it)
	{
		mm.emplace(it->get_artist(), *it);
	}

	std::ofstream dat("funkcionalnost54.txt");
	if (!dat)
	{
		std::cout << "Greska pri kreiranju datoteke." << std::endl;
		return;
	}

	for (int i = 0; i < mm.bucket_count(); i++)
	{
		dat << "Bucket " << i << ": ";
		for (auto it = mm.begin(i); it != mm.end(i);) {
			dat << it->second.get_title();
			++it;
			if (it != mm.end(i))
			{
				dat << " -- ";
			}
		}
		if (!mm.bucket_size(i))
		{
			dat << "[EMPTY]";
		}
		dat << std::endl;
	}
	dat.close();
	std::cout << "Datoteka napravljena!" << std::endl;
}

void funkcionalnost55(std::vector<Song>& original) {

	std::unordered_multimap<std::string, Song> mm;
	for (auto it = original.begin(); it != original.end(); ++it)
	{
		mm.emplace(it->get_title(), *it);
	}

	std::string title;	//Elastic Heart ; Castle Walls (feat. Christina Aguilera)
	std::cout << "Odaberite naslov pjesme: ";
	std::getline(std::cin, title);
	auto found = mm.equal_range(title);
	if (found.first != found.second)
	{
		std::transform(title.begin(), title.end(), title.begin(), ::toupper);

		for (auto it = found.first; it != found.second; ++it)
		{
			int c = 0;
			std::string str = it->second.get_artist();
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			for (int i = 0; i < title.size(); i++)
			{
				if (str[c] == title[i])
				{
					c++;
				}
				if (str.size()-1 == c)
				{
					std::cout << "Ime " << it->second.get_artist() << " se moze kreirati iz naslova " << it->first << std::endl;
					break;
				}
			}
			if (str.size() - 1 != c)
			{
				std::cout << "Ime " << it->second.get_artist() << " se ne moze kreirati iz naslova " << it->first << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Ne postoji taj naslov" << std::endl;
	}
}


int main() {

	std::vector<Song> original;

	std::ifstream projekt("SPA_PROJ_005_MUSIC_data.csv");
	if (!projekt)
	{
		std::cout << "Dogodila se greska.\n";
		return 1;
	}

	load(projekt, original);
	projekt.close();

	bool da;
	do
	{
		std::cout << "ISHOD 3\n";
		std::cout << "(1) Pretraga po zanru\n";
		std::cout << "(2) Prikaz po godini\n";
		std::cout << "(3) Kopiranje u novu listu\n";
		std::cout << "(4) Prikaz po prvom slovu\n\n";

		std::cout << "ISHOD 4\n";
		std::cout << "(5) Selection vs Bubble\n";
		std::cout << "(6) What will the number be\n";
		std::cout << "(7) Randomness\n";
		std::cout << "(8) Sortiranje brojanjem\n\n";

		std::cout << "ISHOD 5\n";
		std::cout << "(9) Pretraga po godini\n";
		std::cout << "(10) Vizualiziraj\n";
		std::cout << "(11) Izrada imena iz imena\n\n";
		
		int odabir;
		std::cout << "Odaberite: ";
		std::cin >> odabir;
		std::cin.ignore();

		switch (odabir)
		{
		case 1:
			funkcionalnost33_34(original);
			break;
		case 2:
			funkcionalnost35(original);
			break;
		case 3:
			funkcionalnost36(original);
			break;
		case 4:
			funkcionalnost37(original);
			break;

		case 5:
			funkcionalnost42_43(original);
			break;
		case 6:
			funkcionalnost44();
			break;
		case 7:
			funkcionalnost45(original);
			break;
		case 8:
			funkcionalnost46();
			break;

		case 9:
			funkcionalnost52_53(original);
			break;
		case 10:
			funkcionalnost54(original);
			break;
		case 11:
			funkcionalnost55(original);
			break;
		default:
			std::cout << "Krivi unesen broj!" << std::endl;
			break;
		}
		std::cout << std::endl;
		std::cout << "Zelite li jos funkcionalnosti? (1 = DA / 0 = NE): ";
		std::cin >> da;
		system("cls");
	} while (da);

	std::cout << "HVALA!\n" << "Napravio: Ivan Jakovic [1RP6]";

	return 0;
}