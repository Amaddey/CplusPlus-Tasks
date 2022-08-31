using System;
using System.Collections.Generic;
using System.Linq;

namespace SomeSpace
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {

                Console.Write($"Choose a task (1-6):");
                int choice = Convert.ToInt32(Console.ReadLine());
                switch (choice)
                {
                    case 1:
                        Console.WriteLine($"It's easy to win forgiveness for being wrong;");
                        Console.WriteLine($"being right is what gets you into real trouble");
                        Console.WriteLine($"Bjarne Stroustrup");
                        break;
                    case 2:
                        Console.WriteLine($"Enter 5 nums");
                        int[] mass = new int[5] { 0, 0, 0, 0, 0 };
                        int sum = 0, product = 1;

                        Console.WriteLine($"mass[{mass[0]}] :");
                        int firstNum = Convert.ToInt32(Console.ReadLine());
                        int max = firstNum, min = firstNum;
                        sum += firstNum;
                        for (int i = 1; i < mass.Length; i++)
                        {
                            Console.WriteLine($"mass[{i}] :");
                            int num = Convert.ToInt32(Console.ReadLine());
                            if (min > num)
                                min = num;
                            if (max < num)
                                max = num;
                            sum += num;
                            product *= num;
                        }

                        Console.WriteLine($"Sum of nums : {sum}");
                        Console.WriteLine($"Product of nums : {product}");
                        Console.WriteLine($"Max of nums : {max}");
                        Console.WriteLine($"Min of nums : {min}");
                        break;
                    case 3:

                        int[] massSix = new int[6];

                        for (int i = 0; i < massSix.Length; i++)
                        {
                            Console.Write($"massSix[{i}] :");
                            massSix[i] = Convert.ToInt32(Console.ReadLine());
                        }

                        Array.Reverse(massSix);

                        for (int i = 0; i < massSix.Length; i++)
                        {
                            Console.Write(massSix[i] + " ");
                        }
                        Console.WriteLine();

                        break;
                    case 4:

                        Console.Write("Enter a range of Fibonacci :");
                        int range = Convert.ToInt32(Console.ReadLine());
                        int a = 0, b = 1, c = 0;
                        Console.Write("{0} {1}", a, b);
                        for (int i = 2; i < range; i++)
                        {
                            c = a + b;
                            Console.Write(" {0} ", c);
                            a = b;
                            b = c;
                        }
                        Console.ReadLine();

                        break;
                    case 5:

                        Console.WriteLine("Eneter A: ");
                        int a1 = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine("Eneter B: ");
                        int b1 = Convert.ToInt32(Console.ReadLine());

                        for (int i = a1; i <= b1; i++)
                        {
                            for (int k = 0; k < i; k++)
                            {
                                Console.Write(i + " ");
                            }
                            Console.WriteLine();
                        }

                        break;
                    case 6:

                        Console.Write("1 - horizontal, 2 - vertical :");
                        int g = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Symbols :");
                        int sym = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Sign :");
                        char sign = Console.ReadKey().KeyChar;
                        Console.WriteLine();

                        if (1 == g)
                        {
                            for (int i = 0; i < sym; i++)
                            {
                                Console.Write(sign);
                            }
                            Console.WriteLine();
                        }
                        else if(2 == g)
                        {
                            for (int i = 0; i < sym; i++)
                            {
                                Console.WriteLine(sign);
                            }
                            Console.WriteLine();
                        }
                        else
                        {
                            Console.WriteLine("Nope.");
                        }
                       

                        break;
                    default:
                        System.Console.WriteLine("Error");
                        break;
                }
            }
        }
    }
}

