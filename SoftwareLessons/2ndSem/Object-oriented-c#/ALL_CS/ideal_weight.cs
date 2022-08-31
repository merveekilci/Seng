using System;

namespace ex3
{
    class Program
    {
        
        static void Main(string[] args)
        {
            // program that calculates ideal weight of a person
			// ideal_weight = (height - 100 + age/10)*0.8   (for female)
			// ideal_weight = (height - 100 + age/10)*0.9   (for male)
            Console.Write("Enter Your Height:");
            int height = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Your Age:");
            int age = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Your Gender [M/F]:");
            char gender = Convert.ToChar(Console.ReadLine());

        
            Console.WriteLine("Your Ideal Weight is " + calcIdealWeight(height,age,gender) + " kg");
        }


        /*In C# there is a distinction between functions 
        that operate on instances (non-static) and 
        functions that do not operate on instances (static). 
        Instance functions can call other instance functions and 
        static functions because they have an implicit reference to the instance. 
        In contrast, static functions can call only static functions, or 
        else they must explicitly provide an instance on which to call a non-static function.

        Since public static void Main(string[] args) is static, 
        all functions that it calls need to be static as well.*/
        static public float calcIdealWeight(int _height, int _age, char _gender)
        {
            float ideal;
            if ((_gender=='F') || (_gender=='f'))
                ideal=(_height-100)+(_age/10)*0.8f;
            else
                ideal=(_height-100)+(_age/10)*0.9f;

            return ideal;
        }
    }
}
