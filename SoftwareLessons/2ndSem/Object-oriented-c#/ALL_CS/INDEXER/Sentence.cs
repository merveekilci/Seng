using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Indexer
{
    // divide each sentence by indexer
    class Sentence
    {
        private string[] mWords;

        public string this[int wordIndex]
        {
            get
            {
                try
                {
                    return mWords[wordIndex];
                }
                catch (IndexOutOfRangeException)
                {
                    return "Out of Range!...";
                }

            }
            set
            {
                try
                {
                    mWords[wordIndex] = value;
                }
                catch (IndexOutOfRangeException)
                {
                    Console.WriteLine( "Out of Range!...");
                }

                //if ((wordIndex < 0) || (wordIndex >= mWords.Length))
                //    throw new IndexOutOfRangeException("Out of Range...");

                //mWords[wordIndex] = value;
            }
        }

        public Sentence()
        {
            mWords = "Today is Object Oriented Programming Day".Split();
        }

        public Sentence(string sentence)
        {
            mWords = sentence.Split();
        }

        public void printWords()
        {
            foreach (string word in mWords)
                Console.WriteLine(word);
        }


    }
}
