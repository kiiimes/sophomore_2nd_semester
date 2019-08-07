import java.io.File;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class SettingSound{
   
   private Clip bgmClip,effectClip;//음악파일을 제어 할 수 있는 인터페이스 선언
   private File bgmSound,effectSound;//GameBgm 파일 저장 객체, GameEffect 파일 저장 객체
   private boolean backgroundIsOn,effectIsOn;//true이면 재생가능.false이면 재생 불가.
   
   
   //생성자
   public SettingSound() {
      bgmSound =new File("BGM/GameBGM.wav");//Clip에 음악 파일 저장
      effectSound =new File("BGM/GameEffect.wav");//Clip에 음악 파일 저장
      backgroundIsOn = effectIsOn = true; 
      try {
         effectClip = AudioSystem.getClip();//오디오파일이나 오디오 스트림에 사용항 수 있는 클립을 취득
         bgmClip = AudioSystem.getClip();//오디오파일이나 오디오 스트림에 사용항 수 있는 클립을 취득
      }
      catch(Exception e) {}
   }
   
   public boolean getEffectIsOn() {return effectIsOn;}
   public void setEffectIsOn(boolean effectIsOn) {this.effectIsOn = effectIsOn;}   
   public boolean getBackgroundIsOn() {return backgroundIsOn;}   
   public void setBackgroundIsOn(boolean backgroundIsOn) {this.backgroundIsOn = backgroundIsOn;}
   //getter,setter
   
   
   public void playBackgroundSound(){
      if(backgroundIsOn == true) {
         try {
            bgmClip.open(AudioSystem.getAudioInputStream(bgmSound));
            //지정한 오디오 입력 스트림내에 제시되고 있는 형식 및 오디오 데이터로 클립을 연다.
            bgmClip.start();//재생
            bgmClip.loop(Clip.LOOP_CONTINUOUSLY);//무한 재생
         }
         catch (Exception e) {}
      }
   }//배경음 재생 메소드

   public void stopBackgroundSound() {
      bgmClip.stop();
      bgmClip.close();
   }//배경음 정지 메소드
   
   public void playEffectSound(){
      if(effectIsOn == true) {
         try {
            effectClip.open(AudioSystem.getAudioInputStream(effectSound));
            //지정한 오디오 입력 스트림내에 제시되고 있는 형식 및 오디오 데이터로 클립을 연다.
            ////////////////////////////////////////////////////////////
            effectClip.loop(Clip.LOOP_CONTINUOUSLY);
            ////////////////////////////////////////////////////////////
            effectClip.start();   //재생
         }
         catch (Exception e) {}
      }
   }//효과음 재생 메소드
   
   public void stopEffectSound() {
         effectClip.stop();
         effectClip.close();
   }//효과음 정지 메소드
   
}//SettingSound