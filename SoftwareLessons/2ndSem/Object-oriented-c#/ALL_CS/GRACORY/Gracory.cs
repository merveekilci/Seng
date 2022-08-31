using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Grocory Example
// id
// name
// type
// expiration date
enum CATEGORY
{
    DRINK,
    JUNK,           // abur cubur
    FOOD,
    STATIONARY,     // kırtasiye
    CLEANING
}


namespace GRACORY
{
    // students - deparments var
    // exam program

    // class dortgen sınıfı yazdır 
    // ekrana çizdir

    // sağa sola hareket ettir

    // expiration date - bugünün tarihinden daha ilerde olmalı
    // category yi yazdır

    class Product
    {
        private int mID;
        private string mName;
        private CATEGORY mCategory;
        private double mPrice;
        private DateTime mExpDate;
        // private int mCount           // add this field to your project and test it

        public int ID { set => mID = value; get => mID; }
        public string Name { set => mName = value; get => mName; }
        public CATEGORY category { set => mCategory = value; get => mCategory; }
        public double price { set => mPrice = value; get => mPrice; }
        public DateTime expDate { set => mExpDate = value; get => mExpDate; }


        public void setInformation()
        {
            Console.Write("Enter ID..................... : ");
            mID = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Name....................: ");
            mName = Console.ReadLine();

            int select;

            // the category should be between 0 and 4
            do
            {
                Console.Write("Enter Category................: ");
                select = Convert.ToInt32(Console.ReadLine());
            } while (!((select >= 0) && (select <= 4)));

            // testing
            mCategory = (CATEGORY)select;

            Console.Write("Enter Price...................: ");
            mPrice = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter Expiration Date.........: ");
            mExpDate = DateTime.Parse(Console.ReadLine());

        }

        public void printInformation()
        {
            Console.WriteLine("ID....................... : " + mID);
            Console.WriteLine("NAME..................... : " + mName);
            Console.WriteLine("CATEGORY................. : " + mCategory);
            Console.WriteLine("EXPIRATION DATE.......... : " + mExpDate);
            Console.WriteLine("PRICE.................... : " + mPrice + " TL");
        }

        public void increasePrice(int percent)
        {
            mPrice = mPrice * (1 + ((double)percent / 100));
            // 10/100 = 0
            // 10.0/100 = 0.1
        }


    }
}
