using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{

    static class AccSelect
    {
        static Account acc;
        public static  void Invoke()
        {
            Control con = Control.instance;//Control 객체 함수에 전달
            int id = wbLib.inputnumber("검색할 회원 ID");
            acc = con.SelectAccount(id);
        }


        static void Print()
        {
            acc.Print();
        }
    }
        
}
