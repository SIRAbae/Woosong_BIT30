using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    delegate void OutMoney(int money);
    delegate void OutDrink(Drink menu);
    delegate void CalEvent(object obj, MachinLogArgs arg);

    class Del
    {

        public OutMoney outm = null;
        public OutDrink outd = null;
        public CalEvent cale = null;

        public Del()
        {
            outm = printOutMoney;
            outd = printOutDrink;
        }

        public void printOutMoney(int money)
        {
            Console.WriteLine("{0}원이 나왔습니다.",money);
        }

        public void printOutDrink(Drink drink)
        {
            Console.WriteLine("<{0}> 이(가) 나왔습니다.", drink.Name);
        }
    }
}
