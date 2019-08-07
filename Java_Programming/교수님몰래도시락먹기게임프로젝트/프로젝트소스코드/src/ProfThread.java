import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ProfThread extends JLabel implements Runnable {
   private Thread myThread;//thread변수
   private JLabel fprofessor,bprofessor; //교수님 앞모습 뒷모습 라벨
   private GamePanel g;//gamePanel 받기 위한 변수
   private int r;//random 값 저장하기 위한 변수
   private SettingSound sound;
   
   public ProfThread(GamePanel p,SettingSound gameSound) {
      myThread=null;//thread초기화
      
      g=p;//객체 인자 대입
      sound = gameSound;
      
      //교수님 앞모습을 넣고 크기 조정
      ImageIcon originIcon = new ImageIcon("images/yohanfront.png");
      Image originImg = originIcon.getImage();
      Image changedImg = originImg.getScaledInstance(280, 600, Image.SCALE_SMOOTH);
      ImageIcon prof = new ImageIcon(changedImg);
      //교수님 크기 지정후 gamePanel에 붙임
      fprofessor = new JLabel(prof);
      fprofessor.setBounds(1400,20,250,600);
      fprofessor.setBackground(Color.black);
      g.add(fprofessor);
      fprofessor.setVisible(false);
       
      //교수님 뒷모습을 넣고 크기 조정
      ImageIcon originybIcon = new ImageIcon("images/yohanback.png");
      Image originybImg = originybIcon.getImage();
      Image changedybImg = originybImg.getScaledInstance(280, 600, Image.SCALE_SMOOTH);
      ImageIcon profyb = new ImageIcon(changedybImg);
      //교수님 크기 지정후 gamePanel에 붙임
      bprofessor = new JLabel(profyb);
      bprofessor.setBounds(1400,20,250,600);
      bprofessor.setBackground(Color.black);
      g.add(bprofessor);
   }
   
   //thread 생성 안됐을 시에 생성하고 thread시작하는 함수
   public void start() {
     if(myThread==null) {
        myThread=new Thread(this);
     }
      myThread.start();
   }//오버라이딩
   
   //thread 멈추는 함수
   public void stop() {
      if(myThread!=null) myThread.stop();
   }
      
   
   public void run() {
	      try {
	         while(g.getCurrentTime()!=0){
	            //타이머변수가 0이 되때까지 while문            
	            //맨처음에 교수님 뒤돌아 있는 상태 시간을 랜덤값을 뽑아 결정
	            r=(int)(Math.random()*100)+1;
	            fprofessor.setVisible(false);
	            bprofessor.setVisible(true);
	            myThread.sleep(r*50);//랜덤값 시간만큼 교수님 뒤돌아있음
	              ///////////////////////////////////////
	           // if(sound.getEffectIsOn()) {
	           //  sound.playEffectSound();
	         // }
	            ////////////////////////////////
	           //또 랜덤값을 뽑아서 난수 범위 안에 들면 교수님이 앞을 본다.
	            r=(int)(Math.random()*100)+1;
	            if(r<g.getBackRandom()) {
	               //////////////////////////////////////
	               /////////////////////////////////////
	                fprofessor.setVisible(true);
	                bprofessor.setVisible(false);

	                sound.stopEffectSound();
	                myThread.sleep(500);//교수님이 돌아보자마자 바로 걸리지 않도록 판정시간 넣어줌
	                r=(int)(Math.random()*g.getBackRandom())+1;//랜덤으로 수를 뽑음
	                for(int j=0;j<r*50;j++) {
	                   if(g.getFlag()==1) {
	                	  g.setCheckProf(1);
	                      g.subControl();
	                   }
	                   myThread.sleep(1);
	                }//교수님이 앞을 보는 동안은 숟가락을 들면 gameOver되도록 subcontrol에서 설정 , for문으로 1씩 sleep해줌  이것도 랜덤으로 배정
	   

	                //교수님이 뒤를 돌아보고 있는 시간도 랜덤으로 다시 해줌
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