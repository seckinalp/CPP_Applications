// CS201 HW3 Name: Seçkin Alp Kargı Student Id: 22001942 Section: 1
#include <string>
class RegistrationSystem 
{
    public :
        RegistrationSystem () ;
        ~ RegistrationSystem () ;
        void addStudent ( const int studentId , const std::string firstName , const std::string lastName ) ;
        void deleteStudent ( const int studentId ) ;
        void addCourse ( const int studentId , const int courseId , const std::string courseName ) ;
        void withdrawCourse ( const int studentId , const int courseId ) ;
        void cancelCourse ( const int courseId ) ;
        void showStudent ( const int studentId ) ;
        void showCourse ( const int courseId ) ;
        void showAllStudents () ;

    private:
        
        class course
        {
            public:
            int course_id;
            std::string course_name;
            course *next;
            
            course(int course_id, std::string course_name)
            {
                next = nullptr;
                this->course_id = course_id;
                this->course_name = course_name;
            }
        };
        class student
        {
            public:

            int student_id;
            std::string student_first_name;
            std::string student_last_name;
            student *next;
            student *prev;
            course *courses;
            student(int student_id,std::string student_first_name,std::string student_last_name)
            {
                courses = nullptr;
                next = nullptr;
                prev = nullptr;
                this->student_last_name = student_last_name;
                this->student_first_name = student_first_name;
                this->student_id = student_id;  
            }
        };

        student* first;
        student* last;
};
