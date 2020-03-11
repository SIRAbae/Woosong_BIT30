using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class wbprint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("******************************************");
            Console.WriteLine("2019.9.27");
            Console.WriteLine("우송비트고급30기 C#언어 과정");
            Console.WriteLine("자판기 프로그램");
            Console.WriteLine("ssg");
            Console.WriteLine("******************************************");
            pause();

        }

        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("******************************************");
            Console.WriteLine("자판기 프로그램");
            Console.WriteLine("프로그램 종료");
            Console.WriteLine("******************************************");
            pause();

        }

        public static void menuprint()
        {
            Console.Clear();
            Console.WriteLine("******************************************");
            Console.WriteLine("[1] 자판기에 돈을 넣는다.");
            Console.WriteLine("[2] 음료를 선택한다.");
            Console.WriteLine("[3] 거스름돈을 받는다.");
            Console.WriteLine("[4] 지나간다.");
            Console.WriteLine("******************************************");

        }

        public static void pause()
        {
            Console.WriteLine("아무키나 누르세요");
            Console.ReadKey();
        }
    }
}
