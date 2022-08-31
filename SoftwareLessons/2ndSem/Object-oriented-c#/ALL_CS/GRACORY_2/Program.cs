using System;

namespace GRACORY
{
    class Program
    {
        static void Main(string[] args)
        {
            Drink drink1 = new Drink();

            //product1.setInformation();
            drink1.ID = 1;
            drink1.name = "AYRAN";
            drink1.price = 100;
            drink1.expDate = DateTime.Parse("10/06/2021");
            drink1.count = 100;

            //drink1.printInformation();

            drink1.increasePrice(10);

            
            Drink drink2 = new Drink();

            drink2.ID = 2;
            drink2.name = "SÜT";
            drink2.price = 50;
            drink2.expDate = DateTime.Parse("01/06/2021");
            drink2.count = 100;

            Starionary starionary1 = new Starionary();

            starionary1.ID = 1;
            starionary1.name = "PEN";
            starionary1.price = 5.0;
            starionary1.count = 10;

            Customer customer1 = new Customer();
            customer1.customerID = 2;

            customer1.addProduct(drink1, 2);
            customer1.addProduct(drink2,3);
            customer1.addProduct(starionary1, 1);

            customer1.printInformation();

        }
    }
}
