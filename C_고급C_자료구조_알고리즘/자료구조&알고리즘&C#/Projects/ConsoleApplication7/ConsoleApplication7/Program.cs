using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication7
{
    class Program
    {

        static void Main(string[] args)
        {
            int pizza = 15000, spagetti = 10000 ,salad = 7000,drink = 2000;
            int pNum, spNum, saNum, drNum;

            Console.WriteLine("1. 피자(15,000원), 2. 스파게티(10,000원), 3. 샐러드(7,000원), 4. 음료수(2,000원) ");
            Console.Write("메뉴별 주문 개수를 입력하시오.");
            pNum = int.Parse(Console.ReadLine());
            spNum = int.Parse(Console.ReadLine());
            saNum = int.Parse(Console.ReadLine());
            drNum = int.Parse(Console.ReadLine());

            Console.Write("사용하실 할인쿠폰을 선택하세요 (0: 없음, 1:5%, 2:10%, 3:20%)");
            int coupon = int.Parse(Console.ReadLine());


            int sum = pizza * pNum + spagetti * spNum + salad * saNum + drink * drNum;
            double discount = 0.0;
            switch (coupon)
            {
                case 0:break;
                case 1: discount = sum - sum * 0.05; break;
                case 2: discount = sum - sum * 0.10; break;
                case 3: discount = sum - sum * 0.20; break;
            }

            Console.WriteLine("식사 금액은 "+discount+"원입니다.");

        }
    }
}
//int triangle = int.Parse(Console.ReadLine());

//            for (int i = 0; i<triangle; i++)
//            {
//                for (int j = 0; j <= i; j++)
//                {
//                    Console.Write(j + 1 + "K");
//                }
//                Console.WriteLine('\n');
//            }
