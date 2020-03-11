using System;
using System.Collections.Generic;
using System.Text;

namespace _0927조과제자판기
{
    class Control
    {
        //저장소=================================
        List<Drink> acc = new List<Drink>();

        //=====================================

        static Control con;
        public static Control instance
        {
            get
            {
                return con;
            }
        }

        static Control()
        {
            con = new Control();
        }

        private Control()
        {
        }


        public void addmoney(int money)
        {

            if(money >0)
            {
                Machin.addMoney(money); 
            }

        }

    }
}