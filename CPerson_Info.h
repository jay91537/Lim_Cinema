#ifndef __CPERSONINFO__
#define __CPERSONINFO__

#include<string>
/*
예매하는 사람의 개인정보
이름, 전화번호, 성별을 입력받아 리턴
포인트 적립
*/
class CPerson_Info {
private:
	std::string m_name;
	std::string m_phonenumber;
	bool m_gender;
	int m_point;

public:
	CPerson_Info(std::string name, std::string phonenumber, bool gender, int point = 500);
	CPerson_Info();

	void setname(std::string name);
	void setphonenumber(std::string phonenumber);
	void setgender(bool gender);
	void setpoint(int point);
	void addpoint(int point);

	void subname(std::string name);
	void subphonenumber(std::string phonenumber);
	void subgender(bool gender);
	void subpoint(int point);

	int getpoint() const;
	std::string getname() const;
	std::string getphonenumber() const;
	bool getgender() const;
};

#endif