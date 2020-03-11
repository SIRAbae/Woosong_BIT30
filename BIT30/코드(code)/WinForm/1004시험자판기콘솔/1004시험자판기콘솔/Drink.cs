using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1004시험자판기콘솔
{
    class Drink
    {
        public string Name { get; private set; }
        private int price;
        public int Count { get; private set; }
        public int Sal { get; private set; }

        public int Price
        {
            get { return price; }
            set
            {
                if (value < 0)
                    throw new Exception("가격은 0 이상 필요함");

                price = value;
            }
        }


        public Drink(string n, int p, int c)
        {
            Name = n;
            Price = p;
            Count = c;
            Sal = 0;
        }

        public string Print()
        {
            string msg =
                string.Format("음료수명 : {0} \r\n 가격 : {1} \r\n재고량 : {2} \r\n판매량 : {3} \r\n판매금액 : {4}",
                Name, Price, Count, Sal, Sal * Price);

            return msg;
        }

        public int GetSal()
        {
            return Count * Price;
        }

        public override string ToString()
        {
            string msg = string.Format("[{0}/{1}원] 판매{2}개 재고{3}개", Name, Price, Sal, Count);
            return msg;
        }

        public void selDrink()
        {
            Count--;
            Sal++;
        }

    }
}

