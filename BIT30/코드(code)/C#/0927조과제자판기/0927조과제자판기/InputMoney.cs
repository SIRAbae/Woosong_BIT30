using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class InputMoney
    {


        static Drink ink;
        static public void Invoke()
        {
            try
            {
                
                int money = WbLib.inputnumber("입금할 금액");
                Control con = Control.instance;
                con.addmoney(money);
                Console.WriteLine("금액 투입 완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("거래 실패");

            }
        }
    }
}
