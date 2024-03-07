
#include "CReserve.h"
#include "Option.h"


CReserve::CReserve(CZone* zones, CMovie_Info* movies) :m_zone_info(zones), m_movies(movies) {}

void CReserve::set_movie_name(std::string title) {
	m_movie_name = title;
}

//복사생성자
/*
CReserve::CReserve(const CReserve& reserve) {
	m_movie_name = reserve.get_movie_name();
	m_movie_time = reserve.get_movie_time();
	m_movie_zone = reserve.get_movie_zone();

	memcpy(m_zone_info, reserve.get_zone_info(), ZONE_NUM);
	memcpy(m_movies, reserve.get_m_movies(), MOVIES_NUM);

}
*/
std::string CReserve::get_movie_name() const {
	return m_movie_name;
}
int CReserve::get_movie_time() const {
	return m_movie_time;
}
int CReserve::get_movie_zone() const {
	return m_movie_zone;
}
CZone* CReserve::get_zone_info() const {
	return (CZone*)m_zone_info;
}
CMovie_Info* CReserve::get_m_movies() const {
	return (CMovie_Info*)m_movies;
}



bool CReserve::reserve(CPerson_Info& customer)
{
	for (int i = 0; i < MOVIES_NUM; i++)
	{
		if (m_movies[i].get_movie_name() == this->m_movie_name)
		{
			for (int j = 0; j < m_movies[i].get_m_schedule_num(); j++)
			{
				std::cout << (m_movies[i].get_movie_schedule()[j].m_zone_num)+1 << "관  ";

				std::string time = "";
				switch (m_movies[i].get_movie_schedule()[j].m_movie_schedule)
				{
				case (schedule::MORNING_1):
					time = "8시 - 9시";		// 0으로 인식
					break;
				case (schedule::MORNING_2):
					time = "9시 - 10시";	// 1으로 인식
					break;
				case (schedule::MORNING_3):
					time = "10시 - 11시";	// 2로 인식
					break;
				case (schedule::AFTERNOON_1):
					time = "12시 - 1시";	// 3으로 인식
					break;
				case (schedule::AFTERNOON_2):
					time = "1시 - 2시"; 	// 4로 인식
					break;
				case (schedule::AFTERNOON_3):
					time = "2시 - 3시";		// 5로 인식
					break;
				}

				std::cout << time << "\n"<<std::endl;
			}
		}
	}

	std::cout << "상영관  상영시간의 순서로 입력해주세요." << std::endl;
	std::cout << "8시 - 9시는 1, 9시 - 10시는 2, 10시 - 11시는 3, 12시 - 1시는 4, 1시 - 2시는 5, 2시 - 3시는 6을 입력해 주세요" << std::endl;
	
	std::cin >> m_movie_zone >> m_movie_time;
	m_movie_time--;
	// m_movie_time 은 schedule enum자료형을 따른 다고 가정함

//좌석 출력 부분
	std::cout << "    1  2  3  4  5  6"<<"\n";
	 char initial = 'A';
	for (int i = 0; i < SEAT_ROW_NUM; i++)
	{
		std::cout<<" " << initial<<"  ";
		for (int j = 0; j < SEAT_COL_NUM; j++)
		{

			if (this->m_zone_info[m_movie_zone - 1].get_seat_info(i, j, m_movie_time).isempty)
			{
				std::cout << "□ ";
			}
			else
			{
				std::cout << "■ ";
			}
			
		}
		std::cout << "\n";
		initial++;
	}

	//좌석 선택 입력
	//좌석이 선택가능한지 판단 -> 선택할수 있는 경우 예약 완료 & 포인트 적립
	std::string row_col;
	int row, size;
	int col;
	while (true) {
		std::cout << "좌석 열을 선택해주세요" << std::endl;
		std::cin >> row_col;
		if (row_col[0] >= 'a' && row_col[0] <= 'f') {
			row_col[0] = row_col[0] - 32;
		}


		row = (int)row_col[0] - 65;
		std::cout << "좌석 번호를 입력해주세요 " << std::endl;
		std::cin >> col;
		col = col - 1;


		if (isavailable(row_col, col, (schedule)m_movie_time, m_movie_zone) == false) {
			std::cout << "해당 좌석은 선택할 수 없습니다.\n";
		}
		else {
			this->m_zone_info[m_movie_zone - 1].set_seat_info(row, col, m_movie_time, customer);


			int ans;
			std::cout << "포인트 적립 하시려면 1번을 눌러주세요." << std::endl;
			std::cin >> ans;
			if (ans == 1)
				customer.addpoint(500);

			break;
		}
	}


	return true;
}


// 특정 좌석이 선택가능한 좌석인지 여부를 반환
bool CReserve::isavailable(std::string& choose_seat, int col, schedule time, int zone) {

	int row = (int)choose_seat[0] - 65;
	int col2 = col;


	if (isempty(row, col2, time, zone) && isempty(row - 1, col2, time, zone) && isempty(row + 1, col2, time, zone) && isempty(row, col2, time, zone) && isempty(row, col2, time, zone))
		return true;
	return false;
}

bool CReserve::isempty(int row, char col, int time, int zone) {
	if (row < 0 || row > SEAT_ROW_NUM - 1 || col < 0 || col > SEAT_COL_NUM - 1)
		return true; //좌석이 범위를 벗어날 경우 고려하지 않아도 됨!
	return m_zone_info[zone].get_seat_info(row, col, time).isempty;
}



bool CReserve::cancel_reservation(CPerson_Info& customer)
{
	std::string person_name;
	std::string phonenumber;
	std::cout << "이름을 입력해 주세요" << std::endl;
	std::cin >> person_name;
	std::cout << "전화번호를 입력해 주세요" << std::endl;
	std::cin >> phonenumber;

	int row = 0, col = 0;
	for (int i = 0; i < ZONE_NUM; i++) {
		for (int j = 0; j < SCHEDULE_NUM; j++) {
			for (int k = 0; k < SEAT_ROW_NUM; k++) {
				for (int L = 0; L < SEAT_COL_NUM; L++) {
					if ((this->m_zone_info[i].get_seat_info(k, L, j).getname() == person_name) && (this->m_zone_info[i].get_seat_info(k, L, j).getphonenumber() == phonenumber)) {
						this->m_zone_info[i].get_seat_info(k, L, j).subname(person_name);
						this->m_zone_info[i].get_seat_info(k, L, j).subphonenumber(phonenumber);
						this->m_zone_info[i].get_seat_info(k, L, j).subpoint(500);
					}
					L++;
				}
				k++;
			}
		}
	}
	return true;
}
