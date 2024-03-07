#ifndef __CMOVIEINFO__
#define __CMOVIEINFO__

#include <string>
#include <cstring>

/*
��ȭ ����
��ȭ ����, �󿵰�, �� �ð��� ���� ����
*/

enum schedule {
    MORNING_1, MORNING_2, MORNING_3,
    AFTERNOON_1, AFTERNOON_2, AFTERNOON_3,
};


//  [�󿵰� ��ȣ, �󿵽ð�]�� �ϳ��� ��� ������.
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
    schedule_table* m_schedule;         //[�󿵰� ��ȣ, �󿵽ð�]�� �迭�� ���� ��ȭ �������� ����
    int m_schedule_num;           //���� �迭�� ������ �����ϴ� ���� �� �Ϸ翡 ��� ���ϴ���

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
