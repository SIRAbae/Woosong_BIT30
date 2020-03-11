using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class Machin
    {

        public int Money;

        public int money
        {
            get { return Money; }
            set
            {
                if (value > 0)
                    Money = value;
                return;
            }
        }
        public Machin(int money)
        {
            Money = money;
        }

        public void addMoney(int money)
        {
            Money += money;
        }

    }
}