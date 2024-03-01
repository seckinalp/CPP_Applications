OUTPUT := simulator

output: HospitalSimulationMgr.o PatientQueTime.o DoctorQue.o PatientQue.o doctor.o patient.o
	g++ HospitalSimulationMgr.o PatientQueTime.o DoctorQue.o PatientQue.o doctor.o patient.o -o $(OUTPUT)

HospitalSimulationMgr.o: HospitalSimulationMgr.cpp
	g++ -c HospitalSimulationMgr.cpp

DoctorQue.o: DoctorQue.cpp
	g++ -c DoctorQue.cpp

PatientQue.o: PatientQue.cpp
	g++ -c PatientQue.cpp

PatientQueTime.o: PatientQueTime.cpp
	g++ -c PatientQueTime.cpp

doctor.o: doctor.cpp doctor.h
	g++ -c doctor.cpp

patient.o: patient.cpp patient.h
	g++ -c patient.cpp

run: output
	./$(OUTPUT)

clean:
	rm -f *.o $(OUTPUT)