using System;

namespace _0923_3
{
    /// <summary>
    /// 
    /// </summary>
    class Program
    {
        //출력함수 
        static void Print1()
        {
            Console.Write("test\n");
            Console.WriteLine("test");
        }

        //값타입 참조타입
        static void Print2()
        {
            int num1;  //값 형식
            num1 = 10;

            Program pr; //참조형식
            pr = new Program();

            Program pr1 = new Program();

            pr = pr1;
        }

        //string 타입 : 참조타입
        //참조타입이지만 값타입처럼 사용 가능..
        //1. 저장공간 생성 : new 
        //2. 대입연산      : 동일객체를 가리킴 
        static void Print3()
        {
            string str = "test";
            string str1;

            str1 = str;
            str1 = "AAA";

            Console.WriteLine("{0}, {1}", str, str1);
        }

        //입력 : read
        static void Print4()
        {
            //문자 하나를 반환하는 함수
            int number = Console.Read();
            Console.WriteLine("{0}", number);
            Console.WriteLine(number);
        }

        //입력 : ReadLine() 
        //일반적으로 위 함수를 사용하여 모든 타입의 입력 처리
        static void Print5()
        {
            Console.Write("이름 : ");
            string name = Console.ReadLine();

            Console.Write("나이 : ");
            string temp = Console.ReadLine();
            int age = int.Parse(temp);      //string -> int 

            Console.Write("몸무게 : ");
            float weight = float.Parse(Console.ReadLine());

            Console.Write("성별(남 or 여) : ");
            temp = Console.ReadLine();
            char gender = temp[0];

            Console.WriteLine("이름 : {0} ", name);
            Console.WriteLine("성별 : " + gender);//S + 기타타입 = S
            Console.WriteLine("나이 : " + age + "살");
            Console.WriteLine("몸무게 : {0} ", weight);
        }

        //ReadKey : 특수문자 포함...
        static void Print6()
        {
            ConsoleKeyInfo key = Console.ReadKey();
            if (key.Key == ConsoleKey.F1)
            {
                Console.WriteLine("F1");
            }
            else if (key.Key == ConsoleKey.DownArrow)
            {
                Console.WriteLine("DOWN");
            }
        }

        //예외처리
        //C#은 다양한 예외처리 구문이 제공된다. 
        static void Print7()
        {
            try
            {
                int num = 0;
                //float result = 10 / num;

                int[] arr = new int[5]; //배열은 참조형 
                arr[5] = 10;

            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine("나눗셈 : " + ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        //객체 사용 코드 
        static void Print8()
        {
            //메모리 그림
            MyTime t1 = new MyTime(12, 22, 31);
            MyTime t2 = new MyTime(12, 22, 31);
            MyTime t3 = t1;

            //객체 명을 출력하면 암묵적으로 ToString()을 호출 
            Console.WriteLine(t1);
            Console.WriteLine(t2.ToString());
            Console.WriteLine(t3);

            //eqauals
            if (t1.Equals(t2) == true)
                Console.WriteLine("TRUE");
            else
                Console.WriteLine("FALSE");

        }

        //Member 사용
        static void Print9()
        {
            try
            {
                Member mem = new Member("홍길동", 10, '남');
                Member mem1 = new Member("이길동", "010-1111-1111", 20, '남');

                mem.Age = -10;
                //mem.Name = "허길동";

                mem.Print();
                mem1.Print();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        #region 2일차
        // ref : 원본 변경이 선택 부분
        // out : 원본 변경이 강제적 부분

        static void exam1(int n1, ref int n2, ref int n3) //call by reference
        {
            n2 = 200;
            n3 = 300;

        }




        #endregion

        private static void Main(string[] args)
        {
            int num1 = 10;
            int num2 = 20;
            int num3 = 30;
            exam1(num1, ref num2, ref num3);

        }


    }

   
}
