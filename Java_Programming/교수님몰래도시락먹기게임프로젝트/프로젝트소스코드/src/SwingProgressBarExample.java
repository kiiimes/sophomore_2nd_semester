import java.awt.*;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.SwingUtilities;

public class SwingProgressBarExample extends JPanel implements Runnable{
   private int run_time; // 게임에 난이별로 주어지는 시간들
   private int current_time; // 게임진행중의 현재 진행시간을 가지는 변수
   private int extra_time; // 난이도별 추가 시간
   
   private boolean stop; // run매소드 안의 for문의 내용을 실행시키지 않기위해 해주는 boolean변수
   
   private Thread myThread; // 스레드
   JProgressBar progressBar; // 유저에게 진행시간을 보여주기 위해서 progressbar를 이용한다
   private GamePanel g;
   
   public SwingProgressBarExample(GamePanel primary,int Rtime, int Ctime) { // 게임 패널과 처음 시간 그리고 현재 진행시간을 인자로 받는 생성자
      g = primary;
      stop = false; // for문안의 내용이 돌아갈 수있게 기본설정을 해준다
      setLayout(null); //레이아웃을 없앰으로서 progressbar의 setsize로 크기를 바꾼다
      setPreferredSize(new Dimension(1000,50)); // 프로그래스바의 크기를 지정해준다
      run_time = Rtime; // 이게 게임 실행시간
      current_time = Ctime; // 이거는 현재 진행된 시간
      myThread = null; // 스레드에 널을 넣어주고
      progressBar = new JProgressBar(0,Rtime); //최대값이 주어진 최대시간으로 프로그래스바생성
      progressBar.setSize(1000,50); // 프로그래스바 길이를 설정해주고
      progressBar.setForeground(Color.green); // 처음 바 색깔을 초록 색으로 보여준다
      progressBar.setStringPainted(false); // 이거 true로하면 몇프로 진행됬는지 보여줌
      g.add(progressBar);// g패널에 프로그래스바를 더한다
   }
   
   
   public void setThread() { this.progressBar = null;} // progressBar를 널로 만들어 버리는 매소드
   public void setRuntime(int time) {run_time = time;} // 난이도별 주어진 시간을 설정해주는 매소드
   public void setCurrenttime(int time) {current_time = time;} // 현재 진행된 시간을 설정해주는 매소드
   public void setExtratime(int time) {extra_time = time;} // 난이도별에 따라 다른 추가시간을 설정해주는 매소드
   public void setTime(int runtime, int extratime) { // runtime과 extratime을 한번에 설정해주는 매소드
      run_time = runtime;
      extra_time = extratime;
   }
   
   public int getRuntime() {return run_time;} // 난이도별 주어진 시간을 외부에 보여주는 갯매소드
   public int getCurrentTime() { return current_time;} // 진행시간을 외부에 알려주는 갯매소드

   public void setStop(boolean stop) {
	   this.stop = stop;
   }
   public boolean getStop() { return stop; }
   
   public void start(){ //thread 시작
      if(myThread == null){
         myThread = new Thread(this); //runnable 로 구현된 객체랑 이어줘야됌
      }
      myThread.start();//this에있는  run method 호출
   }//start() ->thread생성
   
   public void stop(){ // 스레드 stop
      myThread.stop();
   }//stop()
 
   public void run(){ // 스레드 실행부분
      for(int i=current_time;i>=0;i--) { // 프로그래스바에 진행된 시간을 보여주기위한 for문이다
         if(!stop) { // 프로그래스바를 다시 생성하게 될때 지워야하는 원래 프로그래스바를 멈춰주기 위해 stop변수를 사용한다
        	 progressBar.setValue(i); // 프로그래스바의 값을 지정해주고
        	 current_time = i; // 현재시간을 for문의 i의 변화에 맞게 계속 변경시켜준다
             
            if(i<run_time/4) { // 만일 주어진 시간의 4분의1보다 조금남게된다면 시간이 얼마 남지 않았음을 알려주기 위해서
               progressBar.setForeground(Color.red); // 프로그래스바의 색깔을 빨간색으로 바꿔준다
            }
            try{//예외처리
               myThread.sleep(1000); // 1초에 한번씩 줄어들게 만든다
            }
            catch(Exception e){}
            if(i ==0) {
            	stop = true;
             	g.subControl(); //만일 시간이 다 되었을때에 gamePanel의 subControl()매소드를 호출하여서 프로그래스바의 스레드를 멈추고 게임이 끝나는 화면으로 바꾼다
             }
         }
      }
   }//run()


}