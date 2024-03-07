
#include "CReserve.h"
#include "Option.h"


CReserve::CReserve(CZone* zones, CMovie_Info* movies) :m_zone_info(zones), m_movies(movies) {}

void CReserve::set_movie_name(std::string title) {
	m_movie_name = title;
}

//���������
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
				std::cout << (m_movies[i].get_movie_schedule()[j].m_zone_num)+1 << "��  ";

				std::string time = "";
				switch (m_movies[i].get_movie_schedule()[j].m_movie_schedule)
				{
				case (schedule::MORNING_1):
					time = "8�� - 9��";		// 0���� �ν�
					break;
				case (schedule::MORNING_2):
					time = "9�� - 10��";	// 1���� �ν�
					break;
				case (schedule::MORNING_3):
					time = "10�� - 11��";	// 2�� �ν�
					break;
				case (schedule::AFTERNOON_1):
					time = "12�� - 1��";	// 3���� �ν�
					break;
				case (schedule::AFTERNOON_2):
					time = "1�� - 2��"; 	// 4�� �ν�
					break;
				case (schedule::AFTERNOON_3):
					time = "2�� - 3��";		// 5�� �ν�
					break;
				}

				std::cout << time << "\n"<<std::endl;
			}
		}
	}

	std::cout << "�󿵰�  �󿵽ð��� ������ �Է����ּ���." << std::endl;
	std::cout << "8�� - 9�ô� 1, 9�� - 10�ô� 2, 10�� - 11�ô� 3, 12�� - 1�ô� 4, 1�� - 2�ô� 5, 2�� - 3�ô� 6�� �Է��� �ּ���" << std::endl;
	
	std::cin >> m_movie_zone >> m_movie_time;
	m_movie_time--;
	// m_movie_time �� schedule enum�ڷ����� ���� �ٰ� ������

//�¼� ��� �κ�
	std::cout << "    1  2  3  4  5  6"<<"\n";
	 char initial = 'A';
	for (int i = 0; i < SEAT_ROW_NUM; i++)
	{
		std::cout<<" " << initial<<"  ";
		for (int j = 0; j < SEAT_COL_NUM; j++)
		{

			if (this->m_zone_info[m_movie_zone - 1].get_seat_info(i, j, m_movie_time).isempty)
			{
				std::cout << "�� ";
			}
			else
			{
				std::cout << "�� ";
			}
			
		}
		std::cout << "\n";
		initial++;
	}

	//�¼� ���� �Է�
	//�¼��� ���ð������� �Ǵ� -> �����Ҽ� �ִ� ��� ���� �Ϸ� & ����Ʈ ����
	std::string row_col;
	int row, size;
	int col;
	while (true) {
		std::cout << "�¼� ���� �������ּ���" << std::endl;
		std::cin >> row_col;
		if (row_col[0] >= 'a' && row_col[0] <= 'f') {
			row_col[0] = row_col[0] - 32;
		}


		row = (int)row_col[0] - 65;
		std::cout << "�¼� ��ȣ�� �Է����ּ��� " << std::endl;
		std::cin >> col;
		col = col - 1;


		if (isavailable(row_col, col, (schedule)m_movie_time, m_movie_zone) == false) {
			std::cout << "�ش� �¼��� ������ �� �����ϴ�.\n";
		}
		else {
			this->m_zone_info[m_movie_zone - 1].set_seat_info(row, col, m_movie_time, customer);


			int ans;
			std::cout << "����Ʈ ���� �Ͻ÷��� 1���� �����ּ���." << std::endl;
			std::cin >> ans;
			if (ans == 1)
				customer.addpoint(500);

			break;
		}
	}


	return true;
}


// Ư�� �¼��� ���ð����� �¼����� ���θ� ��ȯ
bool CReserve::isavailable(std::string& choose_seat, int col, schedule time, int zone) {

	int row = (int)choose_seat[0] - 65;
	int col2 = col;


	if (isempty(row, col2, time, zone) && isempty(row - 1, col2, time, zone) && isempty(row + 1, col2, time, zone) && isempty(row, col2, time, zone) && isempty(row, col2, time, zone))
		return true;
	return false;
}

bool CReserve::isempty(int row, char col, int time, int zone) {
	if (row < 0 || row > SEAT_ROW_NUM - 1 || col < 0 || col > SEAT_COL_NUM - 1)
		return true; //�¼��� ������ ��� ��� ������� �ʾƵ� ��!
	return m_zone_info[zone].get_seat_info(row, col, time).isempty;
}



bool CReserve::cancel_reservation(CPerson_Info& customer)
{
	std::string person_name;
	std::string phonenumber;
	std::cout << "�̸��� �Է��� �ּ���" << std::endl;
	std::cin >> person_name;
	std::cout << "��ȭ��ȣ�� �Է��� �ּ���" << std::endl;
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
