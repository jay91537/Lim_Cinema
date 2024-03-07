#include "CZone.h"

CZone::CZone(int row_num, int col_num) : m_row_num(row_num), m_col_num(col_num) {
    CSeat::init_seatnum();
    this->allocate(m_row_num, m_col_num);
}

void CZone::allocate(int row, int col) {
    for (int i = 0; i < SCHEDULE_NUM; i++) {
        m_seat_info[i] = new CSeat * [m_row_num];

        for (int j = 0; j < m_row_num; j++) {
            m_seat_info[i][j] = new CSeat[m_col_num];
        }
    }
}

void CZone::free() {
    for (int i = 0; i < SCHEDULE_NUM; i++) {
        for (int j = 0; j < m_row_num; j++) {
            delete[] m_seat_info[i][j];
        }
    }

    for (int i = 0; i < SCHEDULE_NUM; i++) {
        delete[] m_seat_info[i];
    }
}

void CZone::set_seat_num(bool want_row_num, int num) {
    if (want_row_num) {
        this->m_row_num = num;
    }
    else {
        this->m_col_num = num;
    }
    // ���� �Ҵ�� seat_info �迭�� ������.
    free();

    //���ο� ������ seat_info �迭�� �Ҵ���.
    allocate(m_row_num, m_col_num);
}


const CZone& CZone::operator= (const CZone& zone) {
    if (this != &zone) {
        //�����Ϸ��� zone������ ����� ���ƾ� ��. �ƴ� �� �캯�� ���߾� ����.
        if (!(this->m_row_num == zone.get_seat_num(true) && this->m_col_num == zone.get_seat_num(false))) {
            free();
            m_row_num = zone.get_seat_num(true);
            m_col_num = zone.get_seat_num(false);
            allocate(m_row_num, m_col_num);
        }
        for (int i = 0; i < SCHEDULE_NUM; i++) {
            for (int j = 0; j < m_row_num; j++) {
                for (int k = 0; k < m_col_num; k++) {
                    m_seat_info[i][j][k] = zone.get_seat_info(j, k, i);
                }
            }
        }
    }
    return *this;
}

int CZone::get_seat_num(bool want_row_num) const {
    if (want_row_num)
        return m_row_num;
    return m_col_num;
}

CZone::CZone(const CZone& zone) : m_row_num(zone.get_seat_num(true)), m_col_num(zone.get_seat_num(false)) {
    allocate(m_row_num, m_col_num);

    //�¼������� zone�� �����ϰ� ����.
    for (int i = 0; i < SCHEDULE_NUM; i++) {
        for (int j = 0; j < m_row_num; j++) {
            for (int k = 0; k < m_col_num; k++) {
                m_seat_info[i][j][k] = zone.get_seat_info(j, k, i);
            }
        }
    }

}

void CZone::set_seat_info(int row, int col, int time, CPerson_Info customer) {
    m_seat_info[time][row][col].setgender(customer.getgender());
    m_seat_info[time][row][col].setname(customer.getname());
    m_seat_info[time][row][col].setphonenumber(customer.getphonenumber());
    m_seat_info[time][row][col].isempty = false;

}
void CZone::set_movie_info(int time, std::string title) {
    for (int i = 0; i < m_row_num; i++) {
        for (int j = 0; j < m_col_num; j++) {
            m_seat_info[time][i][j].set_movie_name(title);
        }
    }
}

CZone::~CZone() { free(); }
CSeat CZone::get_seat_info(int row, int col, int time) const {
    if (row > m_row_num || col > m_col_num || row < 0 || col < 0)
        return CSeat("", "", false, "", 0);   //���� �ʰ��� ��ȭ������ ���� dummy CSeat ��ü ����

    return m_seat_info[time][row][col];
}

