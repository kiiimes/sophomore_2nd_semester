import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class SubMain extends JPanel {
   //프라이머리 패널 가져와야됨 
   // 아니면 여기에서 프라이머리 패널 만들고 그 패널을 가져와야됨 
   //만든 쪾에서 사용 아니면 여기 이 panel을 primary로 만들고 변수로 this 넘겨줌

   private GameMain gMain; //게임의 메인화면 객체
   private SetLevel sLevel; //레벨 선택화면 객체
   private GamePanel gPanel; //게임 실행화면 객체
   private EndDisplay endDisplay; //마지막 화면
   private SettingPanel settingPanel;//설정 화면

   private SettingSound gameSound;//사운드 설정 객체
   //다시 하기를 위해 설정 저장해주는 변수들
   private int savMax;
   private int savExtra;
   private int savCurrent;
   private int savBackRandom;
   private int savOnigiriCnt;

   public SubMain() {

      //setPreferredSize(new Dimension(2000,1000));//패널 크기 설정
      gMain = new GameMain(this);
      add(gMain);//게임메인화면에 sub객체를 보내주고 메인 프라이머리에 add

      sLevel = new SetLevel(this);
      add(sLevel);//레벨화면에 sub객체를 보내주고 메인 프라이머리에 add

      gameSound = new SettingSound();
      gameSound.playBackgroundSound();
      //사운드 설정 객체 생성 및 바로 실행

      gPanel = new GamePanel(this,gameSound);
      add(gPanel);//게임실행화면에 sub객체를 보내주고 메인 프라이머리에 add

      endDisplay = new EndDisplay(this);
      add(endDisplay);//마지막 화면 추가!

      settingPanel = new SettingPanel(this,gameSound);
      add(settingPanel);//설정화면에 sub객체와 settingSound객체를 보내주고 메인 프라이머리에 add

      //처음에는 gMain을 제외한 나머지 패널들은 다 보이지 않게 함
      sLevel.setVisible(false);
      gPanel.setVisible(false);
      endDisplay.setVisible(false);
      settingPanel.setVisible(false);

   }//생성자

   public void startAction() {
      gMain.setVisible(false);
      sLevel.setVisible(true);
   }//게임 스타트 버튼 누르면 게임 메인화면 사라지고 레벨선택화면으로 이동

   public void settingAction(int i) {
      if(i == 0) {
         gMain.setVisible(true);
         settingPanel.setVisible(false);
      }
      else {
         gMain.setVisible(false);
         settingPanel.setVisible(true);
      }
   }//설정버튼 누르면(i == 1) 환경설정 화면 실행
   //설정화면에서 홈버튼 누르면(i == 0)홈화면 다시 복구 


   public void LlevelAction(){
      //레벨화면 안보이게 하고 실제게임 화면 보이게함
      sLevel.setVisible(false);
      gPanel.setVisible(true);

      gPanel.setTime(15,15,3); //난이도별 타이머시간
      gPanel.setTimerThread(); //타이머 시작
      gPanel.setBackRandom(90);//난이도 별 난수 범위
      gPanel.setOnigiri(6); //난이도 별 주먹밥 갯수
      gameSound.stopBackgroundSound();//배경음악 멈추기
      //다시시작 위해 설정 저장해둠
      savMax=15;
      savCurrent=15;
      savExtra=3;
      savBackRandom=90;
      savOnigiriCnt=6;
      ////////////////////////////////////////////////////////////
      
      ////////////////////////////////////////////////////////////
   }//난이도 하,별 한개짜리 버튼을 누르면 위의 설정이 시작

   public void MlevelAction(){
      sLevel.setVisible(false);
      gPanel.setVisible(true);
      gPanel.setTime(13,13,2);//난이도별 타이머 시간
      gPanel.setTimerThread();
      gPanel.setBackRandom(85);//난이도 별 난수 범위
      gPanel.setOnigiri(10);//난이도 별 주먹밥 갯수
      savMax=13;
      savCurrent=13;
      savExtra=2;
      savBackRandom=85;
      savOnigiriCnt=10;
      gameSound.stopBackgroundSound();
      ////////////////////////////////////////////////////////////
      
      ////////////////////////////////////////////////////////////
      //레벨선택 끝나고 게임실행하기 전에 노래 멈춤
   }//난이도 중,별 두개짜리 버튼을 누르면 위의 설정이 시작

   public void HlevelAction(){
      sLevel.setVisible(false);
      gPanel.setVisible(true);
      gPanel.setTime(10,10,1);//runtime과 currenttime을 보내서 그에 맞게 기본셋팅
      gPanel.setTimerThread();//기본셋팅으로 생성
      gPanel.setBackRandom(90);//난이도 별 난수 범위
      gPanel.setOnigiri(14);//난이도 별 주먹밥 갯수
      gameSound.stopBackgroundSound();
      savMax=10;
      savCurrent=10;
      savExtra=1;
      savBackRandom=90;
      savOnigiriCnt=14;
      ////////////////////////////////////////////////////////////
   
      ////////////////////////////////////////////////////////////
   }//난이도 상 ,별 세개짜리 버튼을 누르면 위의 설정이 시작


   //게임 실행 화면 사라지고 마지막 화면 나와야 한다
   public void EndAction(String str) {
	   gameSound.stopEffectSound();
	   endDisplay.setBackImg(str);//이기고 짐에 따라 배경화면 설정
	      endDisplay.setVisible(true);
	      gPanel.stop_Thread();//스레드 멈추고
	      gPanel.setVisible(false);
	      gPanel.professorStop();
	      gPanel = null;
      
   }//게임패널 전부 초기화 시켜주고 게임 종료 화면 나오는 함수


   public void replay() {
      endDisplay.setVisible(false);
      
      gPanel = new GamePanel(this,gameSound);//게임이 끝난 후 GamePanel객체를 정보를 초기화 하기위해 새로 생성한다.
      add(gPanel);

      //해당 난이도의 게임을 다시 시작하기 위해서 저장해놓은 값으로 게임 셋팅
      gPanel.setTime(savMax,savCurrent,savExtra);      
      gPanel.setTimerThread();// 기본에 맞게 생성
      gPanel.setBackRandom(savBackRandom);
      gPanel.setOnigiri(savOnigiriCnt);
      gPanel.setVisible(true);
      ////////////////////////////////////////////////////////////
      
   }//다시시작 함수

   public void BackMain() {
      //마지막 화면 없애고 다시 메임 화면 보여줌
      endDisplay.setVisible(false);
      gPanel = null;
      gPanel = new GamePanel(this,gameSound);//게임이 끝난 후 GamePanel객체를 정보를 초기화 하기위해 새로 생성한다.
      if(gameSound.getBackgroundIsOn() == true) {
         gameSound.playBackgroundSound();   
      }//게임 끝나고 화면 바꾸면서 만약 gameSound.getBackgroundIsOn()이 true이면 노래 실행

      add(gPanel);
      gMain.setVisible(true);
   }//메인으로 돌아가는 함수
}