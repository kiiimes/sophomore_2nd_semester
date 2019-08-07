import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class SettingPanel extends JPanel {
   private SubMain sub;
   private JButton backButton,backgroundOnBtn,effectOnBtn, backgroundOffBtn,effectOffBtn;
   //순서대로 메인으로돌아가는버튼,배경화면 온 버튼 ,효과음 온 버튼, 배경화면 오프버튼, 효과음 오프버튼
   private JLabel settingNamelbl,backgroundNamelbl,effectNamelbl;
   //순서대로 배경화면라벨,"환경설정"라벨, "배경음설정"라벨 , "효과음설정"라벨
   private JLabel programedBy;
   private GameListener gameL;
   //온오프 버튼 전환을 위한 리스너
   private BtnMenuListener btnL;
   //소리 재생 제어을 위한 리스너
   private SettingSound sound;
   
   private ImageIcon background;//SettingPanel 배경이미지
   
   public SettingPanel(SubMain p,SettingSound gameSound) {
      sub = p;//SubMain에서 받아온  SubMain의 객체 p를 sub에 연결 
      sound = gameSound;//SubMain에서 받아온 SettingSound의 객체 gameSound를 sound에 연결 
      
      gameL = new GameListener();//액션리스너 선언,생성
      btnL = new BtnMenuListener();//마우스리스너 선언,생성
      
      setLayout(null);//레이아웃 없애기
      setPreferredSize(new Dimension(2000,1000));
      
      //"환경설정" 라벨 생성
      settingNamelbl = new JLabel("환경설정");
      settingNamelbl.setFont(new Font("210 콤퓨타세탁 L",Font.BOLD,60));
      settingNamelbl.setLayout(null);
      settingNamelbl.setBounds(800,70,450,200);
      add(settingNamelbl);
      
    //"배경음설정" 라벨 생성
      backgroundNamelbl = new JLabel("배경음 설정");
      backgroundNamelbl.setFont(new Font("210 콤퓨타세탁 L",Font.BOLD,50));
      backgroundNamelbl.setLayout(null);
      backgroundNamelbl.setBounds(600,370,450,200);
      add(backgroundNamelbl);

      //배경음 설정의 on버튼
      backgroundOnBtn = new JButton(new ImageIcon("images/onBtn.png"));
      backgroundOnBtn.setLayout(null);
      backgroundOnBtn.setBounds(1000,440,200,60);
      backgroundOnBtn.addActionListener(gameL);//액션리스너 추가
      backgroundOnBtn.addMouseListener(btnL);//마우스리스너 추가
      backgroundOnBtn.setContentAreaFilled(false);
      backgroundOnBtn.setBorderPainted(false);
      add(backgroundOnBtn);

      //배경음 설정의 off버튼
      backgroundOffBtn = new JButton(new ImageIcon("images/offBtn.png"));
      backgroundOffBtn.setLayout(null);
      backgroundOffBtn.setBounds(1000,440,200,60);
      backgroundOffBtn.addActionListener(gameL);//액션리스너 추가
      backgroundOffBtn.addMouseListener(btnL);//마우스리스너 추가
      backgroundOffBtn.setContentAreaFilled(false);
      backgroundOffBtn.setBorderPainted(false);
      add(backgroundOffBtn);
      backgroundOffBtn.setVisible(false);

      //"효과음설정" 라벨 생성
      effectNamelbl = new JLabel("효과음 설정");
      effectNamelbl.setFont(new Font("210 콤퓨타세탁 L",Font.BOLD,50));
      effectNamelbl.setLayout(null);
      effectNamelbl.setBounds(600,540,400,200);
      add(effectNamelbl);

      //효과음 설정의 on버튼
      effectOnBtn = new JButton(new ImageIcon("images/onBtn.png"));
      effectOnBtn.setLayout(null);
      effectOnBtn.setSize(110,60);
      effectOnBtn.setBounds(1000,610,200,60);
      effectOnBtn.addActionListener(gameL);//액션리스너 추가
      effectOnBtn.setContentAreaFilled(false);
      effectOnBtn.setBorderPainted(false);
      add(effectOnBtn);

      //효과음 설정의 off버튼
      effectOffBtn = new JButton(new ImageIcon("images/offBtn.png"));
      effectOffBtn.setLayout(null);
      effectOffBtn.setSize(110,60);
      effectOffBtn.setBounds(1000,610,200,60);
      effectOffBtn.addActionListener(gameL);//액션리스너 추가
      effectOffBtn.setContentAreaFilled(false);
      effectOffBtn.setBorderPainted(false);
      add(effectOffBtn);
      effectOffBtn.setVisible(false);

      //홈으로 돌아가는 버튼
      backButton = new JButton(new ImageIcon("images/btnhome.png"));
      backButton.setLayout(null);
      backButton.setBounds(1500,750,180,180);
      backButton.addMouseListener(btnL);//마우스리스너 추가
      backButton.setContentAreaFilled(false);
      backButton.setBorderPainted(false);
      add(backButton);

      //programedBy 라벨
      programedBy = new JLabel("Programed By.. 최지현   김은숙   이수민   정주호");
      programedBy.setFont(new Font("210 콤퓨타세탁 L",Font.BOLD,18));
      programedBy.setLayout(null);
      programedBy.setBounds(700,950,500,50);
      add(programedBy);
      
      //배경이미지
      background=new ImageIcon("images/gameback.png");
   }


   //ActionListener
   private class GameListener implements ActionListener{
      public void actionPerformed(ActionEvent event) {
         Object obj = event.getSource();         
         if(obj == backgroundOnBtn) {
            backgroundOnBtn.setVisible(false);
            backgroundOffBtn.setVisible(true);
            sound.setBackgroundIsOn(false);
            //배경음 on버튼 누르면 off버튼 나오고 on버튼 사라짐
            //backgroundIsOn 데이터를 false로 바꿔서 다시 홈으로 돌아와도 소리 안나게.
         }
         else if(obj == backgroundOffBtn) {
            backgroundOffBtn.setVisible(false);
            backgroundOnBtn.setVisible(true);
            sound.setBackgroundIsOn(true);
            //효과음 on버튼 누르면 on버튼 나오고 off버튼 사라짐
            //backgrondInOn 데이터를 true로 바꿔서 다시 홈으로 돌아와도 소리 나게.
         }
            
         else if(obj == effectOnBtn) {
            effectOnBtn.setVisible(false);
            effectOffBtn.setVisible(true);
            sound.setEffectIsOn(false);
            //효과음 on버튼 누르면 off버튼 나오고 on버튼 사라짐
            //effectIsOn 데이터를 false로 바꿔서 다시 홈으로 돌아와도 소리 안나게.
         }

         else if(obj == effectOffBtn) {
            effectOffBtn.setVisible(false);
            effectOnBtn.setVisible(true);
            sound.setEffectIsOn(true);

            //효과음 off버튼 누르면 on버튼 나오고 off버튼 사라짐
            //effectIsOn 데이터를 true로 바꿔서 다시 홈으로 돌아와도 소리 나게.
         }

      }
   }
   
   //MouseLitener
   private class BtnMenuListener implements MouseListener{
         public void mouseClicked(MouseEvent event) {}
         public void mousePressed(MouseEvent event) {}
         public void mouseReleased(MouseEvent event) {
            JButton btn = (JButton)event.getSource();
            
            if(btn == backgroundOnBtn) {
               sound.stopBackgroundSound();
               //on버튼 누르면 배경음 멈춤
            }
            else if(btn == backgroundOffBtn) {
               sound.playBackgroundSound();
               //off버튼 누르면 배경음 시작
            }            
            else if(btn == backButton) {
               sub.settingAction(0);
            }
            
         }
         public void mouseEntered(MouseEvent event) {}
         public void mouseExited(MouseEvent event) {}         
      }//BtnMenuListener
   public void paintComponent(Graphics page) {
       super.paintComponent(page);
       page.drawImage(background.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
    }
}//SettingPanel