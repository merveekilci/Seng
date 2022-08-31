using System;

namespace CLASSES
{
    class Program
    {
        static void Main(string[] args)
        {
            Number number1 = new Number();
            Console.WriteLine("initial value : " + number1.value);
            number1.value = 10;
            number1.value = 20;
            Console.WriteLine("changed value : " + number1.value);

            //STATIC CLASS EXAMPLE
            //staticClass object1 = new staticClass();
            //staticClass object2 = new staticClass();

            //Console.WriteLine(staticClass.getCount());


            // LINE CLASS EXAMPLE

            /*
            Point p1 = new Point(2, 2);
            Point p2 = new Point(8, 6);

            Line line1 = new Line(p1, p2);
            line1.drawCoordinates('*');


            Point p3 = new Point(20, 20);
            Point p4 = new Point(40, 40);

            Line line2 = new Line(p3, p4);
            line2.drawCoordinates('*');
            line2.writeLength();
            */

            //RECTANGLE EXAMPLE
            /*Rectangle d1 = new Rectangle();

            d1.topLeft = new Point() { x = 5, y = 10 };
            d1.width = 5;
            d1.height = 8;

            d1.draw();

            Point test = new Point(20, 40);

            Rectangle d2 = new Rectangle()
            {
                topLeft = test,
                width = 10,
                height = 5
            };

            d2.draw();
            */


            //Console.Write("Enter a Number:");
            //int number = Convert.ToInt32(Console.ReadLine());

            //Number number1 = new Number(number);

            //number1.value = 23;

            //number1.printIsPrime();
            //Console.WriteLine( number1.convertToWords());

            /*Complex number1 = new Complex();
            Complex number2 = new Complex(5,12);

            number1.real = 3;
            number1.imaginary = 4;

            number1.printMagnitude();
            number2.printMagnitude();

            number1.calculateLength(number2);
            */

            int number;

            do
            {
                Console.Write("Enter a four-digit number:");
                number = Convert.ToInt32(Console.ReadLine());
            } while (!((number >= 1000) && (number <= 9999)));


            string message = Convert.ToString(number);

            string encryptedMessage = encrypt(message);
            string decryptedMessage = decrypt(encryptedMessage);

            Console.WriteLine("Encrypted Message......: " + encryptedMessage);
            Console.WriteLine("Decrypted Message......: " + decryptedMessage);


        }

        static string encrypt(string message)
        {
            int[] digits = new int[4];

            for (int i = 0; i < 4; i++)
            {
                digits[i] = Convert.ToInt32(message.Substring(i, 1));
                digits[i] = (digits[i] + 7) % 10;
            }

            int swap;

            swap = digits[0];
            digits[0] = digits[2];
            digits[2] = swap;

            swap = digits[1];
            digits[1] = digits[3];
            digits[3] = swap;

            string m = Convert.ToString(digits[0]) + Convert.ToString(digits[1]) +
                       Convert.ToString(digits[2]) + Convert.ToString(digits[3]);

            return m;
        }

        static string decrypt(string message)
        {
            int[] digits = new int[4];

            for (int i = 0; i < 4; i++)
            {
                digits[i] = Convert.ToInt32(message.Substring(i, 1));
                digits[i] = (digits[i] + 3) % 10;
            }

            int swap;

            swap = digits[0];
            digits[0] = digits[2];
            digits[2] = swap;

            swap = digits[1];
            digits[1] = digits[3];
            digits[3] = swap;

            string m = Convert.ToString(digits[0]) + Convert.ToString(digits[1]) +
                       Convert.ToString(digits[2]) + Convert.ToString(digits[3]);

            return m;
        }

    }
}

