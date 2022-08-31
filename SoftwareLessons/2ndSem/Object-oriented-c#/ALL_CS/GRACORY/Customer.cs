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
        private Product mProduct;       // composition

        public int customerID { set => mCustomerID = value; get => mCustomerID; }
        public Product product { set => mProduct = value; get => mProduct; }

        public void addProduct(Product product)
        {
            mProduct = product;
        }

        public void printInformation()
        {
            Console.WriteLine("CUSTOMER ID................. : " + mCustomerID);
            mProduct.printInformation();
        }

    }
}
