import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BubbleThread extends JLabel implements Runnable {

   private String[] bubbleStr={"학생여러분~ 딴 짓 하지 마세요","제가 주말에 스키장을 다녀왔어요~","어디서 도시락 냄새 나지 않아요?","오늘은 날씨가 좋죠?","유쾌,상쾌,통쾌~^^","커피와 도넛을 들고 어린이 대공원에 갔어요"};
   //말풍선 안에 나올 문구들
   private Thread myThread;
   private ImageIcon sav; //이미지 받는 변수
   private GamePanel g;//gamePanel 받는 변수
   
   //생성자
   public BubbleThread() {
      myThread=null;
   }
   public BubbleThread(ImageIcon icon,GamePanel p) {
      myThread=null;
      g=p;//객체를 인자로 받아서 사용할 수 있도록 넘겨준다.
      setIcon(icon);
   }
   
   //get/set method
   public String[] getStr() {return bubbleStr;}
   public void setStr(String[] s) {bubbleStr=s;}
   
   
   public void start() { //스레드 생성및 시작
	  if(myThread==null) {
		  myThread=new Thread(this);
	  }//한번만 생성하기 위해서 null일때 생성
      myThread.start();
   }//오버라이딩
   
   public void stop() { // 스레드 끝내기
      if(myThread!=null) myThread.stop();
   }
      
   
   public void run() { // 스레드 실행
      try {
    	  int i=0;
         while(g.getCurrentTime()!=0){
            //타이머변수가 0이 되때까지 while문
            setFont(new Font("Courier",Font.BOLD,30)); //글씨 설정
            setText(bubbleStr[i%6]);//6개를 순서대로 계쏙 보여준다.
            setHorizontalTextPosition(SwingConstants.CENTER);
            myThread.sleep(5000);
            i++;//i를 중가시키면서 말풍선의 말이 계쏙 나올 수 있게 해준다.
         }         
      }catch(Exception e) {}
   }
}