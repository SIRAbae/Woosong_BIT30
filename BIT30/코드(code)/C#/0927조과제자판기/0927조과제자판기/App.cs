using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class App
    {

        public void init()
        {
            Wbprint.logo();
            // con.fileload();

        }

        public void run()
        {
            while (true)
            {
                Console.Clear();
                Wbprint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: InputMoney.Invoke(); break;
                    case ConsoleKey.F2: SelectDrink.Invoke(true); break;
                    //case ConsoleKey.F3: AccIO.Invoke(false); break;
                    //case ConsoleKey.F4: AccSelect.Invoke(); break;
                    //case ConsoleKey.F5: AccPrintAll.Invoke(); break;
                    //case ConsoleKey.F6: AccDelete.Invoke(); break;
                    //case ConsoleKey.F7: AccSort.Invoke(true); break;
                    //case ConsoleKey.Escape: break;
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

