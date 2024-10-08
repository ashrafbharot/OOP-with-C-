/***********************************************************************
// OOP244 Workshop # 10
//
// Version 1.0
// Date: 2023/11/25
// Author: Fardad Soleimanloo
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name: MOHAMED ASHRAF BHAROT           Date: 2023-12-05           Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds {
    Car::Car(const char* plate, const char* makeModel) {
        strncpy(m_plate, plate, 8);
        m_plate[8] = 0;
        strncpy(m_makeModel, makeModel, 40);
        m_makeModel[40] = 0;;
    }
    std::ostream& Car::display(std::ostream& os)const {
        return os << m_plate << " " << m_makeModel;
    }
    bool Car::operator==(const char* mmSubstr)const {
        return strstr(m_makeModel, mmSubstr) != nullptr;
    }
}