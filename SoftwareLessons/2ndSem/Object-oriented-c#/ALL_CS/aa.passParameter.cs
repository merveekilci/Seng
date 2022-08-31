using System;

namespace passParameter
{
    class Program
    {
        static void Main(string[] args)
        {
            int number1=10;
            //Console.WriteLine("The initial value of number is " + number1);
            passByRef(ref number1);
            Console.WriteLine("The current value of number1 is " + number1);

            Console.WriteLine("--------------------------------------");
            
            // number2 is not initialized
            int number2=5;
            //Console.WriteLine("The initial value of number2 is " + number2);
            passByOut(out number2);
            Console.WriteLine("The current value of number2 is " + number2);

        }



        static void passByRef(ref int num)
        {
            num = 100;
        }

        static void passByOut(out int num)
        {
            num = 100;
        }
    }
}
