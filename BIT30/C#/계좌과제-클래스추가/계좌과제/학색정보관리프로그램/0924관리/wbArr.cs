using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0924관리
{
    /// <summary>
    /// 배열의 자료구조
    /// </summary>
    class wbArr
    {
        private member[] memlist;
        public int Size { get; private set; }
        public int Max { get; private set; }

        #region 생성자
        public wbArr()
        {
            Size = 0;
            Max = 100;
            memlist = new member[Max];
        }
        #endregion

        public member getdata(int idx)
        {
            return memlist[idx];
        }
        public member this[int index]
        {
            get { return memlist[index]; }
        }
        public void makeacc(member mem)
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
