using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication8
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.Write("오늘 방문한 팀 수를 입력하세요. ");
            int team_count = int.Parse(Console.ReadLine());

            int[] charge = { 5000, 10000, 15000, 3000 };
            int[] count = new int[4];
            int[] v_count = { 0,0,0,0 };
            int total_count = 0;
            int sum=0;
            int total_sum = 0;
            int membership = 0;

            for(int i = 0; i < 4; i++)
            {
                sum = 0;
                Console.Write(i + "번팀 인원수(초등학생, 청소년, 일반, 경로대상)를 입력하세요.");
                for(int j = 0; j < 4; j++)
                {
                   
                    count[j] = int.Parse(Console.ReadLine());
                    v_count[j] += count[j];
                    total_count += count[j];
                }
                Console.Write(i + "번팀 할인카드 종류(카드없음:0, 일반등급:1, VIP등급:2)를 입력하세요.");
                membership = int.Parse(Console.ReadLine());
                for(int j = 0; j < 4; j++)
                {
                    sum = sum + (count[j] * charge[j]);
                }
                if (membership == 1) sum = (int)(sum * 0.9);
                else if (membership == 2) sum = (int)(sum * 0.8);

                Console.WriteLine(i + "번팀 입장료는 " + sum + "원입니다.");

                total_sum += sum;
            }

            Console.WriteLine("\n");

            Console.WriteLine("오늘 총 방문자 수는 {0}명입니다.", total_count);
            Console.WriteLine("초등학생 수는 {0}명입니다.", v_count[0]);
            Console.WriteLine("청소년 수는 {0}명입니다.", v_count[1]);
            Console.WriteLine("일반인 수는 {0}명입니다.", v_count[2]);
            Console.WriteLine("경로대상 수는 {0}명입니다.", v_count[3]);

            Console.WriteLine("\n");

            Console.WriteLine("총 입장료는 {0}원입니다.",total_sum);


        }
    }
}


