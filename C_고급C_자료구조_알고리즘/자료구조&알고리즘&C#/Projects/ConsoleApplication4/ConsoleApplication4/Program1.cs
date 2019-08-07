using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication4
{
    class Program
    {
        static void Main(string[] args)
        {
            string xnum, ynum;
            int x, y,z;

            xnum = Console.ReadLine();
            ynum = Console.ReadLine();

            x = int.Parse(xnum);
            y = int.Parse(ynum);

            z = x * x - y * y;

            Console.Out.WriteLine(Math.Abs(z));

        }
    }
}
