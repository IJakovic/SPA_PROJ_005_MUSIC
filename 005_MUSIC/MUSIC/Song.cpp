#include "Song.h"
#include <sstream>
#include <cctype>


Song::Song(std::string title, std::string artist, std::string top_genre, int year)
{
	set_title(title);
	set_artist(artist);
	set_top_genre(top_genre);
	set_year(year);
}

Song::Song(int ID, std::string title, std::string artist, std::string top_genre, int year, int bpm, int nrgy, int dnce, int db, int live, int val, int dur, int acous, int spch, int pop)
	: Song(title, artist, top_genre, year)
{
	this->ID = ID;
	set_bpm(bpm);
	set_nrgy(nrgy);
	set_dnce(dnce);
	set_db(db);
	set_live(live);
	set_val(val);
	set_dur(dur);
	set_acous(acous);
	set_spch(spch);
	set_pop(pop);
}

//Setteri
void Song::set_title(std::string title)			{ this->title = title; }
void Song::set_artist(std::string artist)		{ this->artist = artist; }
void Song::set_top_genre(std::string top_genre) { this->top_genre = top_genre; }
void Song::set_year(int year)					{ this->year = year; }
void Song::set_bpm(int bpm)						{ this->bpm = bpm; }
void Song::set_nrgy(int nrgy)					{ this->nrgy = nrgy; }
void Song::set_dnce(int dnce)					{ this->dnce = dnce; }
void Song::set_db(int db)						{ this->db = db; }
void Song::set_live(int live)					{ this->live = live; }
void Song::set_val(int val)						{ this->val = val; }
void Song::set_dur(int dur)						{ this->dur = dur; }
void Song::set_acous(int acous)					{ this->acous = acous; }
void Song::set_spch(int spch)					{ this->spch = spch; }
void Song::set_pop(int pop)						{ this->pop = pop; }

//Getteri
int Song::get_ID()					{ return ID; }

std::string Song::get_title() { 

	if (!isupper(title[0]))
	{
		title[0] = toupper(title[0]);
	}
	return title;
}

std::string Song::get_artist()		{ return artist; }
std::string Song::get_top_genre()	{ return top_genre; }
int Song::get_year()				{ return year; }
int Song::get_bpm()					{ return bpm; }
int Song::get_nrgy()				{ return nrgy; }
int Song::get_dnce()				{ return dnce; }
int Song::get_db()					{ return db; }
int Song::get_live()				{ return live; }
int Song::get_val()					{ return val; }
int Song::get_dur()					{ return dur; }
int Song::get_acous()				{ return acous; }
int Song::get_spch()				{ return spch; }
int Song::get_pop()					{ return pop; }

std::string Song::short_to_string()
{
	std::stringstream ss;
	ss << year << ", " << title;
	return ss.str();
}

std::string Song::all_to_string()
{
	std::stringstream ss;
	ss 
		<< ID << ", " 
		<< title << ", " 
		<< artist << ", " 
		<< top_genre << ", " 
		<< year << ", " 
		<< bpm << ", " 
		<< nrgy << ", " 
		<< dnce << ", " 
		<< db << ", " 
		<< live << ", " 
		<< val << ", " 
		<< dur << ", " 
		<< acous << ", " 
		<< spch << ", " 
		<< pop;
	return ss.str();
}
