using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    /// <summary>
    /// 프로그램에서 반복적으로 사용되는 기능
    /// </summary>

    class WbLib

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
    }
}
