using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// int enum
public enum DEPARTMENT : int
{
    IT,
    MANAGEMENT,
    PRODUCTION
};

namespace Employee
{
    public class Employee : Person
    {
        private string mID;
        private DEPARTMENT mDepartment;
        private double mSalary;

        public string ID
        {
            set => mID = value;
            get => mID;
        }

        public DEPARTMENT depart
        {
            set { mDepartment = value; }
            get => mDepartment;
        }

        public double salary
        {
            set => mSalary = value;
            get => mSalary;
        }

        public override void setInformation()
        {
            base.setInformation();

            int dpt;

            do
            {
                Console.Write("Enter Department [0 - IT, 1 - MANAGEMENT, 2- PRODUCTION]:");
                dpt = Convert.ToInt32(Console.ReadLine());
            } while (!((dpt >= 0) && (dpt <= 2)));

            switch (dpt)
            {
                case 0: mDepartment = DEPARTMENT.IT; break;
                case 1: mDepartment = DEPARTMENT.MANAGEMENT; break;
                case 2: mDepartment = DEPARTMENT.PRODUCTION; break;
            }

            Console.Write("Enter Salary.................. : ");
            mSalary = Convert.ToDouble( Console.ReadLine());

        }

        public void increaseSalary(int percent)
        {
            mSalary = mSalary * (1 + ((double)percent / 100));
        }

        public override void printInformation()
        {
            Console.Clear();
            
            base.printInformation();

            Console.WriteLine("Department.............. : " + mDepartment);
            Console.WriteLine("Salary.................. : " + mSalary + " TL");

        }
    }
}
