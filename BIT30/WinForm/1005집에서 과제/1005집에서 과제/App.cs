using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1005집에서_과제
{
    class App
    {
        Control con = new Control();

        public void init()
        {


            Wbprint.logo();
        }

        public void run()
        {
            while (true)
            {
                Console.Clear();
                con.printall();
                Wbprint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: con.Inputmoney(); break;
                    case ConsoleKey.F2: con.SelectDrink(); break;
                    case ConsoleKey.F3: con.ReturnMoney(); break;
                    case ConsoleKey.Escape: exit(); break;
                }
                Wbprint.pause();
            }
        }



        public void exit()
        {
            Wbprint.ending();
        }

    }
}

