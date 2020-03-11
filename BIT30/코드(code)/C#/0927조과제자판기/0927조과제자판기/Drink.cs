using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class Drink
    {

        public int Id { get; private set; }
        public string Name { get; private set; }
        public int Price;
        public int price
        {
            get { return Price; }
            set
            {
                if (value >= 0)
                    Price = value;
            }
        }

        //  public float Sel { get; private set; }

        public Drink(int id, string drink, int price)
        {
            Id = id;
            Name = drink;
            Price = price;
        }

        public void addMoney(int money)
        {
            if (money > 0)
            {
                Price += money;
                return;
            }

        }
    }
}