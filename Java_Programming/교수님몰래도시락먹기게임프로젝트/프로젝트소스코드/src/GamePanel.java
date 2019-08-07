import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GamePanel extends JPanel {
	private SubMain sub;
	private SettingSound sound;
   
   private int timer_max; //���̵��� �־����ð�
   private int extraTime; //�߰��ð�
   private int onigiriCnt; //�ָԹ� ����
   private int currenttime;
   
   private int random; //��ǳ�� �� ���� ���� ����
   private int clickCnt; //���콺 Ŭ�� �� ->�ָԹ�n�󸶳� �Ծ����˼�����
   private int flag; //���� �����ִ��� �Ʒ��ִ��ľ˼��ִ�
   private int backRandom; // �ڵ��� ���� ����
   private int check_prof; // �������� �ڵ��Ƽ� ������ �������� �˾ƿ��� ����
   
   private BubbleThread bubble;//��ǳ��
   private ProfThread professor;//������ �յ��� �ڵ���
   
   private SwingProgressBarExample TimerLabelThread; //�ð��� ������ �˷��ִ� ���α׷��� ��
   private JLabel PalLabelThread,PalLabelThread2; // ������ �����ϸ鼭 �����̴� ���� �̹��� �ΰ�(�÷ȴ� �����°�)
   private JLabel PlateLabelThread; //�ָԹ�ؿ� ����ִ� �׸��̹���
   
   private JLabel[] rockRice; // �ָԹ�
   private ClickListener click; //Ŭ�����޾ƿ��� ClickListener
   
   private ImageIcon cityrock; //���ö�
   private ImageIcon talkbubble; //��ǳ�� 
   private ImageIcon gameback; // ���� ����ȭ���� ���ȭ��
   
   public GamePanel(SubMain p,SettingSound gameSound) {
	   sub = p;
	   sound = gameSound;
      gameback = new ImageIcon("Images/gameback.png");
         
      setPreferredSize(new Dimension(2000,1000)); // ������ ����
      setLayout(null); // ���̾ƿ����ֱ�
      
      clickCnt=0; // ���� ����Ǹ鼭 Ŭ���� Ƚ��
      flag = 0; // ���� �Դ� �����̳� �ƴϳĸ� �Ǻ��ϴ� ����
      click = new ClickListener();
      addMouseListener(click);
      
      PalLabelThread = new JLabel( new ImageIcon("images/spoon.png")); // ���� �����ʰ� �ִ� ������ �̹���
      PalLabelThread.setBounds(1300, 500, 700, 480); // ��ġ�� ����������
      add(PalLabelThread); // �гο� �ٿ���
      PalLabelThread.setVisible(true); // ���� ���۽ÿ��� ���� ���� ���� �̴ϱ� ������
      
      PalLabelThread2 = new JLabel(new ImageIcon("images/spooneat.png")); // ���� �԰� �ִ� ������ �̹���
      PalLabelThread2.setBounds(1100, 500, 900, 480);// ��ġ�� ������ ����
      add(PalLabelThread2); // �гο� �ٿ���
      PalLabelThread2.setVisible(false); // ���� ���۽ÿ��� ���� �԰� ���� �������� �������� ����
      
      ImageIcon originBIcon = new ImageIcon("images/talkbubble.png"); // ��ǳ���̹���
      Image originBImg = originBIcon.getImage();
      Image changedBImg = originBImg.getScaledInstance(800, 450, Image.SCALE_SMOOTH);// �̹����� �޾ƿͼ� ũ�⸦ ���� ������ �� ����
      ImageIcon talkbubble = new ImageIcon(changedBImg); // ũ�⸦ �ٲ� �̹����� talkbubble�� ��������
      bubble=new BubbleThread(talkbubble,this); // talkbubble�� �����ϰ�
      bubble.setBounds(700,50,800,450); // ��ġ�� ����� �����ϰ�
      add(bubble); //�гο� �ٿ��ش�
     
      currenttime = 0; // ������� ����� �ð��� 0���� �ʱ�ȭ ���ش�
      professor=new ProfThread(this,sound); // �������� �������ش�
      
      check_prof = 0;
   }
   
   
   public void setOnigiri(int cnt) { // ���ϱ⸮ ��ġ ����ִ� �Լ�
	   int oni; // �ָԹ� ��ġ�� �������ֱ� ���� ���̰� �� ����
	   onigiriCnt = cnt; // �������� �ָԹ� ������ �ٸ��� ������ �ָԹ� ������ ���ڷ� �޾ƿͼ� onigiriCnt�� �����Ѵ�
	   rockRice = new JLabel[onigiriCnt]; // 8�κ��� ������ �޾ƿ;ߵ�
	      
	   for(int i=0;i<onigiriCnt;i++) { // ���� �ָԹ� �ϳ��ϳ� �迭�� ��ġ ����
		   oni = onigiriCnt/2; // �ָԹ��� ���ٷ� ������ ��ġ ��ų�ű� ������ �ָԹ� ������ ���� ������ �������ش�
	       rockRice[i]=new JLabel(new ImageIcon("images/onigiri.png")); // �̹��� �������ְ�
	       if(onigiriCnt==6) { // ���̵� �� �϶��� �ָԹ��� 6���� �־�����
	    	   if(i<oni) { // 1~3�� ������ ���ٿ� ��ġ��Ű��
	    		   rockRice[i].setBounds(1300/(oni+1)*i+350,450,300,300);
	    	   }
	    	   else  { // 4~6���� �� �����ٿ� ��ġ��Ų��
	    		   rockRice[i].setBounds(1300/(oni+1)*(i%oni)+350,650,300,300);
	    	   }
	    	   add(rockRice[i]); // ��ġ ��Ų�� �гο� �����ش�
	      }
	       else if(onigiriCnt==10) { // ���̵� �� �϶��� �ָԹ��� 10���� �־�����
		       if(i<oni) { //1~5�� ���ٿ� ��ġ��Ű��
		          rockRice[i].setBounds(1300/(oni+2)*i+300,450,300,300);
		       }
		       else  { // 6~10���� �� �����ٿ� ��ġ��Ų��
		          rockRice[i].setBounds(1300/(oni+2)*(i%oni)+300,650,300,300);
		       }
		       add(rockRice[i]); // �гο� �����ش�
		   }
	       else if(onigiriCnt==14) { // ���̵� ���϶��� �ָԹ��� 14���� �־�����.
		       if(i<oni) { //1~7���� ���ٿ� ��ġ��Ű��
		          rockRice[i].setBounds(1300/(oni+4)*i+300,450,300,300);
		       }
		       else  { // 8~14���� �� �����ٿ� ��ġ��Ų��
		          rockRice[i].setBounds(1300/(oni+4)*(i%oni)+300,650,300,300);
		       }
		       add(rockRice[i]); // �гο� �����ش�
		   }
	   }
	   ImageIcon originCIcon = new ImageIcon("images/cityrock0.png"); //��ġ��Ų �ָԹ� �ؿ� ������� �׸��̹���
	   Image originCImg = originCIcon.getImage(); // �̹����� �����ͼ�
	   Image changedCImg = originCImg.getScaledInstance(1200, 400, Image.SCALE_SMOOTH); // ���ϴ�ũ��� �ٲ�����
	   ImageIcon cityrock = new ImageIcon(changedCImg); // ���ϴ� ũ��� �ٲ� �̹����� ���� �����ϰ�
	   PlateLabelThread = new JLabel(cityrock); // ���� ������ �̹����� JLabel�� �����Ѵ�
	   PlateLabelThread.setBounds(100, 500, 1300, 500); // ��ġ�� ����� ������������
	   add(PlateLabelThread); // �гο� �ٿ��ش�
   } // setOnigiri()
 
   
   public void professorStart() {	   
	   professor.start(); // �������� ���ƺ��� �����带 ���۽�Ű�� �żҵ�
   }
   
   public void professorStop() {
	   professor.stop();
   }

   void setTime(int time, int ctime,int e) { // ������ �־����� �ð��� �߰��ð� �׸��� �ٽ� �����ɶ� ���λ����Ǳ����� ���� �ð��� �����Ѵ�
	      timer_max = time; // �־����½ð�
	      currenttime = ctime; // �����Ǿ����� ������� ����Ǿ����� �˷��ִ� ����
	      extraTime=e; // �ָԹ� �Ա⿡ �����Ͽ����� �־����� �߰��ð�
	   }
   void setBackRandom(int r) {backRandom=r;} // ���ƺ��� �ð��� ����
   public void setTimer_max(int timer_max) {this.timer_max = timer_max;} // �־����� �ð��� �����ϴ� �¸޼ҵ�
   public void setExtraTime(int extraTime) {this.extraTime = extraTime;} // �߰��ð��� �����ϴ� �� �޼ҵ�
   public void setCurrenttime(int currenttime) {this.currenttime = currenttime;} // ��������ð��� �����ϴ� �� �޼ҵ�
   public void setCheckProf(int check) {check_prof = check;}
   public int getBackRandom() {return backRandom;} // ���ƺ��� ������ �޾ƿ��� �żҵ�
   public int getFlag() {return flag;} // ���� �ָԹ��� �԰��ִ� �������� �ƴ����� �ܺ��� Ŭ�������� �˷��ִ� �� �żҵ�
   public int getCurrentTime() {return currenttime;} // ���� ������� ���� �Ǿ����� �ܺο��� �˼��ְ� �˷��ִ� �� �żҵ�
   public int getTimer_max() {return timer_max;} //��������Ǵ� ������ �־��� �ð��� ���� �˷��ִ� �� �żҵ�
   public int getExtraTime() {return extraTime;} //�߰��ð��� ������ �˷��ִ� �� �޼ҵ�
   public int getOnigiriCnt() {return onigiriCnt;} // ���� �����ִ� �ָԹ� ������ �˷��ִ� �żҵ�
   public int getCheckProf() {return check_prof;}
   
   public void C_sta() {  // Ŭ���� Ƚ���� ���� ���� �԰� �ִ��� �԰� ���� ������ �˷��ִ� �Լ�   
      if(clickCnt%2==0) {  // ���� ¦���� Ŭ�� �Ǿ����� 
         PalLabelThread.setVisible(true); // �԰� ���� ���� ���·� �����ְ�
         PalLabelThread2.setVisible(false); // ��Դ� �̹����� �������� �ʴ´�
         flag=0; // flag = 0���� ������ ������ 
      }    
      else { // Ȧ�������� Ŭ�� �Ǿ�������
         PalLabelThread.setVisible(false); // ���� ���� �ʰ��ִ� �̹����� �Ⱥ��̰��ϰ�
         PalLabelThread2.setVisible(true); // ���� ��� ���� �԰� �ִ� �̹����� �����ش�
         flag=1; // ���� �԰� ������ �˷��ֱ� ���� flag��� ������ 1�� �����Ѵ�
      }
   }
   
   public void setTimerThread() { // ������ �ð��� ���¸� �˷��ֱ� ���� ���α׷��� �ٸ� �����ϴ� �żҵ��̴� 
	   TimerLabelThread = new SwingProgressBarExample(this,timer_max,currenttime); 
	   //�������� �־��� �ð��� �ٽ� �����Ǿ����� ���� �ð��� �ٲ�� ���ؼ� �־��� �ð��� ���� �ð� �ΰ��� ���ڷ� �޴´�
	   add(TimerLabelThread); // �гο� �߰� �����ְ�
	   TimerLabelThread.start(); // �����带 �����Ѵ�
   } // ������ �ȿ� �� �Լ��� �ִٸ� ��ó�� subMain���� ��� ȭ���� �����Ҷ����� �����尡 ���۵Ǳ� ������ ������ ���� ������ �����ϸ� �̹� ���α׷����ٰ� �پ�� ���·� ������ �����ϱ� ������
     // subMain���� ������ ���� ȭ���� �ѱ涧 �� �żҵ带 ȣ�� �Ͽ��� �������� ���α׷����ٰ� ����� ����ǵ��� ���ش�
   
   
   public void stop_Thread() {
	    TimerLabelThread.progressBar.setVisible(false); // ������ ���α׷����ٸ� ���ش� ������������ ����
	    TimerLabelThread.setThread();
	   	TimerLabelThread.setVisible(false);
	   	TimerLabelThread.removeAll();
	   	TimerLabelThread=null; 
   }
   public void prog_State() { // �߰� �ð����� ���� progressBar�� �ٽ� �����ϰ� ���� �ٲ��ִ� ��
	   if(!TimerLabelThread.getStop()) {
	   		currenttime = TimerLabelThread.getCurrentTime(); // Ŭ������ ���� �ð��� �޾ƿ� (Ŭ�� �ø��� �� �Լ��� ȣ���)
		   	if(clickCnt%4==0 ) { //�ָԹ��� 4�� Ŭ�� �Ҷ����� �ϳ� �Ե��� �����Ͽ����ϱ� Ŭ������ 4�� ����� ��
		   	onigiriCnt--; // �ָԹ� ���� �ϳ��� ���̰�
		   	rockRice[onigiriCnt].setVisible(false); // �ϳ��� �Ⱥ��̰��Ѵ�
		   	if(onigiriCnt == 0) { // �ָԹ� ������ �ٿ����� �������� ���� �ٸԾ ������ �����ϴ� ���
			   	TimerLabelThread.setStop(true);
			   	sub.EndAction("./Images/success.png"); // subMain���� EndAction()�żҵ带 ȣ���ϰ� ���ȭ������ ���� �̹����� ���ڷ� �����ش�
		   	}
		   	else { // �ָԹ��� �� �����ʾ����� ���� ������ �پ�鶧�� �߰��ð��� ��ģ ���� ���α׷������� ���ప���� �ٽ� �������ش�
			   	if(currenttime<= timer_max-extraTime) { // �߰��ð��� �������� ������ �ִ� �־��� �ð� ���� �þ�� �ȵǱ� ������ ������ �������ش�
			   		currenttime += extraTime; // �߰��ð��� ��������
			   		TimerLabelThread.setStop(true);
				   	stop_Thread(); // ������ ���α׷����ٸ� ����� �żҵ带 ȣ���ϰ�
				   	setTimerThread(); // �߰� �ð��� ���� ���� ���� ����ð����� �ϴ� ���α׷��� �ٸ� �ٽû����ϰ�
				   	repaint(); // repaint���ش�
			   	}
			   	else { // ���� �߰��ð��� �������� �ִ�ð��� �Ѿ�� �ȴٸ�
			   		currenttime = timer_max; // ��������ð��� �ִ� �ð����� �ٲ�����
				   	TimerLabelThread.setStop(true);
				   	stop_Thread();// ������ ���α׷����ٸ� ����� �żҵ带 ȣ���ϰ�
				   	setTimerThread();// �߰� �ð��� ���� ���� ���� ����ð����� �ϴ� ���α׷��� �ٸ� �ٽû����ϰ�
				   	repaint();// repaint���ش�
			   	}
		   		}
	   		}
	   }
   }
            
   public void subControl() { // ���� �԰� ������ �������� �ڵ��� ���ø� ������ ������ ȭ������ �ٲ��ִ� �żҵ�
	   TimerLabelThread.setStop(true); // ���α׷����پȿ� ������ ���߰� �ؼ� ������ ���α׷����ٿ��� ���޾ƿ��°� ���´�
	   sub.EndAction("./Images/gameoverback.png");
   }
   
//getflag�� ������ �ڵ� ��� �ٵ� 
   private class ClickListener implements MouseListener{
      public void mouseClicked(MouseEvent event) {}
      public void mousePressed(MouseEvent event) {}
      public void mouseReleased(MouseEvent event) {                               
         clickCnt++; // ���콺�� �����ٰ� �������� Ŭ������ �����ְ�
         if(check_prof == 0)
        	 prog_State(); // Ŭ���ø����� ������ ��ȭ�� ���� prog_State()�żҵ带 ȣ���Ѵ�
         if(clickCnt==1) { // ó�� �ѹ� �������� ��ǳ���� �����ϰ�
            bubble.start();
            if(sound.getEffectIsOn()) {
                sound.playEffectSound();
             }
            professorStart();//������ �ڵ��� ����
         
         }
         C_sta(); // ���� �԰� �ִ� �������� �ƴ����� ���� ��ȭ�� �����ϱ� ���ؼ� C_sta()�żҵ带 ȣ���Ѵ�
      }
      public void mouseEntered(MouseEvent event) {}
      public void mouseExited(MouseEvent event) {}
   }
   
   public void paintComponent(Graphics page) { // ����ȭ�� �׸���
         super.paintComponent(page);
         page.drawImage(gameback.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
      }//���ȭ�� �׷���
}
                               
                       