   import javax.swing.*;
   import java.awt.*;
   import java.awt.event.*;
   
   public class GameMain extends JPanel { //게임 시작화면
      
      private GameListener gameL;
      private JButton startBtn,settingBtn; // 게임 시작버튼과 설정버튼
      private ImageIcon background; // 배경화면받아올 변수
      private SubMain sub;
      
      public GameMain(SubMain p) {
    	  sub = p;//인자 대입
         setPreferredSize(new Dimension(2000,1000)); // 화면 사이즈 지정
         setBackground(Color.white); // 배경색은 흰색으로
         setLayout(null); // 레이아웃은 없이 
         
         gameL=new GameListener();
         
         startBtn=new JButton(new ImageIcon("./Images/play.png")); // 게임시작 버튼의 이미지
         startBtn.setBounds(500,450,400,200); // 위치와 사이즈 지정
         startBtn.setBorderPainted(false); // JButton의 외각선을 없애준다
         startBtn.setContentAreaFilled(false); // JButton이 내용영역 채우기 안함
         startBtn.setFocusPainted(false); // JButton이 선택 되었을때 생기는 테두리 사용안함
         startBtn.addActionListener(gameL);
         add(startBtn);
         
         settingBtn=new JButton(new ImageIcon("./Images/setting.png")); // 설정버튼의 이미지
         settingBtn.setBounds(1000,420,500,200); //위치와 사이즈 지정
         settingBtn.setBorderPainted(false);// JButton의 외각선을 없애준다
         settingBtn.setContentAreaFilled(false);// JButton이 내용영역 채우기 안함
         settingBtn.setFocusPainted(false);// JButton이 선택 되었을때 생기는 테두리 사용안함
         settingBtn.addActionListener(gameL);
         add(settingBtn);
        
         background=new ImageIcon("./Images/main.png");
      }
     
      private class GameListener implements ActionListener{
         public void actionPerformed(ActionEvent event) {
            Object obj=event.getSource();
            if(obj==startBtn) { // 시작 버튼을 눌렀을때 게임 시작하는 화면(startAction())으로 옮겨감
                 sub.startAction();
             }
             else if(obj==settingBtn) {// 설정 버튼을 눌렀을때 게임 설정 화면(settingAction(1))으로 옮겨감
                 sub.settingAction(1); //
             }
         }
      }
      
      public void paintComponent(Graphics page) {
            super.paintComponent(page);
            page.drawImage(background.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
         }//배경화면 그려줌
   }
                                  
                          