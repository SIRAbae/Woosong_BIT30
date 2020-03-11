using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{
   static class AccDelete
    {
        public static void Invoke()
        {
            Control con = Control.instance;//Control 객체 함수에 전달
            int id = wbLib.inputnumber("회원 ID ");

            if (con.DelAccount(id) == true)
                Console.WriteLine("삭제 성공");
            else if (con.DelAccount(id) == false)
                Console.WriteLine("삭제 실패");
        }
    }
}
