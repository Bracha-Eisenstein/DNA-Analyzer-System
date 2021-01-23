//
// Created by sari on 9/22/20.
//

#ifndef DNA_WITH_COLON_H
#define DNA_WITH_COLON_H
#include <string>
class WithColon
{
public:
    WithColon(std::string);
    std::string m_name;
};
inline WithColon::WithColon(std::string name) :m_name(name){}
#endif //DNA_WITH_COLON_H
