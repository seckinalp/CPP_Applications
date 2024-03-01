// CS201 HW3 Name: Seçkin Alp Kargı Student Id: 22001942 Section: 1
#include <iostream>
#include "RegistrationSystem.h"
using namespace std;

RegistrationSystem::RegistrationSystem()  
{
    first = nullptr;
    last = nullptr;
}
RegistrationSystem::~RegistrationSystem() 
{

    student *finder = first;

    while  (finder  != nullptr) 
    {

        course *coursefinder = finder->courses;

        while (coursefinder  != nullptr) 
        {
            course *x = coursefinder ;
            coursefinder = coursefinder->next;
            delete x;
        }
        student *x = finder ;

        finder= finder->next;
        delete x;

    }
   first = nullptr;
     last = nullptr;
} 

void RegistrationSystem::addStudent (const int studentId , const std::string firstName , const std::string lastName)
{
    student *add = new student(studentId,firstName,lastName);
    if (first == nullptr || studentId < first->student_id) 
    {
        add->next = first;
        if(first != nullptr)
        {
            first->prev = add;
        }
        first = add;
    }
    else
    {
        
        if(first->student_id == studentId)
        {
            std::cout << "Student " << studentId << " already exists\n";
            delete add;
            return;
        }
        student *order = first;

            if(order->next != nullptr)
            {
                if(order->next->student_id == studentId)
                {
                        std::cout << "Student " << studentId << " already exists\n";
                        delete add;
                        
                        return;
                }
                while(order->next->student_id < studentId )
                {
                    if(order->student_id == studentId)
                    {
                        std::cout << "Student " << studentId << " already exists\n";
                        delete add;
                        
                        return;
                    }
                    order = order->next;
                    if(order->next == nullptr)
                    {
                        
                        break;
                    }
                    if(order->next->student_id == studentId)
                    {
                        std::cout << "Student " << studentId << " already exists\n";
                        delete add;
                      
                        return;
                    }
                }
              
            }

        add->next = order->next;
        add->prev = order;
        order->next = add;
        if(add->next !=nullptr)
        {
            add->next->prev = add;
        }

    }
    std::cout << "Student " << studentId << " has been added\n";
      /*
        std::cout << "Student " << studentId << " has been added\n";
        return;
    

        student* order = first;


        while (order->student_id < studentId && order != nullptr) 
        {
            order = order->next;
        }

        if(order == first)
        {
            add->next = first;
            first->prev = add;
            first = add;
            std::cout << "Student " << studentId << " has been added\n";
        }
        else if(order == nullptr)
        {
            last->next = add;
            add->prev = last;
            last = add;
            std::cout << "Student " << studentId << " has been added\n";
        }
        else if(order->student_id == studentId)
        {
            std::cout << "Student " << studentId << " already exists\n";
        }
        else
        {
            add->next = order;
            add->prev = order->prev;
            order->prev->next = add;
            order->prev = add;
            std::cout << "Student " << studentId << " has been added\n";
    }
    */
}
void RegistrationSystem::addCourse (const int studentId , const int courseId , const std::string courseName)
{
    if(first != nullptr) {
    student *finder = first;

    while(finder->student_id != studentId && finder != nullptr)
    {
       
        finder = finder->next;
        if(finder == nullptr)
    {
        std::cout << "Student " << studentId << " does not exist\n";
        return;
    }
    }

    if(finder == nullptr)
    {
        std::cout << "Student " << studentId << " does not exist\n";
        return;
    }
    else
    {
        student *finderr = first;
      
        while(finderr != nullptr)
        {
           
            course *course_finderr = finderr->courses;
            
            while(course_finderr != nullptr)
            {
                if(course_finderr->course_id == courseId)
                {
                   
                    
                    if(course_finderr->course_id == courseId && finderr->student_id != studentId)
                    {
                        if(course_finderr->course_name != courseName)
                        {
                            
                            std::cout << "Course " << courseId << " already exists with another name\n";
                            return;
                        }
                       
                        
                    }
                }
                course_finderr = course_finderr->next;
            }
            finderr = finderr->next;
        }


        course *add = new course(courseId,courseName);
        course *order = finder->courses;
        
        if(finder->courses == nullptr)
        {
              add->next = finder->courses;
            finder->courses = add;
            std::cout << "Course " << courseId << " has been added to student " << studentId << "\n";
            return;
        }

         if(order->course_id == courseId)
            {
                if(order->course_name == courseName)
                {
                    std::cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
                    delete add;
                }
                else
                {
                    std::cout << "Course " << courseId << " already exists with another name\n";
                    delete add;
                }
                return;
            }

        if(finder->courses->next != nullptr)
        {
                if(order->next->course_id == courseId)
            {
                if(order->next->course_name == courseName)
                {
                    std::cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
                    delete add;
                  
                }
                else
                {
                    std::cout << "Course " << courseId << " already exists with another name\n";
                    delete add;
                }
                return;
            }
        }
         
        if(finder->courses->course_id > courseId)
        {
            add->next = finder->courses;
            finder->courses = add;
            std::cout << "Course " << courseId << " has been added to student " << studentId << "\n";
            return;
        }
        else
        {
                      
            if(order->course_id == courseId)
            {
                if(order->course_name == courseName)
                {
                    std::cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
                  delete add;
                }
                else
                {
                    std::cout << "Course " << courseId << " already exists with another name\n";
                    delete add;
                }
                return;
            }

            
        if(finder->courses->next != nullptr)
        {
            if(order->next->course_id == courseId)
            {
                if(order->next->course_name == courseName)
                {
                    std::cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
                    delete add;
                  
                }
                else
                {
                    std::cout << "Course " << courseId << " already exists with another name\n";
                    delete add;
                }
                return;
            }
        }
            if(order->next != nullptr)
            {
                while(order->next->course_id < courseId )
                {
                    
                    order = order->next;
                    if(order->next == nullptr)
                    {
                        
                        break;
                    }
                }
            }
            if(order->course_id == courseId)
            {
                if(order->course_name == courseName)
                {
                    std::cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
                    delete add;
                }
                else
                {
                    std::cout << "Course " << courseId << " already exists with another name\n";
                    delete add;
                }
                return;
            }
                        }
            if(order->next != nullptr) {
            if(order->next->course_id == courseId)
            {
                if(order->next->course_name == courseName)
                {
                    std::cout << "Student " << studentId << " is already enrolled in course " << courseId << "\n";
                    delete add;
                }
                else
                {
                    std::cout << "Course " << courseId << " already exists with another name\n";
                    delete add;
                }
                return;
            }
            }
            add->next = order->next;
            order->next = add;

            std::cout << "Course " << courseId << " has been added to student " << studentId << "\n";

        }
        return;
    }
    std::cout << "Student " << studentId << " does not exist\n";
}
void RegistrationSystem::deleteStudent (const int studentId) 
{
    if(first != nullptr)
    {
        student *finder = first;
        while(finder != nullptr)
        {
            
            if(finder->student_id == studentId)
            {

                if(finder->next == nullptr && finder->prev != nullptr)
                {
                    finder->prev->next = nullptr;
                    last = finder->prev;
                    std::cout << "Student " << studentId << " has been deleted\n";
                    
                }
                else if(finder->prev == nullptr)
                {
                    if(finder->next == nullptr)
                    {
                        first->prev = nullptr;
                        first->next = nullptr;
                        first = nullptr;
                        last = nullptr;
                        
                    }
                    else
                    {
                        finder->next->prev = nullptr;
                        
                        first = finder->next;
                        
                    }
                    std::cout << "Student " << studentId << " has been deleted\n";
                    
                }
                else
                {
                    finder->prev->next = finder->next;
                    finder->next->prev = finder->prev;
                    std::cout << "Student " << studentId << " has been deleted\n";
                    
                }
                
                while(finder->courses != nullptr)
                {
                    course *deleter = finder->courses;
                    finder->courses = finder->courses->next;
                    delete deleter;
                }
              delete finder;
                return;
            }
            finder = finder->next;
        }
        
    }
    std::cout << "Student " << studentId << " does not exist\n";
    
}
void RegistrationSystem::cancelCourse (const int courseId) 
{
    int checker = 0;
    
    if(first == nullptr)
    {
        std::cout << "Course " << courseId << " does not exist\n";
        return;
    }
    else
    {
        student *finder = first;
        
        while(finder != nullptr)
        {
            int checker2 = 0;
            course *course_finder = finder->courses;
            course *course_finder_prev = nullptr;
            while(course_finder != nullptr)
            {
                if(course_finder->course_id == courseId)
                {
                    checker2 = 1;
                    break;
                }
                course_finder = course_finder->next;
            }
            
            if(checker2 == 1)
            {
                course_finder = finder->courses;
                while(course_finder->course_id != courseId && course_finder != nullptr)
                {
                    course_finder_prev = course_finder;
                    course_finder = course_finder->next;
                }
                if(course_finder_prev == nullptr)
                {
                    finder->courses = course_finder->next;
                }
                else
                {
                    course_finder_prev->next = course_finder->next;
                }
                checker = 1;
                delete course_finder;
            }

            finder = finder->next;
   
        }
    }

    if(checker == 0)
    {
        std::cout << "Course " << courseId << " does not exist\n";
    }
    else
    {
        std::cout << "Course " << courseId << " has been cancelled\n";
    }
    
}
void RegistrationSystem::withdrawCourse (const int studentId , const int courseId) 
{
    if(first != nullptr)
    {
        student *finder = first;
        while(finder != nullptr)
        {
            if(finder->student_id == studentId)
            {
                break;
            }
            finder = finder->next;
        }
        if(finder == nullptr)
        {
            std::cout << "Student " << studentId << " does not exist\n";
            return;
        }
        
        int checker = 0;
        course *course_finder = finder->courses;
        course *course_finder_prev = nullptr;
        while(course_finder != nullptr)
        {
            if(course_finder->course_id == courseId)
            {
                checker = 1;
                break;
            }
            course_finder = course_finder->next;
        }
        if(checker == 0)
        {
            std::cout << "Student " << studentId << " is not enrolled in course " << courseId <<"\n";
            return;
        }
        course_finder = finder->courses;
        while(course_finder->course_id != courseId && course_finder != nullptr)
        {
            course_finder_prev = course_finder;
            course_finder = course_finder->next;
        }
        if(course_finder_prev == nullptr)
        {
            finder->courses = course_finder->next;
        }
        else
        {
            course_finder_prev->next = course_finder->next;
        }
        std::cout << "Student " << studentId << " has been withdrawn from course " << courseId <<"\n";
        delete course_finder;
        return;
    }
    std::cout << "Student " << studentId << " does not exist\n";
}
void RegistrationSystem::showCourse (const int courseId) 
{
    student *printer = first;
    int checker = 0;
    while(printer != nullptr)
    {
        course *course_printer = printer->courses;
        while(course_printer != nullptr)
        {
            if(course_printer->course_id == courseId)
            {
                if(checker == 0)
                {
                    checker = 1;
                    std::cout << "Course id Course name\n";
                    std::cout <<  courseId << " " << course_printer->course_name << "\n";
                    std::cout << "Student id First name Last name\n";
                }
                std::cout << printer->student_id << " " << printer->student_first_name << " " << printer->student_last_name <<"\n";
            }
            course_printer = course_printer->next;
        }
        printer = printer->next;
    }
    if(checker == 0)
    {
        std::cout << "Course " << courseId << " does not exist\n";
    }
}
void RegistrationSystem::showStudent (const int studentId) 
{
    int checker = 0;
    student *printer = first;
    while(printer != nullptr)
    {
        if(printer->student_id == studentId)
        {
            std::cout << "Student id First name Last name\n";
            std::cout << printer->student_id << " " << printer->student_first_name << " " << printer->student_last_name <<"\n";
            
            if(printer->courses != nullptr)
            {
                course *course_printer = printer->courses;
                while(course_printer != nullptr)
                {
                    if(checker == 0)
                    {
                        checker = 1;
                        std::cout << "Course id Course name\n";
                    }
                    std::cout << course_printer->course_id << " "<< course_printer->course_name << "\n";
                    course_printer = course_printer->next;
                }
            }
            return;
        }
        printer = printer->next;
    }
    std::cout << "Student " << studentId << " does not exist\n";
}
void RegistrationSystem::showAllStudents() 
{
    int checker = 0;
    
    if(first == nullptr)
    {
        std::cout << "There are no students in the system\n";
    }
    else
    {
        if(checker == 0)
        {
            std::cout << "Student id First name Last name\n";
            checker = 1;
        }
        
        student *printer = first;
        while(printer != nullptr)
        {
            int checker2 = 0;
            std::cout << printer->student_id << " " << printer->student_first_name << " " << printer->student_last_name <<"\n";

            if(printer->courses != nullptr)
            {
                course *course_printer = printer->courses;
                while(course_printer != nullptr)
                {
                    if(checker2 == 0)
                    {
                        std::cout << "Course id Course name\n";
                        checker2 = 1;
                    }
                    std::cout << course_printer->course_id << " "<< course_printer->course_name << "\n";
                    course_printer = course_printer->next;
                }
            }
            printer = printer->next;
        }
    }
}
 