using System;
using System.Collections.Generic;
using System.Text;

namespace _0925수업_코드
{
    abstract class Cal
    {
        public int Num1 { get; private set; }
        public int Num2 { get; private set; }
        public float Result { get; private set; }

        public Cal(int num1, int num2)
        {
            Num1 = num1;
            Num2 = num2;
            Result = CalResult(); //
        }

        public abstract float CalResult();//추상 메서드
        
        public abstract void Print();

    }
}
