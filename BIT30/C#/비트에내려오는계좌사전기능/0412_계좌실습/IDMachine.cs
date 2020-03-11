using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0412_계좌실습
{
    class IDMachine
    {

        static private int number;

        static IDMachine() //60페이지 정적생성자 / 접근 한정자 없다 제일처음 호출
        {
            number = 1000;
        }

        public static int CurrentNumber()
        {
            return number;
        }

        public static int GetNumber()
        {
            int tmp = number;
            number = number + 10;
            return tmp;
        }
    }

}

