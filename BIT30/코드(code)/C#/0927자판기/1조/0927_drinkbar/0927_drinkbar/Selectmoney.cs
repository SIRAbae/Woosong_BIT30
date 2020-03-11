using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class Selectmoney
    {
        public static void Invoke()
        {
            try
            {
                Control con = Control.Instance;
                con.mch.printMenu();
                con.outputdrink(wblib.inputnumber("메뉴선택"));
            }
            catch (Exception)
            {
                Console.WriteLine("잘못된 입력");
            }
        }
    }
}
