using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class Inputmoney
    {
        public static void Invoke()
        {
            try
            {
                Control con = Control.Instance;
                con.addmoney(wblib.inputnumber("입금액"));
            }
            catch (Exception)
            {
                Console.WriteLine("잘못된 입력");
            }
        }
    }
}
