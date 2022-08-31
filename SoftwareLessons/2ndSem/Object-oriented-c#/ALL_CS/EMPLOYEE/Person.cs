using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Employee
{
    public class Person
    {
        private string mName;
        private string mSurName;
        private string mTelNumber;
        private char mGender;

        public string name
        {
            set => mName = value;
            get => mName;
        }

        public string surName
        {
            set => mSurName = value;
            get => mSurName;
        }

        public string telNumber
        {
            set => mTelNumber = value;
            get => mTelNumber;
        }

        public char gender
        {
            set => mGender = value;
            get => mGender;
        }

        public virtual void setInformation()
        {
            Console.Write("Enter Name.................... : ");
            mName = Console.ReadLine();

            Console.Write("Enter Surname................. : ");
            mSurName = Console.ReadLine();

            Console.Write("Enter Telephone Number........ : ");
            mTelNumber = Console.ReadLine();

            do
            {
                Console.Write("Enter Gender[F/M].............. : ");
                mGender = Convert.ToChar(Console.ReadLine());
            } while (!((mGender == 'F') || (mGender == 'M') || (mGender == 'm') || (mGender == 'f')));

        }

        public virtual void printInformation()
        {
            Console.WriteLine("Name.................... : " + mName);
            Console.WriteLine("Surname................. : " + mSurName);
            Console.WriteLine("Telephone Number........ : " + mTelNumber);
            Console.Write("Gender.................. : ");
            if (((mGender == 'f') || (mGender == 'F')))
                Console.WriteLine("FEMALE");
            else
                Console.WriteLine("MALE");


        }
    }
}
