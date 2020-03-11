using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class App
    {
        SlotPrint sp = new SlotPrint();
        public void Init()
        {
            sp.logo();
            sp.Print();
            SlotPrint.menuprint();
        }
        public void Run()
        {
            while (true)
            {
                Console.Clear();
                sp.Print();
                SlotPrint.menuprint();

                switch (Console.ReadKey().Key)
                {

                    case ConsoleKey.F1: SlotControl.Instance.InputMoney(); break;
                    case ConsoleKey.F2: SlotControl.Instance.Choice(); break;
                    case ConsoleKey.F3: SlotControl.Instance.Return(); break;


                    case ConsoleKey.Escape: return;

                }
                SlotPrint.pause();
            }
        }

        //public void exit()
        //{
        //    wbprint.ending();
        //}

        //public bool check()
        //{
        //    int i = wblib.inputnumber("[1]입금 [2]출금");

        //    switch (i)
        //    {
        //        case 1: AccIo.Invoke(true); break;
        //        case 2: AccIo.Invoke(false); break;
        //    }
        //    return true;
        //}
    }
}
