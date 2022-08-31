using System;

namespace Indexer
{
    class Program
    {
        static void Main(string[] args)
        {
            Sentence sentence1 = new Sentence();
            
            sentence1[0] = "Tuesday";
            sentence1.printWords();

            Sentence sentence2 =new Sentence( "Tomorrow is Wednesday");
            sentence2[4] = "Thursday";
            Console.WriteLine(sentence2[0]);
        }
    }
}
