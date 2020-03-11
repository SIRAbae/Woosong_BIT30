using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class SelectDrink
    {

        static public void Invoke()
        {
            try
            {
                con.mech.printmenu();
                Control con = Control.instance;
            }
            catch (Exception ex)
            {
                Console.WriteLine("입력 오류");
            }
        }

    }
}


