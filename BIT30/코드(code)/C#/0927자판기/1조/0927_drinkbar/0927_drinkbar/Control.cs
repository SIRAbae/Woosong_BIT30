using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class Control
    {
        #region 싱글톤 구현-------------
        static Control control;
        public static Control Instance
        {
            get { return control; }
        }
        static Control()
        {
            control = new Control();
        }
        #endregion

        static Del del = new Del();
        EventLog elog = new EventLog(del);

        public Machine mch = new Machine();

        public void addmoney(int money)
        {
            mch.addMoney(money);
            del.cale(del, new MachinLogArgs("금액투입", money, 0));
        }

        public void outputdrink(int menu)
        {
            Drink drink = mch.buyDrink(menu);
            del.outd(drink);
            del.cale(this, new MachinLogArgs("구입", drink.Price, menu));
        }

        public void OutMoney()
        {
           int result =  mch.clearMoney();
            del.outm(result);
            del.cale(this, new MachinLogArgs("잔액반환", result, 0));
        }
    }
}
