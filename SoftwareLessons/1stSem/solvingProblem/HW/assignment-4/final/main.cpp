//***************************************
//**Student Name: Merve  KILCI **********
//**Student Number: b211202375 **********
//***************************************
//30.12.2021
//Homework-4 problem solving in software engineering

#include <iostream>  //general input aoutput library
#include <string>    //we use string variable
#include <cctype>    //“For character classification function”
#include <algorithm> //for the transform() function



bool all_alpha(const std::string str)
//bool controls-- true if all characters are alpha, else false.


{
    
    for (auto c : str)
        
        if (!isalpha(c))   //checks if the character is alphabetic
                           //we can do this with the help of isalpha
            
            return false;
    
    return true;

}

int char_to_int(const char c)
     
    // c char value to convert
{   //this command converting a char to integer value
    
    if (c >= 'A' && c <= 'Z') // scale upper-case
        
        return (c - 'A');
    
    else if (c >= 'a' && c <= 'z') // scale lower-case
        
        return (c - 'a');
    
    else
        
        return -1;
}


 
 
//converting an integer to char  (int_to_char)
char int_to_char(const int i, bool is_upper = true) {
    
    // i can not be change because we define as const
    
    //i is the integer value to convert
    if (i >= 0 && i < 26)
        return (
            is_upper ? (i + 'A') : (i + 'a')
                
                //is_upper Base on which the integer to be scaled
        );
    else
        return 0;
}


 
 
 
//password Key for the encryption of the code
//Encrypted ciphertext
//vigenère encryption so we defined as encrypt
//message Message wii be encrypted
std::string encrypt(std::string message, const std::string password)

{
    long i = 0; // we use i as a counter.
    for (auto &c : message) // for each character
        
        if (isalpha(c)) // if it is alpha
            
            c = int_to_char((
                    char_to_int(c) + char_to_int(password[(i++) % password.size()])
    // duplicate the password (which entered by )all through the message
    // it is ignoring spaces
                             
                             
                        ) % 26,
                isupper(c)  //checks if a given character is uppercase

    //  output case should be consistent with the input
            );
    
    return message; //encrypted text.
}


 
 
 //message Ciphertext to be decrypt
//decryption of Vigenère and decrypted message
std::string decrypt(std::string message, const std::string password) {
    
    //password Key for the decryption of the code
    
    long i = 0;
    
    // i as a counter.
    
    for (auto &c : message)
        
        if (isalpha(c)) {
            // it checks
            // make an inverse operation of what was done before
            int u = char_to_int(c) - char_to_int(password[(i++) % password.size()]);
            
            // in the encryption duplicate the password again and substract what added before.
            
            c = int_to_char(
                (u < 0) ? (u + 26) : u, isupper(c)
            );
           
        }
    
    return message;
    //codes decrypted messages
}


int main(int argc, char **argv)

{
    // message to be encrypted or decrypted
    //C++ getline() is a standard library function that is used to read a string or a line from an input stream
    std::string password, message;
    
    std::cout << "Enter a password......: ", std::getline(std::cin, password);
    std::cout << "Enter a  message......: ", std::getline(std::cin,  message);
    std::cout << "---------------------------------------------------" << std::endl;
   
    
    
    if (password.empty() || !all_alpha(password))   // if the given key is empty or include unwanted one gives and error
    {
        std::cout << "Check the given parameters, please" << std::endl;
        return -1;
       
    }

   
  
    
    std::transform(
                   
    //applies an operation sequentially to the elements of one (1) or two (2) ranges and stores the result in the range that begins at result
        
                   password.begin(), password.end(),
       
                   password.begin(), ::toupper
                   //converts a lowercase character to uppercase
    );
    
    std::cout << "PASSWORD           :" << password << std::endl;
      std::cout << "MESSAGE            :" << message << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
    // do the calculations
    //output the return values
    
    std::cout
    << "Encrypted message.....: " << encrypt(message, password) << std::endl
              << "Decrypted message.....: " << decrypt(message, password) << std::endl;
              
    std::cout << "---------------------------------------------------" << std::endl;
    return 0;
}

