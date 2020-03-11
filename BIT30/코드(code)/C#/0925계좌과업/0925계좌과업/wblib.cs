using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
{
    /// <summary>
    /// 프로그램에서 반복적으로 사용되는 기능
    /// </summary>
    class wblib
    {
        public static int inputnember(string msg)
        {
            Console.Write(msg + " : ");
            return int.Parse(Console.ReadLine());
        }


        public static string Inputstring(string msg)
        {
            Console.Write(msg + " : ");
            return Console.ReadLine();
        }
    }
}
