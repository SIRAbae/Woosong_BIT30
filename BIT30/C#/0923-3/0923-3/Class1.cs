using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923_3
{
    public class Calculator
    {

        public static int Plus(int a = 0, int b = 0)
        {
            Console.WriteLine("Input:{0}, {1}", a, b);
            int result = a + b;
            return result;
        }


        public static void foo()
        {
            int x = Plus(3); //x는 7
            int y = Plus(5, 6); //y는 11
        }
        
    }

   //static void Main(string[] args)
     


}
