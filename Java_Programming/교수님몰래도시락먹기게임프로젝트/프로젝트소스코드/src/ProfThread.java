import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ProfThread extends JLabel implements Runnable {
   private Thread myThread;//thread����
   private JLabel fprofessor,bprofessor; //������ �ո�� �޸�� ��
   private GamePanel g;//gamePanel �ޱ� ���� ����
   private int r;//random �� �����ϱ� ���� ����
   private SettingSound sound;
   
   public ProfThread(GamePanel p,SettingSound gameSound) {
      myThread=null;//thread�ʱ�ȭ
      
      g=p;//��ü ���� ����
      sound = gameSound;
      
      //������ �ո���� �ְ� ũ�� ����
      ImageIcon originIcon = new ImageIcon("images/yohanfront.png");
      Image originImg = originIcon.getImage();
      Image changedImg = originImg.getScaledInstance(280, 600, Image.SCALE_SMOOTH);
      ImageIcon prof = new ImageIcon(changedImg);
      //������ ũ�� ������ gamePanel�� ����
      fprofessor = new JLabel(prof);
      fprofessor.setBounds(1400,20,250,600);
      fprofessor.setBackground(Color.black);
      g.add(fprofessor);
      fprofessor.setVisible(false);
       
      //������ �޸���� �ְ� ũ�� ����
      ImageIcon originybIcon = new ImageIcon("images/yohanback.png");
      Image originybImg = originybIcon.getImage();
      Image changedybImg = originybImg.getScaledInstance(280, 600, Image.SCALE_SMOOTH);
      ImageIcon profyb = new ImageIcon(changedybImg);
      //������ ũ�� ������ gamePanel�� ����
      bprofessor = new JLabel(profyb);
      bprofessor.setBounds(1400,20,250,600);
      bprofessor.setBackground(Color.black);
      g.add(bprofessor);
   }
   
   //thread ���� �ȵ��� �ÿ� �����ϰ� thread�����ϴ� �Լ�
   public void start() {
     if(myThread==null) {
        myThread=new Thread(this);
     }
      myThread.start();
   }//�������̵�
   
   //thread ���ߴ� �Լ�
   public void stop() {
      if(myThread!=null) myThread.stop();
   }
      
   
   public void run() {
	      try {
	         while(g.getCurrentTime()!=0){
	            //Ÿ�̸Ӻ����� 0�� �Ƕ����� while��            
	            //��ó���� ������ �ڵ��� �ִ� ���� �ð��� �������� �̾� ����
	            r=(int)(Math.random()*100)+1;
	            fprofessor.setVisible(false);
	            bprofessor.setVisible(true);
	            myThread.sleep(r*50);//������ �ð���ŭ ������ �ڵ�������
	              ///////////////////////////////////////
	           // if(sound.getEffectIsOn()) {
	           //  sound.playEffectSound();
	         // }
	            ////////////////////////////////
	           //�� �������� �̾Ƽ� ���� ���� �ȿ� ��� �������� ���� ����.
	            r=(int)(Math.random()*100)+1;
	            if(r<g.getBackRandom()) {
	               //////////////////////////////////////
	               /////////////////////////////////////
	                fprofessor.setVisible(true);
	                bprofessor.setVisible(false);

	                sound.stopEffectSound();
	                myThread.sleep(500);//�������� ���ƺ��ڸ��� �ٷ� �ɸ��� �ʵ��� �����ð� �־���
	                r=(int)(Math.random()*g.getBackRandom())+1;//�������� ���� ����
	                for(int j=0;j<r*50;j++) {
	                   if(g.getFlag()==1) {
	                	  g.setCheckProf(1);
	                      g.subControl();
	                   }
	                   myThread.sleep(1);
	                }//�������� ���� ���� ������ �������� ��� gameOver�ǵ��� subcontrol���� ���� , for������ 1�� sleep����  �̰͵� �������� ����
	   

	                //�������� �ڸ� ���ƺ��� �ִ� �ð��� �������� �ٽ� ����
	                  r=(int)(Math.random()*100)+1;
	                  fprofessor.setVisible(false);
	                  bprofessor.setVisible(true);

	                  if(sound.getEffectIsOn()) {
	                   sound.playEffectSound();
	                }

	                  myThread.sleep(r*50);
	               }
	         }         
	      }catch(Exception e) {}
	   }
	}