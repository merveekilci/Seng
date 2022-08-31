
//********************************************************************
//**                                                                **  
//**        STUDENT NAME : MERVE KILCI                              **
//**        STUDENT NUMBER : B211202375                             **
//********************************************************************



using System;

namespace final2
{
    interface ICrypt // interface with members
    {

        string message { set; get; }  //interface field 
        string password { set; get; }


        public string KeyLength(string strText, string keyText);  //interface methods 
        public string encrypt(string strText, string keyText);
        public string decrypt(string strText, string keyText);
        public void printEncryptedMessage(string encryptedMessage);
        public void printDecryptedMessage(string decryptedMessage);
    }

    // inherited from ICrypt
    class CRYPT : ICrypt
    {
        private string str;
        private string key;

        public string message { get => str; set => message = value; }  //implementatitons
        public string password { get => key; set => key = value; }

        public CRYPT() //default constructor 
        {

        }
        public string Message // properties 
        {
            get { return str; }
            set { str = value; }
        }
        public string Password // properties 
        {
            get { return key; }
            set { key = value; }

        }

        public CRYPT(string strText, string keyText)
        {
            bool result = true;
            for (int i = 0; i < strText.Length; i++) // removing whitespaces
                                                     // from the message
            {

                result = Char.IsWhiteSpace(strText, i);
                if (result == false)
                {
                    strText = strText.Replace(" ", "");

                }
                else break;
            }
            
            //we are declearing the variables in here
            //because we are using interface method so that we need to declare this parameters in the class
            string finalKey = KeyLength(strText, keyText);
            string encryptedMess = encrypt(strText, finalKey);
            string decryptedMess = decrypt(encryptedMess, finalKey);

            printEncryptedMessage(encryptedMess);   //calling functions
                                                    //with the constructor
            printDecryptedMessage(decryptedMess);

        }

        public string KeyLength(string strText, string keyText)
        {
            int x = strText.Length;

            for (int i = 0; ; i++)
            {
                if (x == i)
                    i = 0;
                if (keyText.Length == strText.Length)
                    break;
                keyText += (keyText[i]);
            }
            return keyText;
        }

        public string encrypt(string strText, string keyText)  //this function makes encryption in the range of 0-25
            //with the help of ASCII table
            //Program will use ToUpper method
            //because if we gonna use small letter it will make an error
            //so that we need to change it to the upper letter
        {
            string encrypt_text = "";

            for (int i = 0; i < strText.Length; i++)
            {
                
                int x = (strText.ToUpper()[i] + keyText.ToUpper()[i]) % 26;   // converting in range 0-25


                x += 'A';   // convert to the alphabets(ASCII)

                encrypt_text += (char)(x);
            }
            return encrypt_text;
        }


        public string decrypt(string strText, string keyText)   //this function decrypting the message to the original
            //with the help of ASCII table 
        {
            string decrypt_text = "";
            for (int i = 0; i < strText.Length; i++)
            {
                
                int x = (strText.ToUpper()[i] - keyText.ToUpper()[i] + 26) % 26;  // converting in range 0-25

               
                x += 'A';
                decrypt_text += (char)(x);   // convert to the alphabets(ASCII)
            }
            return decrypt_text;
        }

        public void printEncryptedMessage(string encryptedMess)  //program will write the results on the screen
            //we have called encryptedMess on the constructor
            //so that we can access in here. We can not access it from the main class 
        {

            Console.WriteLine("ENCRYPTED MESSAGE  :" + encryptedMess);
        }

        public void printDecryptedMessage(string decryptedMess)  //we will see the original text 
        {

            Console.WriteLine("DECRYPTED MESSAGE  :" + decryptedMess);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("ENTER A PASSWORD...:");   //user will enter the values from the keyboard

            string key = Console.ReadLine();   //entering the password 

            Console.Write("ENTER A MESSAGE....:");
            string message = Console.ReadLine();  //entering the message 

            Console.WriteLine("--------------------------------------");  //we are using this sign to see better 

            Console.WriteLine("PASSWORD           :" + key);     //program will show this values which is entered from the keyboard 
            Console.WriteLine("MESSAGE            :" + message);

            Console.WriteLine("--------------------------------------");

            CRYPT Input = new CRYPT(message, key);  //create an object called Input


            Console.WriteLine("--------------------------------------");

        }
    }

}
