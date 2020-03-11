using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    class Application
    {
        AccountAddr ma = null;
        AccountViewer mv = null;

        internal static Application Singleton
        {
            get;
            private set;
        }

        static Application()
        {
            Singleton = new Application();
        }

        private Application()
        {
            ma = new AccountAddr();
            mv = new AccountViewer();
        }

        internal void Run()
        {
            while (true)
            {
                Console.Clear();
                mv.PrintAll();
                menuprint();
                ConsoleKeyInfo info = Console.ReadKey();

                switch (info.Key)
                {
                    case ConsoleKey.F1: ma.AddAccount(); break;
                    case ConsoleKey.F2: ma.Deposit(); break;
                    case ConsoleKey.F3: ma.Withdraw(); break;
                    case ConsoleKey.F4: ma.SelectAccount(); break;
                    case ConsoleKey.F5: ma.DeleteAccount(); break;
                    case ConsoleKey.F6: ma.TransferAccount(); break;
                    case ConsoleKey.F7: ma.SelectName(); break;
                    //case ConsoleKey.F8: bank.BubbleBubble(); break;
                    case ConsoleKey.Escape: return;


                }
            }
        }

        void menuprint()
        {
            Console.WriteLine("---------------- MENU  --------------");
            Console.WriteLine("[F1] 계좌 개설");
            Console.WriteLine("[F2] 입 금");
            Console.WriteLine("[F3] 출 금");
            Console.WriteLine("[F4] 계좌 조회");
            Console.WriteLine("[F5] 계좌 삭제");
            Console.WriteLine("[F6] 계좌 이체");    //1.입금계좌 2.출금계좌 3.입금액
            Console.WriteLine("[F7] 이름으로 계좌 검색 - 다중 검색");
            Console.WriteLine("[F8] 잔액 기반으로 내림차순 출력");
            Console.WriteLine("[ESC] 프로그램 종료");
            Console.WriteLine("-------------------------------------\n");
        }
    }
}
        