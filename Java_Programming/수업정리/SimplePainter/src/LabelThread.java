import java.awt.Color;
import javax.swing.*;



public class LabelThread extends JLabel implements Runnable {
	
	private int type;//���� ������ �����ϱ� ���� ó���� �� ���� ����
	private Thread myThread;// thread �� �������ֱ� ���ؼ� thread�� �ʿ���
	private PrimaryPanel primary;// ���� �г��� upcall �ϱ� ���� ���� 
	private ValueGet valueBox;
	private int i=0;
	
	//LabelThread ������
	public LabelThread() {
		
		//myThread=null;
	}
	
	public LabelThread(int type) {
		this.type=type;
	}//LabelThread()
	
	//get/set method ����
	
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
			if(type==1) {
				while(true) {
					//Double.toString(valueBox.getPowerValue());
					i+=1;
					setText(Integer.toString(i));
					myThread.sleep(500);//�ʹ� ���� �Ⱥ��̴ϱ� ���ڰ��� �ð� ���� ����
				}//for
			}
			
			else if(type==2) {
				while(true) {
					//Double.toString(valueBox.getVoltValue());
					i+=2;
					setText(Integer.toString(i));
					myThread.sleep(500);//�ʹ� ���� �Ⱥ��̴ϱ� ���ڰ��� �ð� ���� ����
				}//for
			}
			
			else if(type==3) {
				while(true) {
					//Double.toString(valueBox.getCurrValue());
					i+=3;
					setText(Integer.toString(i));
					myThread.sleep(500);//�ʹ� ���� �Ⱥ��̴ϱ� ���ڰ��� �ð� ���� ����
				}//for
			}
			//���ڰ� �����Ÿ��鼭 ���ÿ� �˸�â�� �߸� �ȵǹǷ� ���� �Ÿ��°� ���� �Ŀ� gameContinue â�� ����ش�.
		
		}catch(Exception e) {}
	}//run() runnable �����Ϸ��� �ݵ�� run() �޼ҵ尡 �־�ߵȴ�.
	
}//LabelThread class
