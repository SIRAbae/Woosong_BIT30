using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_drinkbar
{
    enum enumcmd { NONE, INSERT, SELECT, RETURN, EXIT };

    class App
    {

        public void init()
        {
            wbprint.logo();
        }

        public void run()
        {
            while (true)
            {
                Console.Clear();
                wbprint.menuprint();
                enumcmd cmd = 0;
                try
                {
                    cmd = (enumcmd)wblib.inputnumber("커맨드 입력");
                }
                catch (Exception ex)
                {
                    Console.WriteLine("에러 : {0}", ex.Message);
                }

                switch (cmd.ToString())
                {
                    case "INSERT": //입금
                        Inputmoney.Invoke();
                        break;
                    case "SELECT": //음료선택
                        Selectmoney.Invoke();
                        break;
                    case "RETURN": //잔액반환
                        Outputmoney.Invoke();
                        break;
                    case "EXIT": //출금
                        return;
                }
                wbprint.pause();
            }
        }

        public void exit()
        {
            wbprint.ending();
        }

    }
}
