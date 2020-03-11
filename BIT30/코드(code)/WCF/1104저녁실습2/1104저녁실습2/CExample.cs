using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1104저녁실습2
{
    class Example : IExample
    {
        public List<Cal> GetExample(int max)
        {
            List<Cal> listcal = new List<Cal>();

            for (int i = 0; i < 10; i++)
            {
                Random r = new Random();
                int n1 = r.Next(1, 10);
                int n2 = r.Next(1, 10);
                int oper = r.Next(1, 5);
                Cal c = new Cal();
                c.Num1 = n1;
                c.Num2 = n2;
                switch (oper)
                {
                    case 1: c.Oper = '+'; break;
                    case 2: c.Oper = '-'; break;
                    case 3: c.Oper = '*'; break;
                    case 4: c.Oper = '/'; break;
                }
                listcal.Add(c);
            }
            return listcal;
        }

       public bool InputExample(int n1, int n2, char c1, float f1)
        {
            float result = 0;
            switch (c1)
            {
                case '+': result = n1 + n2; break;
                case '-': result = n1 - n2; break;
                case '*': result = n1 * n2; break;
                case '/': result = n1 / n2; break;
            }

            if (result == f1)
                return true;
            else
                return false;
        }

       public string PrintExample(int n1, int n2, char c1)
        {
            return n1 + "" + c1 + "" + n2 + "=";
        }
    }
}
