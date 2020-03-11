using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{
    class AccInsert
    {
        static public void Invoke()
        {
            try
            {
                Control con = Control.instance;
                string name = wbLib.inputstring("이름");
                int id = wbLib.inputnumber("계좌번호");
                int balance = wbLib.inputnumber("입 금 액");

                Account acc = new Account(id, name, balance);

                if (con.AddAccount(acc) == true)
                    Console.WriteLine("저장 성공");
                else
                    Console.WriteLine("저장 실패");
            }

            catch (Exception ex)
            {
                Console.WriteLine("입력 오류");
                Console.WriteLine(">> " + ex.Message);
            }
        }
    }
}

