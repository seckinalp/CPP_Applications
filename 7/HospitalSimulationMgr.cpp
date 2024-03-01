/**
 * Author : Seçkin Alp Kargý
 * ID: 22001942
 * Section : 1
 * Homework : 3
 * Description : HostiptalSimulationMgr.cpp - it has two methods calculateAverageWaitingTime and minDoctorFinder also it has Main method. It has O(N*logN*logN) time complexity.
 */
 // g++ patient.cpp doctor.cpp PatientQue.cpp PatientQueTime.cpp DoctorQue.cpp HospitalSimulationMgr.cpp -o main
#include <iostream>
#include <fstream>
#include "patient.h"
#include "PatientQue.h"
#include "DoctorQue.h"
#include "PatientQueTime.h"
#include <string>
using namespace std;

// calculate Average Waiting Time has O(NlogN) time complexity, it travers patients one time O(N) and in each traverse it uses push() and pop() que properties which requires O(logN) time.
float calculateAverageWaitingTime(PatientQueTime patients_load_const, int doctor_number, string& printing, int totalPatients)
{
    PatientQue patientQueue;
    DoctorQue doctorQueue;
    PatientQueTime patients_load;
    PatientQueTime temp;
    while (!patients_load_const.empty())
    {
        patients_load.push(patients_load_const.top());
        temp.push(patients_load_const.top());
        patients_load_const.pop();
    }
    while (!temp.empty())
    {
        patients_load_const.push(temp.top());
        temp.pop();
    }

    printing = "";
    int totalWaitingTime = 0;
    patientQueue.push(patients_load.top());
    patients_load.pop();
    for (int i = 0; i < doctor_number; i++)
    {
        doctorQueue.push(doctor(0, i));
    }

    while (!patientQueue.empty() || !patients_load.empty())
    {
        doctor currentdoc = doctorQueue.top();
        patient currentPatient = patientQueue.top();
        if (!patients_load.empty() && patients_load.top().arrival_time == currentPatient.arrival_time)
        {
            patientQueue.push(patients_load.top());
            patients_load.pop();
        }
        else if (!patients_load.empty() && doctorQueue.top().doctor_time >= patients_load.top().arrival_time)
        {
            patientQueue.push(patients_load.top());
            patients_load.pop();
        }
        else if ((patientQueue.empty() && doctorQueue.top().doctor_time < patients_load.top().arrival_time))
        {
            patientQueue.push(patients_load.top());
            patients_load.pop();
        }
        else
        {
            patientQueue.pop();
            doctorQueue.pop();
            if (currentdoc.doctor_time < currentPatient.arrival_time)
            {
                printing += "Doctor " + to_string(currentdoc.doctor_number) + " takes patient " + to_string(currentPatient.number) + " at minute " + to_string(currentPatient.arrival_time) + " (wait: " + "0" + " mins)\n";
                currentdoc.doctor_time = currentPatient.examination_duration + currentPatient.arrival_time;
                doctorQueue.push(currentdoc);
            }
            else
            {
                totalWaitingTime += currentdoc.doctor_time - currentPatient.arrival_time;
                printing += "Doctor " + to_string(currentdoc.doctor_number) + " takes patient " + to_string(currentPatient.number) + " at minute " + to_string(currentdoc.doctor_time) + " (wait: " + to_string((currentdoc.doctor_time - currentPatient.arrival_time)) + " mins)\n";
                currentdoc.doctor_time = currentPatient.examination_duration + currentdoc.doctor_time;
                doctorQueue.push(currentdoc);
            }
        }
    }
    return static_cast<float>(totalWaitingTime) / totalPatients;
}

// minDoctorFinder function uses Binary Search Tree logic for finding minumum doctor needed so it has O(logN) time complexity.
void minDoctorFinder(PatientQueTime patients_load, float average_waiting, int patient_number)
{
    int minDoctor = 1;
    int maxDoctor = patient_number;
    string printing = "";
    float average = 0;

    while (minDoctor <= maxDoctor)
    {
        int midDoctor = (minDoctor + maxDoctor) / 2;
        average = calculateAverageWaitingTime(patients_load, midDoctor, printing, patient_number);

        if (average <= average_waiting)
        {
            maxDoctor = midDoctor - 1;
        }
        else
        {
            minDoctor = midDoctor + 1;
        }
    }

    minDoctor = maxDoctor + 1;
    average = calculateAverageWaitingTime(patients_load, minDoctor, printing, patient_number);
    std::cout << endl;
    std::cout << "Minimum number of doctors required: " << minDoctor << endl;
    std::cout << endl;
    std::cout << "Simulation with " << minDoctor << " doctors:" << endl;
    std::cout << endl;
    std::cout << printing;
    std::cout << endl;
    std::cout << "Average waiting time: " << average << " minutes" << endl;
    std::cout << endl;
}

int main(int argc, char* argv[])
{

    if (argc < 3)
    {
        std::cout << "There is missing arguments!!" << endl;
    }
    else
    {
        string patients_list = argv[1];
        int average_waiting = atoi(argv[2]);

        if (average_waiting < 0)
        {
            std::cout << "Average waiting can't be negative!";
            return 0;
        }
        ifstream patient_list_file(patients_list);
        if (!patient_list_file)
        {
            std::cout << "Program can not reach the txt file!";
            return 0;
        }

        int number_of_patients;
        patient_list_file >> number_of_patients;

        if (number_of_patients > 0)
        {

            PatientQueTime patients_load;
            for (int i = 0; i < number_of_patients; i++)
            {
                int number, priority, arrival_time, examination_duration;
                patient_list_file >> number >> priority >> arrival_time >> examination_duration;
                patients_load.push(patient(number, priority, arrival_time, examination_duration));
            }

            patient_list_file.close();

            minDoctorFinder(patients_load, average_waiting, number_of_patients);
        }
        else
        {
            patient_list_file.close();
            std::cout << "There is not any patient!!";
        }
    }
    return 0;
}
