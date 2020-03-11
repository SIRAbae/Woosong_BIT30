using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
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
                    case ConsoleKey.F1: con.insert(); break;
                    case ConsoleKey.F2: con.update(); break;
                    case ConsoleKey.F3: con.update1(); break;
                    case ConsoleKey.F4: con.select(); break;
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
