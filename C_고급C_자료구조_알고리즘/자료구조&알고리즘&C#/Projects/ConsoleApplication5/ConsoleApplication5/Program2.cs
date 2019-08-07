using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            string origins, interests, periods;
            double origin, period,sum, interest;

            origins = Console.ReadLine();
            interests = Console.ReadLine();
            periods = Console.ReadLine();

            origin = double.Parse(origins);
            interest = double.Parse(interests);
            period = double.Parse(periods);

            sum = origin * Math.Pow(1 + interest, period);

            Console.Out.WriteLine(sum);
        }
    }
}
