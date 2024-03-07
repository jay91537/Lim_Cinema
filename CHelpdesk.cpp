#include <windows.h>
#include "CHelpdesk.h"

CHelpdesk::CHelpdesk(CReserve& receptionsist, std::string* movie_titles, CPerson_Info& customer, CAnalyze& status) : m_receptionist(receptionsist),
m_movie_titles(movie_titles), m_customer(customer), m_status(status) {
	m_col1_idx = "| No |";
	m_col2_idx = "| Titles |";

	m_movie_num = new std::string[MOVIES_NUM];
	for (int i = 0; i < MOVIES_NUM; i++)
		m_movie_num[i] = std::to_string(i + 1);

}
CHelpdesk::~CHelpdesk() {
	delete[] m_movie_num;
}

bool CHelpdesk::menu() {
	m_printer.msgbox("Welcome to LIM CINEMA!");

	for (int i = 0; i < 50; i++)
		std::cout << " ";

	
	for (int i = 0; i < 20; i++) {
		std::cout << "=";
		Sleep(100);
	}
	m_printer.clear();

	int choice;
	std::cout << "영화 예매는 1번, 예매 현황 분석은 2번, 예매 취소는 3번, 종료는 4번을 눌러주세요. \n";
	std::cin >> choice;

	int title_no;

	switch (choice)
	{
		case 1:

			m_printer.pyo(m_col1_idx, m_col2_idx, m_movie_num, m_movie_titles, m_col1_idx.size(), m_col2_idx.size(), MOVIES_NUM);
			std::cout << "보고 싶으신 영화의 번호를 입력해 주세요\n";
			std::cin >> title_no;
			for (int i = 0; i < 20; i++) {
				std::cout << "\n";
			}
			m_receptionist.set_movie_name(m_movie_titles[title_no - 1]);
			m_receptionist.reserve(m_customer);
			return true;
			break;
		case 2:
			m_status.start_analyzing();
			return true;
			break;
		case 3:
			m_receptionist.cancel_reservation(m_customer);
			return true;
			break;
		case 4:
			return false;
			break;
		default:
			return true;
			break;
	}

}

