using System.Collections.Generic;
using System;

namespace Lab6_second_semestr
{
    public class Program
    {
        private static int Count(char sym, string line)
        {
            int counter = 0;
            foreach(char s in line)
            {
                if(s == sym)
                {
                    counter++;
                }
            }
            return counter;
        }

        private static bool Contains(int j, string line)
        {
            for (int i = 0; i < j; i++)
            {
                if(line[j] == line[i])
                {
                    return true;
                }
            }

            return false;
        }
        private static BinaryTree Process(string line)
        {
            BinaryTree tree = new BinaryTree(line[0], Count(line[0],line), null);
            for (int i = 1; i < line.Length; i++)
            {
                if (!Contains(i, line))
                {
                    tree.Add(line[i], Count(line[i], line));
                }
            }
            return tree;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Введіть рядок символів");
            string line = Console.ReadLine();
            BinaryTree tree = Process(line);
            tree.PrintTree(tree,0);
        }
    }
}