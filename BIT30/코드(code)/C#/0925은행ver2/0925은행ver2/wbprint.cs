using System;
using System.Collections.Generic;
using System.Text;

namespace _0925은행ver2
{
    class wbprint
    {
        public static void logo()
        {
            Console.Clear();
            Console.WriteLine("***************************************");
            Console.WriteLine("***우송비트고급 30기 C# 실습프로그램***");
            Console.WriteLine("********학생 관리 프로그램실습*********");
            Console.WriteLine("*************** 시 작 *****************");
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

        public static void menuprint()
        {
            Console.WriteLine("*********************************************");
            Console.WriteLine("********[ F1 ] : 학생 등록 ******************");
            Console.WriteLine("********[ F2 ] : 학이름으로 검색*************");
            Console.WriteLine("********[ F3 ] : 전화번호,학과, 학년수정*****");
            Console.WriteLine("********[ F4 ] : 학생 삭제*******************");
            Console.WriteLine("********[ F5 ] : 파일 저장*******************");
            Console.WriteLine("********[ F6 ] : 파일 불러오기***************");
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
