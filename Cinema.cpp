#include "Cinema.h"
#include "CZone.h"
#include "Option.h"

Cinema::Cinema(CZone* zones, CMovie_Info* movies, CPerson_Info* people, CPerson_Info& customer, CReserve receptionist, std::string* movie_titles, CAnalyze status) : m_gwan(zones), m_movies(movies),
m_people(people), m_customer(customer), m_chatbot(receptionist, movie_titles, customer, status) { }
