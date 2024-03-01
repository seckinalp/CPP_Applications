/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : patient.cpp
 */
#include "patient.h"
using namespace std;
patient::patient()
{
}

patient::patient(int number, int priority, int arrival_time, int examination_duration)
{
    this->number = number;
    this->priority = priority;
    this->arrival_time = arrival_time;
    this->examination_duration = examination_duration;
}