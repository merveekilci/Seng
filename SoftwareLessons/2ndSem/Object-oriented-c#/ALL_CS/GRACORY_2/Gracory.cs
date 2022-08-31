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

    public interface Product
    {

        public int ID { set; get; }
        public string name { set; get; }
        public double price { set; get; }
        public int count { set; get; }

        public void setInformation();
        public void printInformation();
        public void increasePrice(int percent);

    }

    public class Drink : Product
    {
        private int mID;
        private string mName;
        private double mPrice;
        private DateTime mExpDate;
        private int mCount;           // add this field to your project and test it

        public int ID { set => mID = value; get => mID; }
        public string name { set => mName = value; get => mName; }
        public double price { set => mPrice = value; get => mPrice; }
        public DateTime expDate { set => mExpDate = value; get => mExpDate; }
        public int count { set => mCount = value; get => mCount; }

        public void setInformation()
        {
            Console.Write("Enter ID..................... : ");
            mID = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Name....................: ");
            mName = Console.ReadLine();

            Console.Write("Enter Price...................: ");
            mPrice = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter Expiration Date.........: ");
            mExpDate = DateTime.Parse(Console.ReadLine());

            Console.Write("Enter Product Count...........: ");
            count = Convert.ToInt32(Console.ReadLine());

        }

        public void printInformation()
        {
            Console.WriteLine("ID....................... : " + mID);
            Console.WriteLine("NAME..................... : " + mName);
            Console.WriteLine("EXPIRATION DATE.......... : " + mExpDate.ToString("MM/dd/yyyy"));
            Console.WriteLine("PRICE.................... : " + mPrice.ToString("#.##") + " TL");
            Console.WriteLine("COUNT.................... : " + mCount);
        }

        public void increasePrice(int percent)
        {
            mPrice = mPrice * (1 + ((double)percent / 100));
            // 10/100 = 0
            // 10.0/100 = 0.1
        }

    }

    public class Starionary : Product
    {
        private int mID;
        private string mName;
        private double mPrice;
        private int mCount;           // add this field to your project and test it

        public int ID { set => mID = value; get => mID; }
        public string name { set => mName = value; get => mName; }
        public double price { set => mPrice = value; get => mPrice; }
        public int count { set => mCount = value; get => mCount; }

        public void setInformation()
        {
            Console.Write("Enter ID..................... : ");
            mID = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter Name....................: ");
            mName = Console.ReadLine();

            Console.Write("Enter Price...................: ");
            mPrice = Convert.ToDouble(Console.ReadLine());

            Console.Write("Enter Product Count...........: ");
            count = Convert.ToInt32(Console.ReadLine());

        }

        public void printInformation()
        {
            Console.WriteLine("ID....................... : " + mID);
            Console.WriteLine("NAME..................... : " + mName);
            Console.WriteLine("PRICE.................... : " + mPrice.ToString("#.##") + " TL");
            Console.WriteLine("COUNT.................... : " + mCount);
        }

        public void increasePrice(int percent)
        {
            mPrice = mPrice * (1 + ((double)percent / 100));
            // 10/100 = 0
            // 10.0/100 = 0.1
        }

    }
}
