using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication6
{
    class Program
    {
        static void Main(string[] args)
        {
            string cs;
            double c,f;

            cs = Console.ReadLine();
            c = double.Parse(cs);

            f = 9 / 5.0 * c + 32;

            Console.Out.WriteLine(f);
        }
    }
}
