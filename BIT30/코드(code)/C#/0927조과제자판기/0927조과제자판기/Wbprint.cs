using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class Wbprint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("***************************************");
            Console.WriteLine("***우송비트고급 30기 C# 실습프로그램***");
            Console.WriteLine("********학생 관리 프로그램실습*********");
            Console.WriteLine("**************** 3th  *****************");
            Console.WriteLine("************2019 . 09. 24**************");
            Console.WriteLine("***************************************");
            pause();
        }

        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("***************************************");
            Console.WriteLine("***우송비트고급 30기 C# 실습프로그램***");
            Console.WriteLine("********학생 관리 프로그램실습*********");
            Console.WriteLine("*************** 종 료 *****************");
            Console.WriteLine("************2019 . 09. 24**************");
            Console.WriteLine("***************************************");
            pause();
        }

        public static void menuprint() //메뉴 출력
        {
            Console.WriteLine("*********************************************");
            Console.WriteLine("********[ F1 ] : 계좌 개설 ******************");
            Console.WriteLine("********[ F2 ] : 입   급   ******************");
            Console.WriteLine("********[ F3 ] : 출   금   ******************");
            Console.WriteLine("********[ F4 ] : 잔액 조회 ******************");
            Console.WriteLine("********[ F5 ] : 전체 계좌출력 **************");
            Console.WriteLine("********[ F6 ] : 계좌 삭제 ******************");
            Console.WriteLine("********[ F7 ] : 계좌 정렬 ******************");
            Console.WriteLine("********[ ESC ] 프로그램 종료****************");
            Console.WriteLine("*********************************************");

        }



        public static void pause()
        {
            Console.WriteLine("아무키나 누르세요");
            Console.ReadKey();
        }
    }
}
