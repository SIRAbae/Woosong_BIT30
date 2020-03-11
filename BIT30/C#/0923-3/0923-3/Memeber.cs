using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923_3
{
    /*
     * 1. 맴버 변수           ==> 맴버 변수 : 데이터 은닉
     * 3. get & set 메서드    ==> 프로퍼티(속성) 
     * 2. 생성자 소멸자       ==> 생성자    : 오버로딩 
     * 4. 일반 메서드         ==> 일반메서드 
     */
    class Member
    {
        private string name;
        private string phone;
        private int age;
        private char gender;

        #region 프로퍼티(속성)
        public string Name
        {
            get { return name; }
            private set { name = value; }
        }

        public int Age
        {
            get { return age; }
            set
            {
                if (value > 0)
                    age = value;
                else
                    throw new Exception("마이너스값오류");
            }
        }

        #endregion

        #region 생성자
        public Member(string n, string p, int a, char g)
        {
            Name = n;
            phone = p;
            Age = a;
            gender = g;
        }

        public Member(string name, int age, char gender)
        {
            this.name = name;
            this.phone = string.Empty;
            this.age = age;
            this.gender = gender;
        }
        #endregion 

        public void Print()
        {
            Console.WriteLine("이름 : " + Name);
            Console.WriteLine("전번 : " + phone);
            Console.WriteLine("나이 : " + Age);
            Console.WriteLine("성별 : " + gender);
        }

        public override bool Equals(object obj)
        {
            Member mem = (Member)obj;
            if (phone.Equals(mem.phone) == true)
                return true;
            else
                return false;
        }
    }
}
