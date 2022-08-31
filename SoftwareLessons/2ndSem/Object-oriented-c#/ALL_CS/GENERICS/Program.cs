using System;
using System.Collections;
using System.Collections.Generic;

namespace generics
{
    class Student
    {
        private int mStudentID;
        private string mStudentName;

        public int studentId { set => mStudentID=value; get=>mStudentID; }
        public string studentName { set => mStudentName = value; get => mStudentName; }
    }


    class Program
    {
        static void Main(string[] args)
        {
            // instance of string type
            genericsClass<string> name = new genericsClass<string>();
            name.data = "Object Oriented Programming";
            name.printData();

            // instance of float type
            genericsClass<float> number = new genericsClass<float>(3);
            number.data = 9.0f;
            number.printData();
            number.printList();

            genericsClass<float>[] numbers = new genericsClass<float>[5];

            int x = 5, y = 10;

            genericsClass<int>.Swap(ref x, ref y);

            Console.WriteLine("value of x is " + x);
            Console.WriteLine("value of y is " + y);


            /*ArrayList studentList = new ArrayList();    // List of students
                                                        // uses 'System.Collections' namespace
            Student objStudent;

            objStudent = new Student() { studentName = "Ali", studentId = 1 };
            studentList.Add(objStudent);

            objStudent = new Student() { studentName = "Ayşe", studentId = 2 };
            studentList.Add(objStudent);

            studentList.Add("Test");        // no compile-time error
                                            // throws an exception => InvalidCastException

            foreach (Object s in studentList)
            {
                //Type-casting. If s is anything other than a student
                Student currentStudent = (Student)s;        
                                                    
                Console.WriteLine("ID # " + currentStudent.studentId +
                                  " is " + currentStudent.studentName);
            }
            */


            // List<> is a C# generic collection
            // uses 'System.Collections.Generic' namespace
            List<Student> lstStudents = new List<Student>();

            Student objStudent;

            objStudent = new Student() { studentName = "Ali", studentId = 1 };
            lstStudents.Add(objStudent);

            objStudent = new Student() { studentName = "Ayşe", studentId = 2 };
            lstStudents.Add(objStudent);

            //lstStudents.Add("Test");        // compile-time error

            foreach (Student currentSt in lstStudents)  //Looping through the list of students
            {
                //no need to type cast since compiler already knows that everything inside 
                //this list is a Student
                Console.WriteLine("ID # " + currentSt.studentId +
                                  " is " + currentSt.studentName);
            }

        }
    }
}
