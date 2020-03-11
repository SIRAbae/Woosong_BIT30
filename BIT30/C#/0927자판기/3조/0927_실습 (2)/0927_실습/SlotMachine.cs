using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class SlotMachine
    {
        List<Product> plist = new List<Product>();
        Money b = new Money(0);

        SlotControl sc = SlotControl.Instance;
        SlotEventLog selog;

        public SlotMachine()        //생성자
        {
            
            sc.delInput = SlotInput;
            sc.delChoice = SlotChoice;
            sc.delReturn = SlotReturn;
            selog = new SlotEventLog(sc);
           

            Product water = new Product(1,"물", 1000);
            Product coffe = new Product(2,"커피", 800);
            Product sidar = new Product(3,"사이다", 1500);

            Money money = new Money(0);

            plist.Add(water);
            plist.Add(coffe);
            plist.Add(sidar);

        }

        public void SelectAllProduct(out List<Product> pd)      //일반메서드
        {
            pd = plist;
        }
        public void SelectBalance(out Money pd)
        {
            pd = b;
        }

        public void SlotInput(int money)
        {
            try
            {
                b.Inputmoney = b.Inputmoney + money;
                Console.WriteLine("현재 투입금액 {0}", b.Inputmoney);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        public void SlotChoice(int choice_number,ref Product pro)
        {
            try
            {
                int i = num_to_p(choice_number);

                if (plist[i].Price <= b.Inputmoney)
                {
                    Console.WriteLine("선택하신 제품 : {0}", plist[i].Pname);
                    b.Inputmoney = b.Inputmoney - plist[i].Price;
                    pro = plist[i];
                }
                else
                {
                    Console.WriteLine("잔액이부족합니다.");
                }
            }
            
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        public void SlotReturn()
        {
            try
            {
                if (b.Inputmoney > 0)
                {
                    Console.WriteLine("거스름돈 반환되었습니다. {0}원", b.Inputmoney);
                    b.Inputmoney = 0;
                }
                else
                    Console.WriteLine("반환할 거스름돈이 없습니다.");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private int num_to_p(int pnum)
        {
            for (int i = 0; i < plist.Count; i++)
            {
                Product p = plist[i];
                if (p.Pnumber.Equals(pnum) == true)
                    return i;
            }
            throw new Exception("존재하지 않는상품입니다.");    //return -1 이랑 같은 효과
        }

    }
}
