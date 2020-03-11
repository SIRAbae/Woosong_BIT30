using _1104오후수업클라이언트.ServiceReference2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1104오후수업클라이언트
{
    class Program
    {
        static void Main(string[] args)
        {
            ExampleClient r = new ExampleClient();
            Cal[] arr = r.GetExample(10);
            for (int i = 0; i < 10; i++)
            {
                string str = r.printExample(arr[i].Num1, arr[i].Num2, arr[i].Oper);
                Console.Write(str);
                float result = float.Parse(Console.ReadLine());
                if (r.InputExample(arr[i].Num1, arr[i].Num2, arr[i].Oper, result))
                    Console.WriteLine("정답");
                else
                    Console.WriteLine("오답");
            }
        }


    }
}