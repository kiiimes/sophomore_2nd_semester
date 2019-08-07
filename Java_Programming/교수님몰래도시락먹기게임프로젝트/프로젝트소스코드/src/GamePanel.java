import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GamePanel extends JPanel {
	private SubMain sub;
	private SettingSound sound;
   
   private int timer_max; //난이도별 주어진시간
   private int extraTime; //추가시간
   private int onigiriCnt; //주먹밥 갯수
   private int currenttime;
   
   private int random; //말풍선 뭐 쓸지 고르는 난수
   private int clickCnt; //마우스 클릭 수 ->주먹밥n얼마나 먹었나알수있음
   private int flag; //손이 위에있느냐 아래있느냐알수있다
   private int backRandom; // 뒤도는 난수 범위
   private int check_prof; // 교수님이 뒤돌아서 게임이 끝났음을 알아오는 변수
   
   private BubbleThread bubble;//말풍선
   private ProfThread professor;//교수님 앞돌고 뒤돌고
   
   private SwingProgressBarExample TimerLabelThread; //시간의 진행을 알려주는 프로그래스 바
   private JLabel PalLabelThread,PalLabelThread2; // 게임을 진행하면서 움직이는 팔의 이미지 두개(올렸다 내리는거)
   private JLabel PlateLabelThread; //주먹밥밑에 깔려있는 그릇이미지
   
   private JLabel[] rockRice; // 주먹밥
   private ClickListener click; //클릭을받아오는 ClickListener
   
   private ImageIcon cityrock; //도시락
   private ImageIcon talkbubble; //말풍선 
   private ImageIcon gameback; // 게임 진행화면의 배경화면
   
   public GamePanel(SubMain p,SettingSound gameSound) {
	   sub = p;
	   sound = gameSound;
      gameback = new ImageIcon("Images/gameback.png");
         
      setPreferredSize(new Dimension(2000,1000)); // 사이즈 설정
      setLayout(null); // 레이아웃없애기
      
      clickCnt=0; // 게임 진행되면서 클릭된 횟수
      flag = 0; // 밥을 먹는 도중이냐 아니냐를 판별하는 변수
      click = new ClickListener();
      addMouseListener(click);
      
      PalLabelThread = new JLabel( new ImageIcon("images/spoon.png")); // 밥을 먹지않고 있는 상태의 이미지
      PalLabelThread.setBounds(1300, 500, 700, 480); // 위치와 사이즈지정
      add(PalLabelThread); // 패널에 붙여줌
      PalLabelThread.setVisible(true); // 게임 시작시에는 먹지 않은 상태 이니까 보여줌
      
      PalLabelThread2 = new JLabel(new ImageIcon("images/spooneat.png")); // 밥을 먹고 있는 상태의 이미지
      PalLabelThread2.setBounds(1100, 500, 900, 480);// 위치와 사이즈 지정
      add(PalLabelThread2); // 패널에 붙여줌
      PalLabelThread2.setVisible(false); // 게임 시작시에는 밥을 먹고 있지 않음으로 보여주지 않음
      
      ImageIcon originBIcon = new ImageIcon("images/talkbubble.png"); // 말풍선이미지
      Image originBImg = originBIcon.getImage();
      Image changedBImg = originBImg.getScaledInstance(800, 450, Image.SCALE_SMOOTH);// 이미지를 받아와서 크기를 내가 지정할 수 있음
      ImageIcon talkbubble = new ImageIcon(changedBImg); // 크기를 바꾼 이미지를 talkbubble로 선언해줌
      bubble=new BubbleThread(talkbubble,this); // talkbubble을 생성하고
      bubble.setBounds(700,50,800,450); // 위치와 사이즈를 지정하고
      add(bubble); //패널에 붙여준다
     
      currenttime = 0; // 현재까지 진행된 시간은 0으로 초기화 해준다
      professor=new ProfThread(this,sound); // 교수님을 생성해준다
      
      check_prof = 0;
   }
   
   
   public void setOnigiri(int cnt) { // 오니기리 위치 잡아주는 함수
	   int oni; // 주먹밥 위치를 지정해주기 위해 쓰이게 될 변수
	   onigiriCnt = cnt; // 레벨별로 주먹밥 갯수가 다르기 때문에 주먹밥 갯수를 인자로 받아와서 onigiriCnt에 저장한다
	   rockRice = new JLabel[onigiriCnt]; // 8부분은 변수로 받아와야됨
	      
	   for(int i=0;i<onigiriCnt;i++) { // 이제 주먹밥 하나하나 배열로 위치 설정
		   oni = onigiriCnt/2; // 주먹밥을 두줄로 나눠서 배치 시킬거기 때문에 주먹밥 갯수의 반을 변수로 설정해준다
	       rockRice[i]=new JLabel(new ImageIcon("images/onigiri.png")); // 이미지 생성해주고
	       if(onigiriCnt==6) { // 난이도 하 일때는 주먹밥이 6개로 주어진다
	    	   if(i<oni) { // 1~3개 까지는 한줄에 위치시키고
	    		   rockRice[i].setBounds(1300/(oni+1)*i+350,450,300,300);
	    	   }
	    	   else  { // 4~6개는 그 다음줄에 위치시킨다
	    		   rockRice[i].setBounds(1300/(oni+1)*(i%oni)+350,650,300,300);
	    	   }
	    	   add(rockRice[i]); // 위치 시킨후 패널에 더해준다
	      }
	       else if(onigiriCnt==10) { // 난이도 중 일때는 주먹밥이 10개로 주어진다
		       if(i<oni) { //1~5개 한줄에 위치시키고
		          rockRice[i].setBounds(1300/(oni+2)*i+300,450,300,300);
		       }
		       else  { // 6~10개는 그 다음줄에 위치시킨다
		          rockRice[i].setBounds(1300/(oni+2)*(i%oni)+300,650,300,300);
		       }
		       add(rockRice[i]); // 패널에 더해준다
		   }
	       else if(onigiriCnt==14) { // 난이도 상일때는 주먹밥이 14개로 주어진다.
		       if(i<oni) { //1~7개는 한줄에 위치시키고
		          rockRice[i].setBounds(1300/(oni+4)*i+300,450,300,300);
		       }
		       else  { // 8~14개는 그 다음줄에 위치시킨다
		          rockRice[i].setBounds(1300/(oni+4)*(i%oni)+300,650,300,300);
		       }
		       add(rockRice[i]); // 패널에 더해준다
		   }
	   }
	   ImageIcon originCIcon = new ImageIcon("images/cityrock0.png"); //위치시킨 주먹밥 밑에 깔려있을 그릇이미지
	   Image originCImg = originCIcon.getImage(); // 이미지를 가져와서
	   Image changedCImg = originCImg.getScaledInstance(1200, 400, Image.SCALE_SMOOTH); // 원하는크기로 바꿔준후
	   ImageIcon cityrock = new ImageIcon(changedCImg); // 원하는 크기로 바뀐 이미지를 새로 생성하고
	   PlateLabelThread = new JLabel(cityrock); // 새로 생성된 이미지로 JLabel을 생성한다
	   PlateLabelThread.setBounds(100, 500, 1300, 500); // 위치와 사이즈를 지정시켜준후
	   add(PlateLabelThread); // 패널에 붙여준다
   } // setOnigiri()
 
   
   public void professorStart() {	   
	   professor.start(); // 교수님이 돌아보는 스레드를 시작시키는 매소드
   }
   
   public void professorStop() {
	   professor.stop();
   }

   void setTime(int time, int ctime,int e) { // 레벨별 주어지는 시간과 추가시간 그리고 다시 생성될때 새로생성되기전의 현재 시간을 설정한다
	      timer_max = time; // 주어지는시간
	      currenttime = ctime; // 생성되었을때 어느정도 진행되었는지 알려주는 변수
	      extraTime=e; // 주먹밥 먹기에 성공하였을때 주어지는 추가시간
	   }
   void setBackRandom(int r) {backRandom=r;} // 돌아보는 시간의 난수
   public void setTimer_max(int timer_max) {this.timer_max = timer_max;} // 주어지는 시간만 설정하는 셋메소드
   public void setExtraTime(int extraTime) {this.extraTime = extraTime;} // 추가시간만 설정하는 셋 메소드
   public void setCurrenttime(int currenttime) {this.currenttime = currenttime;} // 현재진행시간만 설정하는 셋 메소드
   public void setCheckProf(int check) {check_prof = check;}
   public int getBackRandom() {return backRandom;} // 돌아보는 난수를 받아오는 매소드
   public int getFlag() {return flag;} // 지금 주먹밥을 먹고있는 상태인지 아닌지를 외부의 클래스에게 알려주는 겟 매소드
   public int getCurrentTime() {return currenttime;} // 현재 어느정도 진행 되었는지 외부에서 알수있게 알려주는 갯 매소드
   public int getTimer_max() {return timer_max;} //현재진행되는 게임의 주어진 시간이 얼만지 알려주는 갯 매소드
   public int getExtraTime() {return extraTime;} //추가시간이 얼마인지 알려주는 갯 메소드
   public int getOnigiriCnt() {return onigiriCnt;} // 현재 남아있는 주먹밥 갯수를 알려주는 매소드
   public int getCheckProf() {return check_prof;}
   
   public void C_sta() {  // 클릭한 횟수에 따른 밥을 먹고 있는지 먹고 있지 않은지 알려주는 함수   
      if(clickCnt%2==0) {  // 만약 짝수번 클릭 되었을때 
         PalLabelThread.setVisible(true); // 먹고 있지 않은 상태로 보여주고
         PalLabelThread2.setVisible(false); // 밥먹는 이미지는 보여주지 않는다
         flag=0; // flag = 0으로 변수에 저장함 
      }    
      else { // 홀수번으로 클릭 되었을때는
         PalLabelThread.setVisible(false); // 밥을 먹지 않고있는 이미지를 안보이게하고
         PalLabelThread2.setVisible(true); // 팔을 들어 밥을 먹고 있는 이미지를 보여준다
         flag=1; // 밥을 먹고 있음을 알려주기 위해 flag라는 변수에 1을 저장한다
      }
   }
   
   public void setTimerThread() { // 게임의 시간의 상태를 알려주기 위한 프로그래스 바를 생성하는 매소드이다 
	   TimerLabelThread = new SwingProgressBarExample(this,timer_max,currenttime); 
	   //레벨별로 주어진 시간과 다시 생성되었을때 진행 시간이 바뀌기 위해서 주어진 시간과 진행 시간 두개를 인자로 받는다
	   add(TimerLabelThread); // 패널에 추가 시켜주고
	   TimerLabelThread.start(); // 스레드를 시작한다
   } // 생성자 안에 이 함수가 있다면 맨처음 subMain에서 모든 화면을 생성할때부터 스레드가 시작되기 때문에 레벨을 고르고 게임을 시작하면 이미 프로그래스바가 줄어든 상태로 게임을 시작하기 때문에
     // subMain에서 레벨을 고른후 화면을 넘길때 이 매소드를 호출 하여서 그제서야 프로그래스바가 제대로 실행되도록 해준다
   
   
   public void stop_Thread() {
	    TimerLabelThread.progressBar.setVisible(false); // 이전의 프로그래스바를 없앤다 없애지않으면 보임
	    TimerLabelThread.setThread();
	   	TimerLabelThread.setVisible(false);
	   	TimerLabelThread.removeAll();
	   	TimerLabelThread=null; 
   }
   public void prog_State() { // 추가 시간으로 인한 progressBar를 다시 생성하고 길이 바꿔주는 곳
	   if(!TimerLabelThread.getStop()) {
	   		currenttime = TimerLabelThread.getCurrentTime(); // 클릭시의 현재 시간을 받아옴 (클릭 시마다 이 함수가 호출됨)
		   	if(clickCnt%4==0 ) { //주먹밥을 4번 클릭 할때마다 하나 먹도록 설정하였으니까 클릭수가 4의 배수일 때
		   	onigiriCnt--; // 주먹밥 갯수 하나를 줄이고
		   	rockRice[onigiriCnt].setVisible(false); // 하나를 안보이게한다
		   	if(onigiriCnt == 0) { // 주먹밥 갯수를 줄여가는 과정에서 밥을 다먹어서 게임을 성공하는 경우
			   	TimerLabelThread.setStop(true);
			   	sub.EndAction("./Images/success.png"); // subMain에서 EndAction()매소드를 호출하고 배경화면으로 쓰일 이미지를 인자로 보내준다
		   	}
		   	else { // 주먹밥을 다 먹진않았지만 그저 갯수만 줄어들때는 추가시간을 합친 값을 프로그래스바의 진행값으로 다시 생성해준다
			   	if(currenttime<= timer_max-extraTime) { // 추가시간을 합쳤을때 게임의 최대 주어진 시간 보다 늘어나면 안되기 때문에 범위를 제한해준다
			   		currenttime += extraTime; // 추가시간을 더해준후
			   		TimerLabelThread.setStop(true);
				   	stop_Thread(); // 기존의 프로그래스바를 지우는 매소드를 호출하고
				   	setTimerThread(); // 추가 시간을 더한 값을 현재 진행시간으로 하는 프로그래스 바를 다시생성하고
				   	repaint(); // repaint해준다
			   	}
			   	else { // 만약 추가시간을 더했을때 최대시간을 넘어가게 된다면
			   		currenttime = timer_max; // 현재진행시간을 최대 시간으로 바꿔준후
				   	TimerLabelThread.setStop(true);
				   	stop_Thread();// 기존의 프로그래스바를 지우는 매소드를 호출하고
				   	setTimerThread();// 추가 시간을 더한 값을 현재 진행시간으로 하는 프로그래스 바를 다시생성하고
				   	repaint();// repaint해준다
			   	}
		   		}
	   		}
	   }
   }
            
   public void subControl() { // 밥을 먹고 있을때 교수님이 뒤돌아 보시면 게임이 끝나는 화면으로 바꿔주는 매소드
	   TimerLabelThread.setStop(true); // 프로그래스바안에 포문을 멈추게 해서 없어진 프로그래스바에서 값받아오는걸 막는다
	   sub.EndAction("./Images/gameoverback.png");
   }
   
//getflag랑 교수님 뒤돈 모양 근데 
   private class ClickListener implements MouseListener{
      public void mouseClicked(MouseEvent event) {}
      public void mousePressed(MouseEvent event) {}
      public void mouseReleased(MouseEvent event) {                               
         clickCnt++; // 마우스를 눌렀다가 땔때마다 클릭수를 더해주고
         if(check_prof == 0)
        	 prog_State(); // 클릭시마다의 상태의 변화를 위해 prog_State()매소드를 호출한다
         if(clickCnt==1) { // 처음 한번 눌렸을때 말풍선이 시작하고
            bubble.start();
            if(sound.getEffectIsOn()) {
                sound.playEffectSound();
             }
            professorStart();//교수님 뒤돌기 시작
         
         }
         C_sta(); // 밥을 먹고 있는 상태인지 아닌지에 따른 변화를 감지하기 위해서 C_sta()매소드를 호출한다
      }
      public void mouseEntered(MouseEvent event) {}
      public void mouseExited(MouseEvent event) {}
   }
   
   public void paintComponent(Graphics page) { // 바탕화면 그리기
         super.paintComponent(page);
         page.drawImage(gameback.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
      }//배경화면 그려줌
}
                               
                       