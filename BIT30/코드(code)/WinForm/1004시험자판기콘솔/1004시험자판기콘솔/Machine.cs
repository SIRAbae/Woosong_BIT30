using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1004시험자판기콘솔
{
    class Machine
    {
        #region 싱글톤 구현-------------
        static Machine control;
        public static Machine Instance
        {
            get { return control; }
        }
        #endregion

        public List<Drink> drinklist = new List<Drink>();

        public int AllSal { get; private set; }
        public int AllPrice { get; private set; }
        public int Money { get; private set; }

        static Machine()
        {
            control = new Machine();
        }

        public void InitDrinkSetting()
        {
            AllSal = 0;
            AllPrice = 0;
            Money = 0;

            drinklist.Add(new Drink("콜라", 600, 10));
            drinklist.Add(new Drink("사이다", 700, 10));
            drinklist.Add(new Drink("식혜", 800, 10));
            drinklist.Add(new Drink("청국장", 900, 10));
            drinklist.Add(new Drink("초신수", 1000, 10));
        }

        public string PrintAll()
        {
            string msg = string.Format("판매수량 : {0}\r\n판매금액 : {1}\r\n", AllSal, AllPrice);

            for (int i = 0; i < drinklist.Count; i++)
            {
                msg += drinklist[i].ToString() + "\r\n";
            }
            return msg;

        }

        public void InsertMoney(int value)
        {
            if (value <= 0)
                throw new Exception("0보다 큰 금액을 투입하시오");
            Money += value;
        }

        public void SelectDrink(string name)
        {
            for (int i = 0; i < drinklist.Count; i++)
            {
                if (name == drinklist[i].Name)
                {
                    if (drinklist[i].Count <= 0)
                        throw new Exception("재고가 없다.");

                    if (Money < drinklist[i].Price)
                        throw new Exception("금액이 모자라다.");

                    drinklist[i].selDrink();
                    SelDrink(drinklist[i].Price);
                    return;
                }
            }
        }


        public void SelDrink(int price)
        {
            AllSal++;
            AllPrice += price;
            Money -= price;
        }

        public void GetMoney()
        {
            Money = 0;
        }
    }
}
