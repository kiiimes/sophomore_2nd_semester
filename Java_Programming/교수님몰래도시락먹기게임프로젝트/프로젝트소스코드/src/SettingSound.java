import java.io.File;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class SettingSound{
   
   private Clip bgmClip,effectClip;//���������� ���� �� �� �ִ� �������̽� ����
   private File bgmSound,effectSound;//GameBgm ���� ���� ��ü, GameEffect ���� ���� ��ü
   private boolean backgroundIsOn,effectIsOn;//true�̸� �������.false�̸� ��� �Ұ�.
   
   
   //������
   public SettingSound() {
      bgmSound =new File("BGM/GameBGM.wav");//Clip�� ���� ���� ����
      effectSound =new File("BGM/GameEffect.wav");//Clip�� ���� ���� ����
      backgroundIsOn = effectIsOn = true; 
      try {
         effectClip = AudioSystem.getClip();//����������̳� ����� ��Ʈ���� ����� �� �ִ� Ŭ���� ���
         bgmClip = AudioSystem.getClip();//����������̳� ����� ��Ʈ���� ����� �� �ִ� Ŭ���� ���
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
            //������ ����� �Է� ��Ʈ������ ���õǰ� �ִ� ���� �� ����� �����ͷ� Ŭ���� ����.
            bgmClip.start();//���
            bgmClip.loop(Clip.LOOP_CONTINUOUSLY);//���� ���
         }
         catch (Exception e) {}
      }
   }//����� ��� �޼ҵ�

   public void stopBackgroundSound() {
      bgmClip.stop();
      bgmClip.close();
   }//����� ���� �޼ҵ�
   
   public void playEffectSound(){
      if(effectIsOn == true) {
         try {
            effectClip.open(AudioSystem.getAudioInputStream(effectSound));
            //������ ����� �Է� ��Ʈ������ ���õǰ� �ִ� ���� �� ����� �����ͷ� Ŭ���� ����.
            ////////////////////////////////////////////////////////////
            effectClip.loop(Clip.LOOP_CONTINUOUSLY);
            ////////////////////////////////////////////////////////////
            effectClip.start();   //���
         }
         catch (Exception e) {}
      }
   }//ȿ���� ��� �޼ҵ�
   
   public void stopEffectSound() {
         effectClip.stop();
         effectClip.close();
   }//ȿ���� ���� �޼ҵ�
   
}//SettingSound