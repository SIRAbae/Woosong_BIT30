using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    
    class SlotPrint
    {
        static List<Product> products;
        static Money money;

        SlotMachine sm = new SlotMachine();
        public void logo()
        {
            sm.SelectAllProduct(out products);
            sm.SelectBalance(out money);

        }

        public void Print()
        {
            Console.Clear();
            Console.WriteLine("*******************************************************");
            Console.WriteLine("2019.09.24");
            Console.WriteLine("우송비트 고급30기 C#언어과정");
            Console.WriteLine("*******************************************************");
            Console.WriteLine("-----------김경훈 --자판기------------------네번째 실습");
            for(int i=0; i< products.Count; i++)
            {
                Console.WriteLine("({0}) [{1}] {2}원",products[i].Pnumber, products[i].Pname,products[i].Price);

            }
            Console.WriteLine("-------------------------------------------------------");
            Console.WriteLine(money);
            Console.WriteLine("-------------------------------------------------------");
            Console.WriteLine("*******************************************************");

        }


        public static void menuprint()
        {
            Console.WriteLine("[F1] 금액 투입 [F2] 제품선택 [F3]잔액반환");
            Console.WriteLine("*******************************************************\n");
            pause();

        }

        public static void pause()
        {
            Console.WriteLine("아무키나 누르쇼");
            Console.ReadKey();
        }
        public static void ending()
        {
            Console.Clear();
            Console.WriteLine("*******************************************************");
            Console.WriteLine("자판기 폭발 - 네번째 실습");
            Console.WriteLine("자판기 없어짐");
            Console.WriteLine("*******************************************************");
        }
    }
}
