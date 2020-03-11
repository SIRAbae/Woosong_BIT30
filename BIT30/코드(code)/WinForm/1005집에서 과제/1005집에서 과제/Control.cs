using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1005집에서_과제
{



    class Control
    {
        Machine mch = new Machine();

        #region  델리게이트 사용
        //public Control()
        //{
        //    mu.delgetitem = getdrink;
        //    mu.delreturnbalance = getbalance;
        //}
        #endregion




        public void printOutMoney(int money)
        {
            Console.WriteLine("{0}원이 나왔습니다.", money);
        }

        public void printOutDrink(Drink drink)
        {
            Console.WriteLine("<{0}> 이(가) 나왔습니다.", drink.Name);
        }

        public void printall()
        {
            mch.PrintAll();

        }
        public void Inputmoney()
        {
            try
            {
                int inputmoney = Lib.inputnumber("넣을 금액");
                if (inputmoney <= 0)
                    throw new Exception("0보다 큰 금액을 투입하세요");

                mch.InputMoney(inputmoney);

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public void SelectDrink()
        {

            try
            {
                mch.PrintAll();
                string name = Lib.inputstring("구매할 음료");
                mch.SelectDrink(name);

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        public void  ReturnMoney()
        {
            mch.GetMoney();
        }

    }
}
