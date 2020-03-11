using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리
{
    /// <summary>
    /// 화면 출력 기능 static >> 멤버변수가 필요없다.. 객체가 필요없다
    /// </summary>
    class wbprint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("**************************************");
            Console.WriteLine(" 2019 . 09. 24");
            Console.WriteLine(" 우송비트고급30기");
            Console.WriteLine(" 계좌프로그램 - 과제");
            Console.WriteLine(" 권도훈");
            Console.WriteLine("**************************************");
            pause();
        }
        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("**************************************");
            Console.WriteLine(" 계좌프로그램 - 과제");
            Console.WriteLine(" 프로그램 종료");
            Console.WriteLine("**************************************");
            pause();
        }
        public static void menuprint()
        {
            Console.WriteLine("****************MENU******************");
            Console.WriteLine("[F1] 계좌 생성");
            Console.WriteLine("[F2] 입금");
            Console.WriteLine("[F3] 출금");
            Console.WriteLine("[F4] 잔액 조회");
            Console.WriteLine("[ESC] 프로그램 종료");
            Console.WriteLine("**************************************");
        }
        public static void pause()
        {
            Console.WriteLine("\nPress Any Key");
            Console.ReadKey();
        }
    }
}
