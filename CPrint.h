
#ifndef __CPRINT__
#define __CPRINT__

#include <string>
#include <iostream>
#include <stdlib.h>

class CPrint {
private:

public:
    CPrint();
    void msgbox(std::string sentence) const;
    void clear() const;
    void pyo(std::string col1, std::string col2, std::string* col1_ptr, std::string* col2_ptr, int col1_size, int col2_size, int array_size) const;
    void pyo_zul(int co1_size, int col2_size)const;
    void pyo_naeyong(std::string* col1_ptr, std::string* col2_ptr, int col1_size, int col2_size, int i) const;
};

#endif