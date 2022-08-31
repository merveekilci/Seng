using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GRACORY
{
    class Customer
    {
        private int mCustomerID;
        private List<Drink> mDrinks;       
        private List<object> mProducts;
        private List<int> mProductCount;

        public int customerID { set => mCustomerID = value; get => mCustomerID; }
        public List<object> products { set => mProducts = value; get => mProducts; }
        public List<int> productCount { set => mProductCount = value; get => mProductCount; }
        //public List<Drink> drinks { set => mDrinks = value; get => mDrinks;}

        public Customer(){
            //mDrinks = new List<Drink>();
            //drinks  = new List<Drink>();

            mProducts = new List<object>();
            products  = new List<object>();

            mProductCount = new List<int>();
            productCount = new List<int>();
        }

        

        public void addProduct(object product, int count)
        {
            // buraya bir switch case yaz...
            //object _product = new object();

            //_product = product;
            

            mProducts.Add(product);
            mProductCount.Add(count);

            //product.count -= count ;
        }

        public void printInformation()
        {
            Console.WriteLine("CUSTOMER ID.............. : " + mCustomerID);

            /*for (int i = 0; i < mProducts.Count; i++)
            {
                switch (mProducts[i])
                {
                    case Drink drink: drink.printInformation(); ; break;
                }
                Console.WriteLine("PRODUCT COUNT............ : " + mProductCount[i]);
            }*/

            // here we can not write the counts of products on the screen, because it needs classical for loop
            /*foreach (object i in mProducts)
            {
                if (i is Drink drink)
                    drink.printInformation();
                else if (i is Starionary stationary)
                    stationary.printInformation();
            }*/

            for (int i = 0; i < mProducts.Count; i++)
            {
                if (mProducts[i] is Drink drink)
                    drink.printInformation();
                else if (mProducts[i] is Starionary stationary)
                    stationary.printInformation();

                Console.WriteLine("PRODUCT COUNT............ : " + mProductCount[i]);
                Console.WriteLine("********************************************");
            }
        }

        /*public void addProduct(Drink drink)
        {
            mDrinks.Add(drink);
            drink.count--;
        }

        public void printInformation()
        {
            Console.WriteLine("CUSTOMER ID................. : " + mCustomerID);

            for (int i=0; i<  mDrinks.Count; i++) { 
                mDrinks[i].printInformation();
            }
        }*/

    }
}
