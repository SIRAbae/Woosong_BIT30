using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class MachinLogArgs
    {
        public string Type { get; private set; }
        public int Money { get; private set; }
        public int Menu { get; private set; }
        public DateTime Date { get; private set; }

        public MachinLogArgs(string t, int m, int menu)
        {
            Type = t;
            Money = m;
            Menu = menu;
            Date = DateTime.Now;
        }
    }
}
