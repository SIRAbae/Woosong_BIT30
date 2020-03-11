using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class Slotlib
    {
        public static int inputnumber(string msg)
        {
            Console.Write(msg + " : ");
            return int.Parse(Console.ReadLine());
        }

        public static string inputstring(string msg)
        {
            Console.Write(msg + " : ");
            return Console.ReadLine();
        }

        public static int inputmoney(string msg)
        {
            Console.Write(msg + " : ");
            int i = int.Parse(Console.ReadLine());
            //int.Parse(Console.ReadLine());

            if (i >= 0)
            {

                return i;
            }
            else
                throw new Exception("마이너스값을 넣을 순없지");
        }
    }
}
