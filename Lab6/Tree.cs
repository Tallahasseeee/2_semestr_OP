using System.Collections.Generic;
using System;

namespace Lab6_second_semestr
{
    public class BinaryTree
    {
        private BinaryTree parent, left = null, right = null;
        private char sym;
        private int val;

        public BinaryTree(char sym, int val, BinaryTree parent)
        {
            this.sym = sym;
            this.val = val;
            this.parent = parent;
        }

        public void Add(char sym, int val)
        {
            if (val < this.val)
            {
                if (this.left == null)
                {
                    this.left = new BinaryTree(sym, val, this);
                }
                else if (this.left != null)
                {
                    this.left.Add(sym, val);
                }
            }
            else
            {
                if (this.right == null)
                {
                    this.right = new BinaryTree(sym, val, this);
                }
                else if (this.right != null)
                {
                    this.right.Add(sym, val);
                }
            }
        }

         public void PrintTree(BinaryTree tree, int tabs)
        {
            if (tree == null)
            {
                return;
            }
            tree.PrintTree(tree.right, ++tabs);

            for (int i = 1; i < tabs; i++)
            {
                Console.Write("\t");
            }
            Console.Write(tree.sym + "\n");

            tree.PrintTree(tree.left, tabs);
        }


    }
}
