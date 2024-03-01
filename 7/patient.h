/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : patient.h it has special bool oparetor < for PatientQue Max Heap Que implemantation.
 */
#ifndef PATIENT_H
#define PATIENT_H
using namespace std;

class patient
{

public:
    patient();
    int number;
    int priority;
    int arrival_time;
    int examination_duration;
    patient(int number, int priority, int arrival_time, int examination_duration);

    bool operator<(const patient& other) const
    {
        if (priority == other.priority)
        {

            return arrival_time > other.arrival_time;
        }
        return priority < other.priority;
    }
};

#endif // PATIENT_H