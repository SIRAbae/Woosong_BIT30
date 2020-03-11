using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class Drink
    {
        public int Id { get; private set; }

        public String Name { get; private set; }

        public int Price { get; private set; }


        public Drink(int id, string name, int price)
        {
            Id = id;
            Name = name;
            Price = price;
        }

 


    }
}
