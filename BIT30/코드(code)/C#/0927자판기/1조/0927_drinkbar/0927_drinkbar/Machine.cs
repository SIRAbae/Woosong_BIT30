using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class Machine
    {
        public List<Drink> drinklist = new List<Drink>();

        public int Money { get; private set; }

        #region 검색관련코드=======================
        private int Key { get; set; }
        private Predicate<Drink> predicate;

        private bool FindAccount(Drink s)
        {
            return s.Id == Key;
        }
        #endregion

        public Machine()
        {
            predicate = FindAccount;

            //초기금액
            Money = 0;

            //음료수 세팅
            drinklist.Add(new Drink(1, "콜라", 1000));
            drinklist.Add(new Drink(2, "사이다", 1000));
            drinklist.Add(new Drink(3, "식혜", 1000));
          
        }

        
        public void printMenu()
        {
            for (int i = 0; i < drinklist.Count; i++)
            {
                Console.WriteLine("[{0}] {1} {2}"
                    ,drinklist[i].Id , drinklist[i].Name, drinklist[i].Price);
            }

        }

        public void addMoney(int money)
        {
            Money += money;
        }

        public Drink buyDrink(int menu)
        {
            try
            {
                Key = menu;
                Drink finddata = drinklist.Find(predicate);

                if (finddata.Price <= Money)
                {
                    Money -= finddata.Price;
                    return finddata;
                }
                return null;
            }
            catch (Exception)
            {
                Console.WriteLine("없다");
                return null;
            }
        }

        public int clearMoney()
        {
            int result = Money;
            Money = 0;
            return result;
        }
    }
}
