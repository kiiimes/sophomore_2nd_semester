import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BubbleThread extends JLabel implements Runnable {

   private String[] bubbleStr={"�л�������~ �� �� ���� ������","���� �ָ��� ��Ű���� �ٳ�Ծ��~","��� ���ö� ���� ���� �ʾƿ�?","������ ������ ����?","����,����,����~^^","Ŀ�ǿ� ������ ��� ��� ������� �����"};
   //��ǳ�� �ȿ� ���� ������
   private Thread myThread;
   private ImageIcon sav; //�̹��� �޴� ����
   private GamePanel g;//gamePanel �޴� ����
   
   //������
   public BubbleThread() {
      myThread=null;
   }
   public BubbleThread(ImageIcon icon,GamePanel p) {
      myThread=null;
      g=p;//��ü�� ���ڷ� �޾Ƽ� ����� �� �ֵ��� �Ѱ��ش�.
      setIcon(icon);
   }
   
   //get/set method
   public String[] getStr() {return bubbleStr;}
   public void setStr(String[] s) {bubbleStr=s;}
   
   
   public void start() { //������ ������ ����
	  if(myThread==null) {
		  myThread=new Thread(this);
	  }//�ѹ��� �����ϱ� ���ؼ� null�϶� ����
      myThread.start();
   }//�������̵�
   
   public void stop() { // ������ ������
      if(myThread!=null) myThread.stop();
   }
      
   
   public void run() { // ������ ����
      try {
    	  int i=0;
         while(g.getCurrentTime()!=0){
            //Ÿ�̸Ӻ����� 0�� �Ƕ����� while��
            setFont(new Font("Courier",Font.BOLD,30)); //�۾� ����
            setText(bubbleStr[i%6]);//6���� ������� ��� �����ش�.
            setHorizontalTextPosition(SwingConstants.CENTER);
            myThread.sleep(5000);
            i++;//i�� �߰���Ű�鼭 ��ǳ���� ���� ��� ���� �� �ְ� ���ش�.
         }         
      }catch(Exception e) {}
   }
}