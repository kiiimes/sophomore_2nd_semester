import java.awt.Color;

import javax.swing.*;

public class LabelThread extends JLabel implements Runnable {
	
	private int nStart,nFinish;//���� ������ �����ϱ� ���� ó���� �� ���� ����
	private Thread myThread;// thread �� �������ֱ� ���ؼ� thread�� �ʿ���
	private HighLowPanel primary;// ���� �г��� upcall �ϱ� ���� ���� 
	
	//LabelThread ������
	public LabelThread() {
		nStart=1;
		nFinish=1;
		//myThread=null;
	}
	
	public LabelThread(HighLowPanel p) {
		nStart=1;
		nFinish=1;
		//myThread=null;
		primary=p;//�ٸ� �޼ҵ忡���� ������ ������ ����
		
		//��ü�� �ϳ�
	}//labelthread() �ش� Ŭ������ ��ü�� �Ķ���ͷ� ���� 
	
	public LabelThread(int s,int f) {
		nStart=s;
		nFinish=f;
	}//LabelThread()
	
	public LabelThread(String str) {
		//setText(str);
		super(str);// �θ� ���ڿ��� ���� �ϸ� �����׵� ���ڿ��� ���� �Ǵ°� 
		nStart=nFinish=1;
		//myThread=null;
	}
	
	//get/set method ����
	public int getStart() {return nStart;}
	public int getFinish() {return nFinish;}
	public void setStart(int s) {nStart=s;}
	public void setFinissh(int f) {nFinish=f;}
	public void setRange(int s,int f) {nStart=s; nFinish=f;}
	
	//thred ���� �޼ҵ�
	public void start() {
		myThread=null;
		/*if(myThread==null) {
			myThread=new Thread(this);//runnable �� this�� 
			//���� �����ε� thread ���� �ʱ�ȭ �ϴ� ��� ���� 
		}*/
		myThread=new Thread(this);
		myThread.start();//this �� �ִ� run method�� �����
	}//start
	
	//thread ���� ���� �޼ҵ�
	public void stop() {
		if(myThread!=null) myThread.stop();
	}//stop()
	
	
	public void run() {
		// ���� ���� ó�����ֱ� ���ؼ� try catch���ش�. 
		try {
			//ó�����ں��� �����ڱ��� ���ڸ� ����Ѵ�.
			for(int i=nStart; i<nFinish;i++) {
				setText(Integer.toString(i));
				myThread.sleep(100);//�ʹ� ���� �Ⱥ��̴ϱ� ���ڰ��� �ð� ���� ����
			}//for
			setForeground(Color.red);//������ڰ� �Ǹ� ���� �� ���������� �ٲ�
			//�ð� ������ �ΰ� ���ڸ� ������ �Ⱥ����� �ؼ� ���ڰ� ���� �Ÿ��� ��ó�� ���̰� �Ѵ�.
			for(int i=0;i<10;i++) {
				setVisible(false);
				myThread.sleep(200);
				setVisible(true);
				myThread.sleep(200);
			}
			//���ڰ� �����Ÿ��鼭 ���ÿ� �˸�â�� �߸� �ȵǹǷ� ���� �Ÿ��°� ���� �Ŀ� gameContinue â�� ����ش�.
			primary.gameContinue();
		}catch(Exception e) {}
	}//run() runnable �����Ϸ��� �ݵ�� run() �޼ҵ尡 �־�ߵȴ�.
	
}//LabelThread class
