using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _identity
{
    class Identity
    {
        private long mNumber;
        public long number { set=>mNumber=value; get=>mNumber; }

        public Identity()
        { }

        public Identity(long number)
        {
            mNumber = number;
        }

        private bool checkNumber()
        {
            bool check = false;

            byte[] digits = new byte[11];

            string test = mNumber.ToString();
            Console.WriteLine(test);

            for (int i = 0; i < 11; i++)
                digits[i] = Convert.ToByte(test.Substring(i, 1));

            //Console.WriteLine("1. Letter : " + test[0]);
            //Console.WriteLine("1. Digit : " + digits[0]);

            //c1 = ((d1 + d3 + d5 + d7 + d9) * 7 - (d2 + d4 + d6 + d8)) mod10
            //c2 = (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + c1) mod10

            int check1 =(digits[0] + digits[2] + digits[4] + digits[6]) + digits[8];
            check1 *= 7;
            check1 -= digits[1] + digits[3] + digits[5] + digits[7];
            check1 %= 10;

            if (check1 == digits[9])
            { 
                int check2 = (digits[0] + digits[1] + digits[2] + digits[3]) + digits[4];
                check2 += digits[5] + digits[6] + digits[7] + digits[8] + digits[9];
                check2 %= 10;

                if (check2 == digits[10])   check=true;
            }

            return check;
        }

        public void printCheckedNumber()
        {
            if (checkNumber())
                Console.WriteLine("Valid");
            else
                Console.WriteLine("Not Valid");
        }
    }
}
