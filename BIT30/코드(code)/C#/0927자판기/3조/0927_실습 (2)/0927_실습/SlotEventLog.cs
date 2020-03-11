using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    
    class SlotEventLog
    {

        private List<SlotEventArgs> sloglist = new List<SlotEventArgs>();

        SlotControl sc;

        public SlotEventLog(SlotControl _sc)
        {
            sc = _sc;
            sc.log += LogMessage;
        }

        public void LogMessage(object obj, SlotEventArgs e)
        {
            sloglist.Add(e);
            PrintAll();

        }

        private void PrintAll()
        {
            Console.WriteLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            foreach (SlotEventArgs a in sloglist)
            {
                Console.WriteLine("[{0}] ({1}) {2} {3}원 {4}",a.Behave, a.Pnum, a.Pname, a.Price, a.date);
            }
            Console.WriteLine("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        }

    }
}
