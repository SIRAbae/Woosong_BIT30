using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리
{
    class wbioArr
    {
        private acciolist[] acclist;
        public int Size { get; private set; }
        public int Max { get; private set; }

        #region 생성자
        public wbioArr()
        {
            Size = 0;
            Max = 256;
            acclist = new acciolist[Max];
        }
        #endregion
        public acciolist this[int index]
        {
            get { return acclist[index]; }
        }
        public void makeacc(acciolist acc)
        {
            if (Size >= Max)
                throw new Exception("저장 공간 부족");
            acclist[Size] = acc;
            Size++;
        }
        public void erase(int idx)
        {
            for (int i = idx; i < Size; i++)
            {
                acclist[i] = acclist[i++];
            }
            Size--;
        }
    }
}