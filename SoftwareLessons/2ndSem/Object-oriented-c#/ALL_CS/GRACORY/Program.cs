using System;

namespace GRACORY
{
    class Program
    {
        static void Main(string[] args)
        {
            // we will add a product class
            // we will add a customer class
            //Console.WriteLine("Hello World!");

            Product product1 = new Product();

            //product1.setInformation();
            product1.ID = 1;
            product1.Name = "xxxx";
            product1.category = (CATEGORY)2;
            product1.price = 100;
            product1.expDate = DateTime.Parse("01/01/2022");


            //product1.printInformation();

            product1.increasePrice(10);


            Customer customer1 = new Customer();
            customer1.customerID = 2;

            customer1.addProduct(product1);
            customer1.printInformation();

        }
    }
}
