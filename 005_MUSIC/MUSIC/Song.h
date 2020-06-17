#pragma once
#include <iostream>
#include <string>


class Song
{
public:
	Song(std::string title, std::string artist, std::string top_genre, int year);
	Song(int ID, std::string title, std::string artist, std::string top_genre, int year, int bpm, int nrgy, int dnce, int db, int live, int val, int dur, int acous, int spch, int pop);

	void set_title(std::string title);
	void set_artist(std::string artist);
	void set_top_genre(std::string top_genre);
	void set_year(int year);
	void set_bpm(int bpm);
	void set_nrgy(int nrgy);
	void set_dnce(int dnce);
	void set_db(int db);
	void set_live(int live);
	void set_val(int val);
	void set_dur(int dur);
	void set_acous(int acous);
	void set_spch(int spch);
	void set_pop(int pop);

	int get_ID();
	std::string get_title();
	std::string get_artist();
	std::string get_top_genre();
	int get_year();
	int get_bpm();
	int get_nrgy();
	int get_dnce();
	int get_db();
	int get_live();
	int get_val();
	int get_dur();
	int get_acous();
	int get_spch();
	int get_pop();

	std::string short_to_string();
	std::string all_to_string();
private:
	int ID;
	std::string title;
	std::string artist;
	std::string top_genre;
	int year;
	int bpm;
	int nrgy;
	int dnce;
	int db;
	int live;
	int val;
	int dur;
	int acous;
	int spch;
	int pop;
};

struct compareYear_Song
{
	bool operator() (Song& s1, Song& s2) {
		return s1.get_year() < s2.get_year();
	}
};

struct compareLetter_Song
{
	bool operator() (Song& s1, Song& s2) {

		if (s1.get_title()[0] == s2.get_title()[0])
		{
			return s1.get_year() < s2.get_year();
		}
		else
		{
			return s1.get_title() > s2.get_title();
		}
	}
};