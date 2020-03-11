using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{
    class AccPrintAll
    {
        static List<Account> acc;

        static public void Invoke()
        {
            Control con = Control.instance;
            con.SelectAllAccount(out acc);
            Printall();

        }
        static void Printall()
        {
            Console.WriteLine("저장개수 : {0}개", acc.Count);
            for (int i = 0; i < acc.Count; i++)
            {
                Account mem = acc[i];
                Console.WriteLine(mem);
            }
        }
    }
}
