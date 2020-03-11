using System;

/*
 *사칙연산
 * 시나리오
 * 
 * 1. 랜던하게 1000개의 문제가 생성
 * 2. 아래와 같이 전체 문제가 출력
 *  3 * 3 = 6
 *  [덧셈add, 뺄셈sud, 나눗셉div, 곱셈mul]
 *  ===> {([int,int]CalResult())-기능//////  [result]-(print)}
 *  
 *  <부모> cal(int,int,resulr,)
 *  {CalResult[추상], print[가상]}
 *  
 *  <자식>ADD(int,int resulr)
 *  { CalResult<재정의 [가상]>}
 *  
 */

namespace _0925수업_코드
{
    class Program
    {
        private Cal[] callist = new Cal[1000];


        public void Run()
        {
            InirExample();
            PrintExample();

        }

        private void InirExample()
        {
            Random r = new Random();

            int num1, num2, oper;
            for (int i = 0; i < callist.Length; i++)
            {
                num1 = r.Next(1, 100);
                num2 = r.Next(1, 100);
                oper = r.Next(0, 4);


                Cal cal = null;
                switch (oper)
                {
                    case 0: cal = new Add(num1, num2); break;
                    case 1: cal = new Sub(num1, num2); break;
                    case 2: cal = new Mul(num1, num2); break;
                    case 3: cal = new Div(num1, num2); break;
                }
                callist[i] = cal;
            }
        }

        private void PrintExample()
        {
            for (int i = 0; i < callist.Length; i++)
            {
                Console.WriteLine("*****[{0}]*****", i + 1);
                callist[i].Print();
            }
        }
        static void Main(string[] args)
        {
            Program p = new Program();
            p.Run();
        }
    }
}3
