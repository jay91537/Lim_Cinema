#ifndef __CANALYZE__
#define __CANALYZE__

#include <string>
#include <iostream>
#include "CMovie_Info.h"
#include "CPerson_Info.h"
#include "Option.h"
#include "CZone.h"
#include <cstring>


class CAnalyze {
private:
	CZone* m_zone_Info;
	CMovie_Info* m_movies;
	int m_movie_time;
	int m_movie_zone;
	std::string m_movie_name;


public:
	CAnalyze(CZone* zones, CMovie_Info* movies);

	std::string get_movie_name() const;
	int get_movie_time() const;
	int get_movie_zone() const;
	CZone* get_zone_info() const;
	CMovie_Info* get_m_movies() const;

	bool start_analyzing();
	void set_movie_name(std::string title);

	void most_reserved_seat();
	void most_reserved_seat_by_movie();
	void most_reserved_seat_by_gender();

	void how_much_movie_reserved();
	void how_much_gender_rserved();
	void how_much_time_reserved();


};










#endif