using System;

namespace Employee
{
    class Program
    {
        static void Main(string[] args)
        {
            //Person person1 = new Person();
            //person1.setInformation();
            //Console.Clear();
            //person1.printInformation();

            Employee emp1 = new Employee();
            emp1.setInformation();
            emp1.increaseSalary(10);

            emp1.printInformation();
        }
    }
}
