using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class SlotEventArgs : EventArgs
    {
        public string Behave { get; private set; }
        public int Pnum { get; private set; }
        public string Pname { get; private set; }
        public int Price { get; private set; }
        public DateTime date { get; private set; }


        public SlotEventArgs(string b, int s, string n1, int n2)
        {
            Behave = b;
            Pnum = s;
            Pname = n1;
            Price = n2;
            date = DateTime.Now;
        }

    }

    delegate void SlotEvent(object obj, SlotEventArgs arg);

}

