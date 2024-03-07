#include"CPerson_Info.h"

CPerson_Info::CPerson_Info() {}

CPerson_Info::CPerson_Info(std::string name, std::string phonenumber, bool gender, int point) :m_name(name),
m_phonenumber(phonenumber), m_gender(gender), m_point(point) {};

void CPerson_Info::setname(std::string name) { this->m_name = name; }
void CPerson_Info::setphonenumber(std::string phonenumber) { this->m_phonenumber = phonenumber; }
void CPerson_Info::setgender(bool gender) { this->m_gender = gender; }
void CPerson_Info::setpoint(int point) { this->m_point = point; }
void CPerson_Info::addpoint(int point) { this->m_point = this->m_point + point; }

void CPerson_Info::subname(std::string name) { this->m_name = ""; }
void CPerson_Info::subphonenumber(std::string phonenumber) { this->m_phonenumber = ""; }
void CPerson_Info::subgender(bool gender) { this->m_gender = 0; }                     
void CPerson_Info::subpoint(int point) { this->m_point = m_point - point; }

int CPerson_Info::getpoint() const { return m_point; }
std::string CPerson_Info::getname() const { return m_name; }
std::string CPerson_Info::getphonenumber() const { return m_phonenumber; }
bool CPerson_Info::getgender() const { return m_gender; }
