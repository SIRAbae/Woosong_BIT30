using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class Product
    {
        public int Pnumber { get; private set; }
        public string Pname { get; private set; }
        public int Price { get; private set; }

        public Product()
        {
            Pnumber = 0;
            Pname = string.Empty;
            Price = 0;

        }

        public Product(int pn,string pname, int pr)
        {
            Pnumber = pn;
            Pname = pname;
            Price = pr;
            
        }

    }
}
