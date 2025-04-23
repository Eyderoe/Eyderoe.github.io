#ifndef ADDON_HPP
#define ADDON_HPP

class Account {
    public:
        static double m_rate;
        static void set_rate (const double &x);
};
double Account::m_rate;   // 静态数据要在类的外面定义

namespace tds {

template<typename T>
struct multi {
    T id;
};


multi<int> person;
void add () {}

}
namespace dts = tds;
using namespace tds;
using dts::add;

#endif //ADDON_HPP
