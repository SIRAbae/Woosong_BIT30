using System;
using System.Collections.Generic;
using System.Text;

namespace _0926저녁실습
{
    class Application
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
                AccPrintAll.Invoke();
                Wbprint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: AccInsert.Invoke(); break;
                    case ConsoleKey.F2: AccIO.Invoke(true); break;
                    case ConsoleKey.F3: AccIO.Invoke(false); break;
                    case ConsoleKey.F4: AccSelect.Invoke(); break; 
                    case ConsoleKey.F5: AccPrintAll.Invoke(); break;
                    case ConsoleKey.F6: AccDelete.Invoke(); break;
                    case ConsoleKey.F7: AccSort.Invoke(true); break;
                    case ConsoleKey.Escape: break;
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
