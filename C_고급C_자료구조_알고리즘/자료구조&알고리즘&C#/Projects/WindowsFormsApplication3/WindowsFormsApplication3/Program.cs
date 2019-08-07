using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
/*========체크리스트===========*/
//1.연산자,조건문,반복문
//2.클래스,인스턴스 변수, 메서드
//3.주소 참조(ref, out) 사용
//4.try-catch
//5.

namespace 윈도폼
{
    public partial class Form1 : Form
    {
        public int ball_count = 0;
        public int out_count = 0;
        public int strike_count = 0;
        public int[] answer;//답

        public Form1()
        {
            InitializeComponent();

            //정답은 랜덤으로 정한다.
            answer = new int[3];

            Random rand = new Random();

            for (int i = 0; i < 3; i++)
            {
                answer[i] = rand.Next(0, 9);
                for (int j = 0; j < i; j++)
                    if (answer[i] == answer[j])
                        i--;
            }//중복값이 없고,랜덤하게 숫자 3개 선택
            System.Windows.Forms.MessageBox.Show(answer[0].ToString() + answer[1].ToString() + answer[2].ToString());

        }//Form1

        private void compare(ref int[] p)
        {
            ball_count = 0;
            out_count = 0;
            strike_count = 0;
            int flag = 0;

            for (int i = 0; i < 3; i++)
            {
                flag = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (p[i] == answer[j])
                    {
                        flag = 1;
                        if (i == j)
                            strike_count++;
                        else
                            ball_count++;
                    }
                }
                if (flag == 0)
                    out_count++;
                if (strike_count == 3)
                    break;
            }
        }//player 값과 answer값 비교 메소드
        //ball,out,strike의 개수 세기

        private void init_function()
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult check;

            try
            {
                int text1 = int.Parse(textBox1.Text);
                int text2 = int.Parse(textBox2.Text);
                int text3 = int.Parse(textBox3.Text);
                //textbox에 숫자가 아닌 값을 입력할 경우 예외 처리

                int n = dataGridView1.Rows.Add();
                //행 추가 & 행 번호를 n에 저장

                dataGridView1.Rows[n].Cells[0].Value = textBox1.Text;
                dataGridView1.Rows[n].Cells[1].Value = textBox2.Text;
                dataGridView1.Rows[n].Cells[2].Value = textBox3.Text;
                //왼쪽 표에 입력받은 값 추가 

                int[] player = new int[3];
                player[0] = int.Parse(textBox1.Text);
                player[1] = int.Parse(textBox2.Text);
                player[2] = int.Parse(textBox3.Text);
                //textbox값에 입력받은 숫자를 player배열에 저정

                compare(ref player);
                //정답과 비교해주는 함수호출

                int m = dataGridView2.Rows.Add();
                dataGridView2.Rows[m].Cells[0].Value = ball_count;
                dataGridView2.Rows[m].Cells[1].Value = strike_count;
                dataGridView2.Rows[m].Cells[2].Value = out_count;
                //오른쪽 표에 결과 값 추가

                if (strike_count == 3)
                {
                    String result = "ANSWER  :  " +
                                    answer[0].ToString() +
                                    "   " + answer[1].ToString() +
                                    "   " + answer[2].ToString();
                    label2.Text = result;
                    check = System.Windows.Forms.MessageBox.Show("다시 시작?");

                    //확인버튼 누르면 값 초기화 후 다시 시작
                    if (check == System.Windows.Forms.DialogResult.Yes)
                    {
                        Console.WriteLine("확인선택!");
                    }

                    //아직 구현 안함
                }
            }
            catch (Exception exception)
            {
                System.Windows.Forms.MessageBox.Show("숫자를 입력하세요!");

            }
            finally
            {
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
                //textbox 값 비우기
            }

        }//button1_Click

        private void Form1_Load(object sender, EventArgs e) { }
        //아무것도 안쓰고 그대로 사용(지우면 안댕!!)
    }//Form1(class)

}//윈도폼(naemspace)