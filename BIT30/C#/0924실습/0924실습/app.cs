﻿using System;
using System.Collections.Generic;
using System.Text;

namespace _0924실습
{
    class app
    {
        control con = new control();//객체 생성
        public void init()
        {


            wbprint.logo();
        }

        public void run()
        {
            while (true)
            {
                Console.Clear();
                con.printall();
                wbprint.menuprint();
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.F1: con.insert(); break;
                    case ConsoleKey.F2: con.update(); break;
                    case ConsoleKey.F3: con.update1(); break;
                    case ConsoleKey.F4: con.select(); break;
                    case ConsoleKey.Escape: exit(); break;
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