#ifndef __CMOVIEINFO__
#define __CMOVIEINFO__

#include <string>
#include <cstring>

/*
영화 정보
영화 제목, 상영관, 상영 시간에 대한 정보
*/

enum schedule {
    MORNING_1, MORNING_2, MORNING_3,
    AFTERNOON_1, AFTERNOON_2, AFTERNOON_3,
};


//  [상영관 번호, 상영시간]을 하나로 묶어서 관리함.
class schedule_table {
public:
    int m_zone_num;
    schedule m_movie_schedule;

    schedule_table(int zone_num, schedule movie_schedule);
    schedule_table();
    int get_m_zone_num();
    schedule get_m_movie_schedule();
    void set_m_zone_num(int zone_num);
    void set_m_movie_schedule(schedule movie_schedule);
};



class CMovie_Info {
private:
    std::string m_moviename;
    schedule_table* m_schedule;         //[상영관 번호, 상영시간]의 배열을 만들어서 영화 상영정보를 저장
    int m_schedule_num;           //위의 배열의 갯수를 저장하는 변수 즉 하루에 몇번 상영하는지

public:
    CMovie_Info(std::string name, int num);
    CMovie_Info(const CMovie_Info& movie_info);
    CMovie_Info();

    const CMovie_Info& operator=(const CMovie_Info& movie_info);
    std::string get_movie_name()const;
    schedule_table* get_movie_schedule() const;
    int get_m_schedule_num() const;

    void set_movie_name(std::string name);
    void set_movie_schedule(schedule_table* table);
    
    ~CMovie_Info();
};

#endif
