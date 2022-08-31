using System;

namespace casting2
{
    class Program
    {
        static void Main(string[] args)
        {
            /*Person personAli = new Person();
            personAli.name = "Ali";
            personAli.birth = new DateTime(2000,1,1);

            personAli.writeToConsole();
            */

            Employee employeeAli = new Employee();
            employeeAli.name = "Ali";
            employeeAli.birth = new DateTime(2000, 1, 1);
            employeeAli.hired = new DateTime(2022, 1, 1);
            employeeAli.ID = "AA123";

            Person personAli = employeeAli;     // upcasting

            personAli.writeToConsole();
            employeeAli.writeToConsole();

            personAli.printInformation();
            employeeAli.printInformation();
            
            Console.WriteLine("--------------------");

            Manager managerAyse = new Manager();
            managerAyse.name = "Ayşe";
            managerAyse.birth = new DateTime(1990, 6, 6);
            managerAyse.hired = new DateTime(2022, 1, 1);
            managerAyse.ID = "BB123";

            Console.WriteLine("--------------------");
            
            managerAyse.writeToConsole();

            Employee employeeAyse = managerAyse;       // upcasting

            Console.WriteLine("--------------------");
            
            employeeAyse.writeToConsole();


        }


    }
}
