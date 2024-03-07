#include "CMovie_Info.h"

schedule_table::schedule_table() {}

schedule_table::schedule_table(int zone_num, schedule movie_schedule) {
    m_zone_num = zone_num;
    m_movie_schedule = movie_schedule;
}

int schedule_table::get_m_zone_num() {
    return this->m_zone_num;
}

schedule schedule_table::get_m_movie_schedule() {
    return this->m_movie_schedule;
}

void schedule_table::set_m_zone_num(int zone_num) {
    this->m_zone_num = zone_num;
}

void schedule_table::set_m_movie_schedule(schedule movie_schedule) {
    this->m_movie_schedule = movie_schedule;
}

CMovie_Info::CMovie_Info(std::string name, int num) : m_moviename(name), m_schedule_num(num) {
    m_schedule = new schedule_table[m_schedule_num];
}

CMovie_Info::CMovie_Info(const CMovie_Info& movie_info) : m_schedule_num(movie_info.get_m_schedule_num()) {
    m_schedule = new schedule_table[m_schedule_num];
    memcpy(m_schedule, movie_info.get_movie_schedule(), movie_info.get_m_schedule_num());
    m_moviename = movie_info.get_movie_name();
}

CMovie_Info::CMovie_Info() {
    m_schedule = 0;
    m_schedule_num = 0;
    m_moviename = "";
}


const CMovie_Info& CMovie_Info::operator=(const CMovie_Info& movie_info) {
    if (this != &movie_info) {
        memcpy(m_schedule, movie_info.get_movie_schedule(), movie_info.get_m_schedule_num());
        m_moviename = movie_info.get_movie_name();
    }
    return *this;
}

std::string CMovie_Info::get_movie_name() const {
    return this->m_moviename;
}

schedule_table* CMovie_Info::get_movie_schedule() const {
    return this->m_schedule;
}

int CMovie_Info::get_m_schedule_num() const {
    return this->m_schedule_num;
}

void CMovie_Info::set_movie_name(std::string name) {
    this->m_moviename = name;
}

void CMovie_Info::set_movie_schedule(schedule_table* table) {
    this->m_schedule = table;
}
CMovie_Info::~CMovie_Info() { delete[] this->m_schedule; }