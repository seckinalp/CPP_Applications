/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : doctor.cpp , it has doctor_time and doctor_number attributes
 */
#include "doctor.h"
using namespace std;
doctor::doctor()
{
}
doctor::doctor(int doctor_time, int doctor_number)
{
    this->doctor_time = doctor_time;
    this->doctor_number = doctor_number;
}