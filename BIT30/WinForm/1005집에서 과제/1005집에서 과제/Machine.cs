using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1005집에서_과제
{
    //==== 델리게이트 =================================
    //delegate void DelGetItem(string product);
    //delegate void DelReturnBalance(int balance);
    //=================================================

    class Machine
    {


        #region 싱글톤 구현(인스턴트 객체 생성)
        static Machine control;
        public static Machine Instance
        {
            get { return control; }
        }

        #endregion

        #region 검색관련코드=======================
        //private string Key { get; set; }
        //private Predicate<Drink> predicate;

        //private bool FindAccount(Drink s)
        //{
        //    return s.Name == Key;
        //}
        ////==== 델리게이트 =================================
        //public DelGetItem delgetitem = null;
        //public DelReturnBalance delreturnbalance = null;
        ////=================================================
        #endregion


        ///[Drink 컬렉션] List 로 객체 생성
        public List<Drink> drinklist = new List<Drink>();

        //========================================================
        //필드 : Drink 컬렉션, 판매 총 수량, 판매 총 금액, 투입액
        //get; 노출 set; 은닉
        //========================================================
        public int AllSale { get; private set; } //판매 총 수량
        public int AllPrice { get; private set; } // 판매 총 금액
        public int Money { get; private set; } // 투입액

        static Machine()
        {
            control = new Machine();
        }

        public Machine()
        {
            // predicate = FindDrink; //위의 검색관련 코드 사용하려면 필요함
            AllSale = 0;
            AllPrice = 0;
            Money = 0;
            InitDrinkSetting();
        }

        public void InitDrinkSetting()
        {
            //AllSale = 0;
            //AllPrice = 0;
            //Money = 0;


            //Drink 리스트
            drinklist.Add(new Drink("콜라", 1200, 40));
            drinklist.Add(new Drink("광동헛개차", 1300, 15));
            drinklist.Add(new Drink("식혜", 2000, 20));
            drinklist.Add(new Drink("소주", 3500, 30));
            drinklist.Add(new Drink("숙취해소 여명", 5000, 20));
        }

        public string PrintAll()
        {
            string msg =
               string.Format("판매 수량 : {0} 개 \r\n 판매 금액 : {1} 원 \r\n", AllSale, AllPrice);
            // 1번만 처음 출력
            for (int i = 0; i < drinklist.Count; i++)
            {
                // 메뉴 리스트 만큼 반복해서 tostring 출력
                msg += drinklist[i].ToString() + "\r\n";
            }
            return msg;
        }


        public void InputMoney(int value)
        {
            if (value <= 0)
            { throw new Exception("0보다 큰 금액을 투입하시오"); }
            else
            {
                Money += value;
                return;
            }

        }

        public void SelectDrink(string name)
        {
            for (int i = 0; i < drinklist.Count; i++)
            {
                if (name == drinklist[i].Name) //이름이 같은 음료 검색
                {
                    // 재고량이 0이하면
                    if (drinklist[i].Stock <= 0)
                    {
                        throw new Exception("재고가 없쥬~~~ 돌아가유");
                    }
                    // 투입액이 제품가격보다 낮으면
                    if (Money < drinklist[i].Price)
                    {
                        throw new Exception("돈이 모라유~~ 줄 수 있는게 없어유~ㅎ");
                    }

                    //Drink 클래스에 있는 SelDrink를 호출
                    drinklist[i].SelDrink();

                    //Machine 클래스에 있는 SelDrink에 Drink 클래스의 Price를 전달
                    SelDrink(drinklist[i].Price);

                    return;
                }
            }
        }

        public void SelDrink(int price)
        {
            AllSale++;
            AllPrice += price;
            Money -= price;
        }

        public void GetMoney()
        {
            Money = 0;
            // throw new Exception("잔돈 드릴게유~~ 언능 집에가유~ㅎ");
        }
    }
}
