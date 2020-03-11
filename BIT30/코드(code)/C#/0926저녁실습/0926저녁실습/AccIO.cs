using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{

    static class AccIO
    {
        static Account acc;
        public static void Invoke(bool b)
        {
            try
            {
                Control con = Control.instance;//Control 객체 함수에 전달
                int id = wbLib.inputnumber("회원 ID ");
                int Balance = wbLib.inputnumber("입금할 금액");
                if (b == true)
                    con.InputAccount(id, Balance);
                else if (b == false)
                    con.outputAccount(id, Balance);

                Console.WriteLine("거래 성공 / 완료");
            }
            catch (Exception ex)
            {
                Console.WriteLine("거래 실패");
                
            }
        }
    }

}
