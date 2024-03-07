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
					if (m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "�����") {
						movies[0]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "�ҿ�") {
						movies[1]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "����") {
						movies[2]++;
					}
					else if (this->m_zone_Info[i].get_seat_info(k, L, j).get_movie_name() == "��ٿ� Ÿ��") {
						movies[3]++;
					}
					L++;
				}
				k++;
			}
		}
	}

	std::cout << "����� : " << movies[0] << "ȸ\n";
	std::cout << "�ҿ� : " << movies[1] << "ȸ\n";
	std::cout << "���� : " << movies[2] << "ȸ\n";
	std::cout << "��ٿ� Ÿ�� : " << movies[3] << "ȸ\n";

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
	std::cout << "���� : " << gender[1] << "ȸ\n";
	std::cout << "���� : " << gender[0] << "ȸ\n";
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
	std::cout << "8�� - 9�� : " << time[0] << "ȸ\n";
	std::cout << "9�� - 10�� : " << time[1] << "ȸ\n";
	std::cout << "10�� - 11�� : " << time[2] << "ȸ\n";
	std::cout << "12�� - 1�� : " << time[3] << "ȸ\n";
	std::cout << "1�� - 2�� : " << time[4] << "ȸ\n";
	std::cout << "2�� - 3�� : " << time[5] << "ȸ\n";
}
bool CAnalyze::start_analyzing() {

	std::cout << "1���ϰ��� �¼��� ����Դϴ�." << std::endl;
	std::cout << "(1) ���� ���� ���ŵ� �¼� TOP3  (2) ��ȭ�� ���� ���� ���ŵ� �¼� TOP3" << std::endl;
	std::cout << "(3) ���ະ ���� ���� ���ŵ� �¼� TOP3  (4)  �¼��� ���� ���� ���" << std::endl;
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
		std::cout<<"[1] ��ȭ�� ���� Ƚ��  [2] ���� ���� ����  [3]  �󿵴뺰 ���� Ƚ��"<<std::endl;
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