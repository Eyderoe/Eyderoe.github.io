#ifndef STR_HPP
#define STR_HPP

#include <cstring>

class str {
    public:
        str (const char *cstr = 0);
        str (const str &string);    // 拷贝构造
        str &operator= (const str &string); // 拷贝复制
        ~str ();    // 析构
        char *get_c_str () const { return m_data; }
    private:
        char *m_data;
};
inline str::str (const char *cstr) {
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else {  // 未指定初值
        m_data = new char[1];
        *m_data = '\0';
    }
}
str::str (const str &string) {
    m_data = new char[strlen(string.m_data) + 1];
    strcpy(m_data, string.m_data);
}
str &str::operator= (const str &string) {
    if (this == &string)    //自我赋值
        return *this;

    delete m_data;
    m_data = new char[strlen(string.m_data) + 1];
    strcpy(m_data, string.m_data);
    return *this;
}
str::~str () {
    delete[]m_data;
}
std::ostream &operator<< (std::ostream &os, const str &string) { // ostream不能是const，因为输出时状态会改变
    return os << string.get_c_str();
}

#endif //STR_HPP
