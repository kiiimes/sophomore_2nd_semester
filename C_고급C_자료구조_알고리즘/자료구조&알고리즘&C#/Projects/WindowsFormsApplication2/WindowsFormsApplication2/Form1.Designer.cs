using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication7
{
    class Circle
    {
        public int x, y, point;

        public Circle(int x, int y, int point)
        {
            this.x = x;
            this.y = y;
            this.point = point;
        }

        public int equals(Circle obj)
        {
            if (obj.point == point) return 1;
            else return 0;
        }

        public void toString()
        {
            Console.WriteLine("Circle({0},{1})반지름{2}",x,y,point);
        }

    }


     
    public class CircleApp
    {
        static void Main(string[] args)
        {
            Circle a = new Circle(2, 3, 5);
            Circle b = new Circle(2, 3, 30);
            Console.WriteLine("원 a : " + a.ToString());
            Console.WriteLine("원 b : " + b.ToString());
            if (a.Equals(b)) Console.WriteLine("같은 원");
            else Console.WriteLine("서로 다른 원");
        }
    }

}