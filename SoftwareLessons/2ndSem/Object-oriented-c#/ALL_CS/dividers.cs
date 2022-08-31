using System;
using System.Collections;           // for array list

namespace week5_
{
    class Program
    {
        static void Main(string[] args)
        {
            Number number1 = new Number(); //Number number1 = new();
            number1.num = 13;

            number1.printNumber();

            number1.printIsOdd();
            number1.printIsPrime();

            Console.WriteLine("-----------------------");

            Number number2 = new Number(10);
            number2.printNumber();

            number2.num = 15;
            number2.printNumber();

            number2.printDividers();



        }
    }
}
