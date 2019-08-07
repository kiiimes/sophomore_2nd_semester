import java.awt.*;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.SwingUtilities;

public class SwingProgressBarExample extends JPanel implements Runnable{
   private int run_time; // ���ӿ� ���̺��� �־����� �ð���
   private int current_time; // ������������ ���� ����ð��� ������ ����
   private int extra_time; // ���̵��� �߰� �ð�
   
   private boolean stop; // run�żҵ� ���� for���� ������ �����Ű�� �ʱ����� ���ִ� boolean����
   
   private Thread myThread; // ������
   JProgressBar progressBar; // �������� ����ð��� �����ֱ� ���ؼ� progressbar�� �̿��Ѵ�
   private GamePanel g;
   
   public SwingProgressBarExample(GamePanel primary,int Rtime, int Ctime) { // ���� �гΰ� ó�� �ð� �׸��� ���� ����ð��� ���ڷ� �޴� ������
      g = primary;
      stop = false; // for������ ������ ���ư� ���ְ� �⺻������ ���ش�
      setLayout(null); //���̾ƿ��� �������μ� progressbar�� setsize�� ũ�⸦ �ٲ۴�
      setPreferredSize(new Dimension(1000,50)); // ���α׷������� ũ�⸦ �������ش�
      run_time = Rtime; // �̰� ���� ����ð�
      current_time = Ctime; // �̰Ŵ� ���� ����� �ð�
      myThread = null; // �����忡 ���� �־��ְ�
      progressBar = new JProgressBar(0,Rtime); //�ִ밪�� �־��� �ִ�ð����� ���α׷����ٻ���
      progressBar.setSize(1000,50); // ���α׷����� ���̸� �������ְ�
      progressBar.setForeground(Color.green); // ó�� �� ������ �ʷ� ������ �����ش�
      progressBar.setStringPainted(false); // �̰� true���ϸ� ������ ��������� ������
      g.add(progressBar);// g�гο� ���α׷����ٸ� ���Ѵ�
   }
   
   
   public void setThread() { this.progressBar = null;} // progressBar�� �η� ����� ������ �żҵ�
   public void setRuntime(int time) {run_time = time;} // ���̵��� �־��� �ð��� �������ִ� �żҵ�
   public void setCurrenttime(int time) {current_time = time;} // ���� ����� �ð��� �������ִ� �żҵ�
   public void setExtratime(int time) {extra_time = time;} // ���̵����� ���� �ٸ� �߰��ð��� �������ִ� �żҵ�
   public void setTime(int runtime, int extratime) { // runtime�� extratime�� �ѹ��� �������ִ� �żҵ�
      run_time = runtime;
      extra_time = extratime;
   }
   
   public int getRuntime() {return run_time;} // ���̵��� �־��� �ð��� �ܺο� �����ִ� ���żҵ�
   public int getCurrentTime() { return current_time;} // ����ð��� �ܺο� �˷��ִ� ���żҵ�

   public void setStop(boolean stop) {
	   this.stop = stop;
   }
   public boolean getStop() { return stop; }
   
   public void start(){ //thread ����
      if(myThread == null){
         myThread = new Thread(this); //runnable �� ������ ��ü�� �̾���߉�
      }
      myThread.start();//this���ִ�  run method ȣ��
   }//start() ->thread����
   
   public void stop(){ // ������ stop
      myThread.stop();
   }//stop()
 
   public void run(){ // ������ ����κ�
      for(int i=current_time;i>=0;i--) { // ���α׷����ٿ� ����� �ð��� �����ֱ����� for���̴�
         if(!stop) { // ���α׷����ٸ� �ٽ� �����ϰ� �ɶ� �������ϴ� ���� ���α׷����ٸ� �����ֱ� ���� stop������ ����Ѵ�
        	 progressBar.setValue(i); // ���α׷������� ���� �������ְ�
        	 current_time = i; // ����ð��� for���� i�� ��ȭ�� �°� ��� ��������ش�
             
            if(i<run_time/4) { // ���� �־��� �ð��� 4����1���� ���ݳ��Եȴٸ� �ð��� �� ���� �ʾ����� �˷��ֱ� ���ؼ�
               progressBar.setForeground(Color.red); // ���α׷������� ������ ���������� �ٲ��ش�
            }
            try{//����ó��
               myThread.sleep(1000); // 1�ʿ� �ѹ��� �پ��� �����
            }
            catch(Exception e){}
            if(i ==0) {
            	stop = true;
             	g.subControl(); //���� �ð��� �� �Ǿ������� gamePanel�� subControl()�żҵ带 ȣ���Ͽ��� ���α׷������� �����带 ���߰� ������ ������ ȭ������ �ٲ۴�
             }
         }
      }
   }//run()


}