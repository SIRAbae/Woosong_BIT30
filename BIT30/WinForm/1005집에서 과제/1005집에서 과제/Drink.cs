using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1005집에서_과제
{
    class Drink
    {
        #region 필드 (음료수명, 가격, 재고랑, 판매량)
        public string Name { get; private set; }
        private int price;
        public int Stock { get; private set; }
        public int Sale { get; private set; }

        #endregion
        //========================================================
        // Price를 제외한 나머지는 get외부 노출 set 은닉
        // Price는 get 외부노출 set 외부노출 단, 0 이상의 값
        //========================================================
        public int Price
        {
            get { return price; }
            set
            {
                if (value < 0)
                    throw new Exception("가격은 0 이상 필요함");

                price = value;
            }
        }

        //=======================================================
        //음료수명, 가격, 재고량을 전달받아 각 필도 값 초기화
        //판매량은 0으로 초기화
        //=======================================================
        public Drink(string n, int p, int s)
        {
            Name = n;
            Price = p;
            Stock = s;
            Sale = 0;
        }

        //=======================================================
        //\r\n 텍스트 박스에 순서대로 넣기 위해 사용함 
        //\r\n 사용하면 줄 이동과 커서 리셋이 가능함
        //=======================================================
        public string Print()
        {
            string msg =
                string.Format("음료수명 : {0} \r\n 가격 : {1} \r\n재고량 : {2} \r\n판매량 : {3} \r\n판매금액 : {4}",
                Name, Price, Stock, Sale, Sale * Price);

            return msg;
        }
        //=======================================================
        // 음료수 총 판매 금액 반환
        //판매개수와 가격의 곱을 반환
        //=======================================================
        public int GetSal()
        {
            return Sale * Price;
        }

        public override string ToString()
        {
            string msg =
                string.Format("[음료수 이름 : {0} / {1} 원] 판매--> {2}개 / 재고-->{3}개",
               Name,Price,Sale,Stock);

            return msg;
        }
        public void SelDrink()
        {
            Stock--;
            Sale++;
        }
    }
}
