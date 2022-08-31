//************************************************
//*   STUDENT NAME:........ MERVE KILCI         **
//*   STUDENT NUMBER:...... B211202375          **
//************************************************
#include <iostream>  // input output library

using namespace std;

/*Grocery product
 1-Product Name
 2-Product ID
 3-Product Type (food,drink,junk,stationary)
 4-Price */

const int MAX = 10;   //max size is 10 so we use const int then it wont be change
                      // we use m inside of the  enum enumCategory because we want program to see 1 for FOOD
enum enumCategory { m, FOOD, DRINK, JUNK, STATIONARY };  //define an enumaration type named enumCategory
//product
//create a struct to store different type of elements together
struct Product {    //it keeps information of the product
    string productName;
    int productid = -4;
    enumCategory type;
    double price;
    double tax;
};
// creating function of the add Product
void addProduct(Product* Product2)

{
    char no_yes;
    int Category;
    enumCategory type;

    cout << "DO YOU WANT TO ADD NEW PRODUCT? Enter 'y' or 'n'" << endl;  //requesting from the user if they want to add new values
    cin >> no_yes;
    if (no_yes == 'y') {
        for (int i = 0; Product2->productid != -4; i++) {
            Product2++; //increasing of the product2
        }



        // outputing NAME,ID,PRICE,TYPE
        cout << "ENTER THE INFORMATIONS OF THE PRODUCT:" << endl;

        cout << "PRODUCT NAME.........................:";
        //The Arrow(->) operator exists to access the members of the structure or the unions using pointers
        cin >> Product2->productName;

        cout << "PRODUCT ID...........................:";
        cin >> Product2->productid;

        cout << "PRODUCT TYPE:[FOOD=>1,DRINK=>2,JUNK=>3,STATIONARY=>4:";
        cin >> Category;
        Product2->type = static_cast<enumCategory>(Category);  // it is a compile time cast

        cout << "PRODUCT PRICE........................:";
        cin >> Product2->price;
        //a cast operator is an unary operator which forces one data type to be converted into another data type
    }



}

//creating printProduct function
//will calculate tax informations
//will write all the informations
void printProduct(Product* proproducts) {

    //print the result of the screen until the defined value
    for (int i = 0; proproducts->productid != -4; i++)
    {
        cout << "PRODUCT NAME...............:" << proproducts->productName << endl;

        cout << "PRODUCT ID.................:" << proproducts->productid << endl;

        cout << "PRODUCT TYPE...............:";


//writing the type of the products
        //calculating the tax price
        switch (proproducts->type) {
        case 1:
            cout << "FOOD" << endl;
            proproducts->tax = proproducts->price * 3 / 100;
            break;

        case 2:
            cout << "DRINK" << endl;
            proproducts->tax = proproducts->price * 5 / 100;
            break;

        case 3:
            cout << "JUNK" << endl;
            proproducts->tax = proproducts->price * 18 / 100;
            break;

        case 4:
            cout << "STATIONARY" << endl;
            proproducts->tax = proproducts->price * 8 / 100;
            break;

        default:
            cout << "Please enter a valid type" << endl; //error
        }
        //writing on the screen
        cout << "PRODUCT PRICE......................:" << proproducts->price << endl;
        cout << "PRODUCT TAXPRICE...................:" << proproducts->tax << endl;
        cout << "-------------------------------------" << endl;

        proproducts++;
    }
}
//variables(informations) of the product list
Product products[10] = { {"BREAD",1,FOOD,3},{"AYRAN",2,DRINK,10},{"CHIPS",3,JUNK,9},{"PENCIL",4,STATIONARY,15},{},{},{},{},{},{} };





int main() {

    cout << "--------------------------------------------------------" << endl;
    cout << "-------------------PRODUCT LIST-------------------------" << endl;
    cout << "--------------------------------------------------------" << endl;

    products[0].tax = products[0].price * 3 / 100;
    products[1].tax = products[1].price * 5 / 100;
    products[2].tax = products[2].price * 18 / 100;
    products[3].tax = products[3].price * 8 / 100;
    for (int i = 0; i < 4; i++) {


        cout << "PRODUCT NAME....................:" << products[i].productName << endl;
        cout << "PRODUCT ID......................:" << products[i].productid << endl;
        cout << "PRODUCT TYPE................:";
        switch (products[i].type)   //we use switch-case to write the type of the product
                                    //food-drınk-junk-statıonary
        {
        case FOOD:
            cout << "FOOD" << endl;
            break;
        case DRINK:
            cout << "DRINK" << endl;
            break;
        case JUNK:
            cout << "JUNK" << endl;
            break;
        case STATIONARY:
            cout << "STATIONARY" << endl;
            break;
        default:
            cout << "unvalid type" << endl;
        }
        cout << "PRODUCT PRICE...................:" << products[i].price << "TL" << endl;
        cout << "PRODUCT TAX PRICE................" << products[i].tax << endl;
        cout << "--------------------------------------------------------" << endl;
    }
    for (int i = 5; i <= 10; i++) {

        addProduct(products);  //function call
        printProduct(products);
    }


    return 0;
}
