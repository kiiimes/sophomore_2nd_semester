import java.awt.Color;

import javax.swing.*;

public class LabelThread extends JLabel implements Runnable {
	
	private int nStart,nFinish;//숫자 범위를 조정하기 위한 처음과 끝 숫자 변수
	private Thread myThread;// thread 로 매핑해주기 위해서 thread가 필요함
	private HighLowPanel primary;// 메인 패널을 upcall 하기 위한 변수 
	
	//LabelThread 생성자
	public LabelThread() {
		nStart=1;
		nFinish=1;
		//myThread=null;
	}
	
	public LabelThread(HighLowPanel p) {
		nStart=1;
		nFinish=1;
		//myThread=null;
		primary=p;//다른 메소드에서도 쓰려고 대입을 해줌
		
		//객체가 하낭
	}//labelthread() 해당 클래스의 객체를 파라미터로 받음 
	
	public LabelThread(int s,int f) {
		nStart=s;
		nFinish=f;
	}//LabelThread()
	
	public LabelThread(String str) {
		//setText(str);
		super(str);// 부모에 문자열을 셋팅 하면 나한테도 문자열이 셋팅 되는거 
		nStart=nFinish=1;
		//myThread=null;
	}
	
	//get/set method 설정
	public int getStart() {return nStart;}
	public int getFinish() {return nFinish;}
	public void setStart(int s) {nStart=s;}
	public void setFinissh(int f) {nFinish=f;}
	public void setRange(int s,int f) {nStart=s; nFinish=f;}
	
	//thred 시작 메소드
	public void start() {
		myThread=null;
		/*if(myThread==null) {
			myThread=new Thread(this);//runnable 임 this가 
			//이쪽 문제인듯 thread 에서 초기화 하는 방법 알자 
		}*/
		myThread=new Thread(this);
		myThread.start();//this 에 있는 run method가 수행됨
	}//start
	
	//thread 강제 종료 메소드
	public void stop() {
		if(myThread!=null) myThread.stop();
	}//stop()
	
	
	public void run() {
		// 예외 사항 처리해주기 위해서 try catch써준다. 
		try {
			//처음숫자부터 끝숫자까지 숫자를 출력한다.
			for(int i=nStart; i<nFinish;i++) {
				setText(Integer.toString(i));
				myThread.sleep(100);//너무 빨라서 안보이니까 숫자간의 시간 간격 조정
			}//for
			setForeground(Color.red);//정답숫자가 되면 글자 색 빨간색으로 바꿈
			//시간 간격을 두고 숫자를 보였다 안보였다 해서 숫자가 깜빡 거리는 것처럼 보이게 한다.
			for(int i=0;i<10;i++) {
				setVisible(false);
				myThread.sleep(200);
				setVisible(true);
				myThread.sleep(200);
			}
			//숫자가 깜빡거리면서 동시에 알림창이 뜨면 안되므로 깜빡 거리는게 끝난 후에 gameContinue 창을 띄워준다.
			primary.gameContinue();
		}catch(Exception e) {}
	}//run() runnable 구현하려면 반드시 run() 메소드가 있어야된다.
	
}//LabelThread class
