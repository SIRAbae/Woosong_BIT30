using System;
using System.Collections.Generic;
using System.Text;

namespace _0925계좌과업
{
    class wbarray //저장하는놈
    {
        private Member[] memlist;
        public int Size { get; private set; }
        public int Max { get; private set; }

        #region 생성자
        public wbarray()
        {
            Size = 0;
            Max = wblib.inputnember("배열의 크기");
            memlist = new Member[Max];
        }
        #endregion

        public Member getdata(int idx)
        {
            return memlist[idx];
        }

        public Member this[int index]
        {
            get { return memlist[index]; }

        }

        public void insert(Member mem)
        {

            if (Size >= Max)
                throw new Exception("저장 공간 부족");

            memlist[Size] = mem;
            Size++;
        }


        public void erase(int idx)
        {
            for (int i = idx; i < Size; i++)
            {
                memlist[i] = memlist[i++];
            }

            Size--;
        }
    }
}
