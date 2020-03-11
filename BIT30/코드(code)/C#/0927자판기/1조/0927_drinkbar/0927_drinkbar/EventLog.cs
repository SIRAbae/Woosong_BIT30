using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    class EventLog
    {
        private List<MachinLogArgs> loglist = 
            new List<MachinLogArgs>();

        Del del;
        public EventLog(Del _del)
        {
            del = _del;
            del.cale += LogMessage;
        }

        public void LogMessage(object obj, MachinLogArgs e)
        {
            loglist.Add(e);
            printAll();
        }

        private void printAll()
        {
            Console.WriteLine("===================================================================");
            foreach (MachinLogArgs a in loglist)
            {
                Console.WriteLine("[{0}] {1}원,{2}번메뉴", a.Type, a.Money, a.Menu, a.Date);
            }
            Console.WriteLine("===================================================================");

        }
    }
}
