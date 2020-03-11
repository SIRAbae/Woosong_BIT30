using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1001오후과제
{
    class Shape
    {
        public Point point { get; set; }
        public int Size { get; set; }
        public Color BrushColor { get; set; }

        public Shape(Point pt, int size, Color br)
        {
            point = pt;
            Size = size;
            BrushColor = br;
        }
        public Shape(Point pt, Color br)
        {
            point = pt;
            Size = 50;
            BrushColor = br;
        }


    }
}
