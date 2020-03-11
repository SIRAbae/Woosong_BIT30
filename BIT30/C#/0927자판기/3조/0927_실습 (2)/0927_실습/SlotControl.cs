using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    delegate void DelInputmoney(int inputmoney);       //금액투입델리게이션 클래스 생성
    delegate void DelChoice(int choice_number,ref Product pro);       //금액투입델리게이션 클래스 생성
    delegate void DelReturn();       //금액투입델리게이션 클래스 생성
    
    class SlotControl
    {
        static SlotControl sc;

        public static SlotControl Instance { get { return sc; } }    //인스턴스 1

        static SlotControl()    //정적생성자2
        {
            sc = new SlotControl();
        }

        private SlotControl()   //은닉생성자3
        {
        }

        public DelInputmoney delInput = null;      //금액투입딜리게이션 객체 생성
        public DelChoice delChoice = null;      //금액투입딜리게이션 객체 생성
        public DelReturn delReturn = null;      //금액투입딜리게이션 객체 생성
        public event SlotEvent log = null;       //이벤트 딜리게이션 객체 생성           여기에다가 EventLog 함수를 넣어야함.

        public void InputMoney()
        {
            int money = Slotlib.inputmoney("투입할 금액");

            delInput(money);

            LogMessage("금액투입", 0, "", 0);  //이벤트 게시
        }

        public void Choice()
        {
            Product pro = new Product();
            int choice_number = Slotlib.inputnumber("제품을 선택해주세요");

            delChoice(choice_number, ref pro);
                
            LogMessage("제품선택",pro.Pnumber, pro.Pname, pro.Price);  //이벤트 게시
        }

        public void Return()
        { 
            delReturn();

            LogMessage("잔돈반환", 0, "", 0);  //이벤트 게시
        }

        private void LogMessage(string msg,int pnum,string pname,int i)
        {

            if (log != null)
            {
                log(this, new SlotEventArgs(msg, pnum, pname, i));    //메세지만 넘겨주고 나머지는 필드에존재하니 갖다씀
            }
        }
        //private int num_to_p(int pnum)
        //{
        //    List<Product> products;
        //    SlotMachine sm = new SlotMachine();

        //    sm.SelectAllProduct(out products);

        //    for (int i = 0; i < products.Count; i++)
        //    {
        //        Product p = products[i];
        //        if (p.Pnumber.Equals(pnum) == true)
        //            return i;
        //    }
        //    throw new Exception("존재하지 않는상품입니다.");    //return -1 이랑 같은 효과
        //}
    }
}
