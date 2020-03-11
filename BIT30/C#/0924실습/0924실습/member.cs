using System;
using System.Collections.Generic;
using System.Text;

namespace _0924실습
{


    /// <summary>
    /// 데이터 클래스 
    /// </summary>
    class member
    {
        public int Id { get; private set; }
        public string Name { get; private set; }
        public int Balance { get; set; }

        //생성자
        public member(int _id, string _name, int _bal)
        {
            Id = _id;
            Name = _name;
            Balance = _bal;

        }

        public void Print()
        {
            Console.WriteLine("******** 계좌 개설 ********");
            Console.WriteLine("계좌  ID : " + Id);
            Console.WriteLine("이    름 : " + Name);
            Console.WriteLine("입 금 액 : " + Balance);
        }

        public override string ToString()
        {
            string temp =
                string.Format("[{0}] {1}, {2}원",
                                Id, Name, Balance);
            return temp;
        }

        
    }




}
