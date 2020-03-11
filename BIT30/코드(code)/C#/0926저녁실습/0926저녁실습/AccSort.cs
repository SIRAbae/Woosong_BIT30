using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{
    class AccSort
    {
        static Account acc;
        public static void Invoke(bool b)
        {
            Control con = Control.instance;//Control 객체 함수에 전달
            Console.WriteLine("저장방식>>");
            string idx = wbLib.inputstring("[1]계좌번호 [2]이름 [3]잔액");

            con.SortAccount(idx);

        }
    }
}
