#include "CAnalyze.h"
#include "Option.h"
#include <windows.h>

CAnalyze::CAnalyze(CZone* zones, CMovie_Info* movies) : m_zone_Info(zones), m_movies(movies) {}

void CAnalyze::set_movie_name(std::string title) {
	m_movie_name = title;
}

void CAnalyze::most_reserved_seat() {
	
}

void CAnalyze::how_much_movie_reserved() {
	int movies[MOVIES_NUM] = { 0,0,0,0 };
	

	for (int i = 0; i < ZONE_NUM; i++) {
		for (int j = 0; j < SCHEDULE_NUM; j++) {
			for (int k = 0; k < SEAT_ROW_NUM; k++) {
				for (int L = 0; L < SEAT_COL_NUM; L++) {         
					if (m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "어벤져스") {
						movies[0]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "소울") {
						movies[1]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "광해") {
						movies[2]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "어바웃 타임") {
						movies[3]++;
					}
					L++;
				}
				k++;
			}
		}
	}

	std::cout << "어벤져스 : " << movies[0] << "회\n";
	std::cout << "소울 : " << movies[1] << "회\n";
	std::cout << "광해 : " << movies[2] << "회\n";
	std::cout << "어바웃 타임 : " << movies[3] << "회\n";

}

void CAnalyze::how_much_gender_rserved() {
	int gender[2] = { 0,0 };



	for (int i = 0; i < ZONE_NUM; i++) {
		for (int j = 0; j < SCHEDULE_NUM; j++) {
			for (int k = 0; k < SEAT_ROW_NUM; k++) {
				for (int L = 0; L < SEAT_COL_NUM; L++) {
					if (this->m_zone_Info[i].get_seat_info(k, L, j).getgender() == 1) {
						gender[1]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L,j).isempty!=1&&this->m_zone_Info[i].get_seat_info(k, L, j).getgender() == 0) {
						gender[0]++;
					}
					L++;
				}
				k++;
			}
		}
	}
	std::cout << "남자 : " << gender[1] << "회\n";
	std::cout << "여자 : " << gender[0] << "회\n";
}

void CAnalyze::how_much_time_reserved() {
	int time[SCHEDULE_NUM] = { 0,0,0,0,0,0 };

	int row = 0, col = 0;

	for (int i = 0; i < ZONE_NUM; i++) {
		for (int j = 0; j < SCHEDULE_NUM; j++) {
			for (int k = 0; k < SEAT_ROW_NUM; k++) {
				for (int L = 0; L < SEAT_COL_NUM; L++) {
					if (this->m_zone_Info[i].get_seat_info(k, L, j).isempty == 0) {
						time[j]++;
					}
					L++;
				}
				k++;
			}
		}
	}
	std::cout << "8시 - 9시 : " << time[0] << "회\n";
	std::cout << "9시 - 10시 : " << time[1] << "회\n";
	std::cout << "10시 - 11시 : " << time[2] << "회\n";
	std::cout << "12시 - 1시 : " << time[3] << "회\n";
	std::cout << "1시 - 2시 : " << time[4] << "회\n";
	std::cout << "2시 - 3시 : " << time[5] << "회\n";
}
bool CAnalyze::start_analyzing() {

	std::cout << "1주일간의 좌석별 통계입니다." << std::endl;
	std::cout << "(1) 가장 많이 예매된 좌석 TOP3  (2) 영화별 가장 많이 예매된 좌석 TOP3" << std::endl;
	std::cout << "(3) 남녀별 가장 많이 예매된 좌석 TOP3  (4)  좌석별 세부 정보 출력" << std::endl;
	int choice2;
	std::cin >> choice2;
	switch (choice2)
	{
	case 1:
		most_reserved_seat();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		std::cout<<"[1] 영화별 예매 횟수  [2] 남녀 예매 비율  [3]  상영대별 예매 횟수"<<std::endl;
		int choice3;
		std::cin>>choice3;
		switch (choice3) {
			case 1:
				how_much_movie_reserved();
				Sleep(3000);
				break;
			case 2:
				how_much_gender_rserved();
				Sleep(3000);
				break;

			case 3:
				how_much_time_reserved();
				Sleep(3000);
				break;
		
		
		}
		break;
	
	}
	return true;
}