using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class Outputmoney
    {

        public static void Invoke()
        {
            try
            {
                Control con = Control.Instance;
                con.OutMoney();
            }
            catch (Exception)
            {
                Console.WriteLine("잔돈반환실패");
            }
        }

    }
}
