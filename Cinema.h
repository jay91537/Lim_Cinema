
#ifndef __CINEMA__
#define __CINEMA__

#include "CZone.h"
#include "CHelpdesk.h"
#include "CReserve.h"
#include "Option.h"
#include "CMovie_Info.h"
#include "CPerson_Info.h"
class Cinema {

private:
	CZone* m_gwan;

	CMovie_Info* m_movies;
	CPerson_Info* m_people;		//�̸� ������ �ο����� ����
	CPerson_Info m_customer;    // ���� ���� �ϰ��� �ϴ� �� ����.

public:
	CHelpdesk m_chatbot;
	Cinema(CZone* zones, CMovie_Info* movies, CPerson_Info* people, CPerson_Info& customer, CReserve receptionist,
		std::string* movie_titles, CAnalyze status);
};
#endif
