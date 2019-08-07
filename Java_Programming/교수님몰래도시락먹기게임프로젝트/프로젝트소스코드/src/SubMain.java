import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class SubMain extends JPanel {
   //�����̸Ӹ� �г� �����;ߵ� 
   // �ƴϸ� ���⿡�� �����̸Ӹ� �г� ����� �� �г��� �����;ߵ� 
   //���� �U���� ��� �ƴϸ� ���� �� panel�� primary�� ����� ������ this �Ѱ���

   private GameMain gMain; //������ ����ȭ�� ��ü
   private SetLevel sLevel; //���� ����ȭ�� ��ü
   private GamePanel gPanel; //���� ����ȭ�� ��ü
   private EndDisplay endDisplay; //������ ȭ��
   private SettingPanel settingPanel;//���� ȭ��

   private SettingSound gameSound;//���� ���� ��ü
   //�ٽ� �ϱ⸦ ���� ���� �������ִ� ������
   private int savMax;
   private int savExtra;
   private int savCurrent;
   private int savBackRandom;
   private int savOnigiriCnt;

   public SubMain() {

      //setPreferredSize(new Dimension(2000,1000));//�г� ũ�� ����
      gMain = new GameMain(this);
      add(gMain);//���Ӹ���ȭ�鿡 sub��ü�� �����ְ� ���� �����̸Ӹ��� add

      sLevel = new SetLevel(this);
      add(sLevel);//����ȭ�鿡 sub��ü�� �����ְ� ���� �����̸Ӹ��� add

      gameSound = new SettingSound();
      gameSound.playBackgroundSound();
      //���� ���� ��ü ���� �� �ٷ� ����

      gPanel = new GamePanel(this,gameSound);
      add(gPanel);//���ӽ���ȭ�鿡 sub��ü�� �����ְ� ���� �����̸Ӹ��� add

      endDisplay = new EndDisplay(this);
      add(endDisplay);//������ ȭ�� �߰�!

      settingPanel = new SettingPanel(this,gameSound);
      add(settingPanel);//����ȭ�鿡 sub��ü�� settingSound��ü�� �����ְ� ���� �����̸Ӹ��� add

      //ó������ gMain�� ������ ������ �гε��� �� ������ �ʰ� ��
      sLevel.setVisible(false);
      gPanel.setVisible(false);
      endDisplay.setVisible(false);
      settingPanel.setVisible(false);

   }//������

   public void startAction() {
      gMain.setVisible(false);
      sLevel.setVisible(true);
   }//���� ��ŸƮ ��ư ������ ���� ����ȭ�� ������� ��������ȭ������ �̵�

   public void settingAction(int i) {
      if(i == 0) {
         gMain.setVisible(true);
         settingPanel.setVisible(false);
      }
      else {
         gMain.setVisible(false);
         settingPanel.setVisible(true);
      }
   }//������ư ������(i == 1) ȯ�漳�� ȭ�� ����
   //����ȭ�鿡�� Ȩ��ư ������(i == 0)Ȩȭ�� �ٽ� ���� 


   public void LlevelAction(){
      //����ȭ�� �Ⱥ��̰� �ϰ� �������� ȭ�� ���̰���
      sLevel.setVisible(false);
      gPanel.setVisible(true);

      gPanel.setTime(15,15,3); //���̵��� Ÿ�̸ӽð�
      gPanel.setTimerThread(); //Ÿ�̸� ����
      gPanel.setBackRandom(90);//���̵� �� ���� ����
      gPanel.setOnigiri(6); //���̵� �� �ָԹ� ����
      gameSound.stopBackgroundSound();//������� ���߱�
      //�ٽý��� ���� ���� �����ص�
      savMax=15;
      savCurrent=15;
      savExtra=3;
      savBackRandom=90;
      savOnigiriCnt=6;
      ////////////////////////////////////////////////////////////
      
      ////////////////////////////////////////////////////////////
   }//���̵� ��,�� �Ѱ�¥�� ��ư�� ������ ���� ������ ����

   public void MlevelAction(){
      sLevel.setVisible(false);
      gPanel.setVisible(true);
      gPanel.setTime(13,13,2);//���̵��� Ÿ�̸� �ð�
      gPanel.setTimerThread();
      gPanel.setBackRandom(85);//���̵� �� ���� ����
      gPanel.setOnigiri(10);//���̵� �� �ָԹ� ����
      savMax=13;
      savCurrent=13;
      savExtra=2;
      savBackRandom=85;
      savOnigiriCnt=10;
      gameSound.stopBackgroundSound();
      ////////////////////////////////////////////////////////////
      
      ////////////////////////////////////////////////////////////
      //�������� ������ ���ӽ����ϱ� ���� �뷡 ����
   }//���̵� ��,�� �ΰ�¥�� ��ư�� ������ ���� ������ ����

   public void HlevelAction(){
      sLevel.setVisible(false);
      gPanel.setVisible(true);
      gPanel.setTime(10,10,1);//runtime�� currenttime�� ������ �׿� �°� �⺻����
      gPanel.setTimerThread();//�⺻�������� ����
      gPanel.setBackRandom(90);//���̵� �� ���� ����
      gPanel.setOnigiri(14);//���̵� �� �ָԹ� ����
      gameSound.stopBackgroundSound();
      savMax=10;
      savCurrent=10;
      savExtra=1;
      savBackRandom=90;
      savOnigiriCnt=14;
      ////////////////////////////////////////////////////////////
   
      ////////////////////////////////////////////////////////////
   }//���̵� �� ,�� ����¥�� ��ư�� ������ ���� ������ ����


   //���� ���� ȭ�� ������� ������ ȭ�� ���;� �Ѵ�
   public void EndAction(String str) {
	   gameSound.stopEffectSound();
	   endDisplay.setBackImg(str);//�̱�� ���� ���� ���ȭ�� ����
	      endDisplay.setVisible(true);
	      gPanel.stop_Thread();//������ ���߰�
	      gPanel.setVisible(false);
	      gPanel.professorStop();
	      gPanel = null;
      
   }//�����г� ���� �ʱ�ȭ �����ְ� ���� ���� ȭ�� ������ �Լ�


   public void replay() {
      endDisplay.setVisible(false);
      
      gPanel = new GamePanel(this,gameSound);//������ ���� �� GamePanel��ü�� ������ �ʱ�ȭ �ϱ����� ���� �����Ѵ�.
      add(gPanel);

      //�ش� ���̵��� ������ �ٽ� �����ϱ� ���ؼ� �����س��� ������ ���� ����
      gPanel.setTime(savMax,savCurrent,savExtra);      
      gPanel.setTimerThread();// �⺻�� �°� ����
      gPanel.setBackRandom(savBackRandom);
      gPanel.setOnigiri(savOnigiriCnt);
      gPanel.setVisible(true);
      ////////////////////////////////////////////////////////////
      
   }//�ٽý��� �Լ�

   public void BackMain() {
      //������ ȭ�� ���ְ� �ٽ� ���� ȭ�� ������
      endDisplay.setVisible(false);
      gPanel = null;
      gPanel = new GamePanel(this,gameSound);//������ ���� �� GamePanel��ü�� ������ �ʱ�ȭ �ϱ����� ���� �����Ѵ�.
      if(gameSound.getBackgroundIsOn() == true) {
         gameSound.playBackgroundSound();   
      }//���� ������ ȭ�� �ٲٸ鼭 ���� gameSound.getBackgroundIsOn()�� true�̸� �뷡 ����

      add(gPanel);
      gMain.setVisible(true);
   }//�������� ���ư��� �Լ�
}