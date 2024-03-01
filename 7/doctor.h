/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : doctor.h - it has bool operator <  logic for Que implemantation.
 */
using namespace std;

class doctor
{

public:
    doctor();
    int doctor_time;
    int doctor_number;
    doctor(int doctor_time, int doctor_number);

    bool operator<(const doctor& other) const
    {
        if (doctor_time > other.doctor_time)
        {
            return doctor_time > other.doctor_time;
        }
        if (doctor_time < other.doctor_time)
        {
            return doctor_time > other.doctor_time;
        }
        return doctor_number > other.doctor_number;
    }
};

