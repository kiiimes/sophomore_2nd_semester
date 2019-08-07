import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class SetLevel extends JPanel {// 누르는 난이도별 게임의 기본 셋팅을 해주는 클래스이다
   private JButton LButton,MButton,HButton; // 난이도 상중하를 고를 수있게 보여주는 JButton들 
   private ImageIcon levelBackground; //난이도를 고르는 화면에서 보여주는 배경화면
   private GameListener gameL;//클릭한 곳의 정보를 얻기 위한 변수
   private SubMain sub;//submain 클래스를 받기위한 변수
   
   //생성자
   public SetLevel(SubMain p) {
	     sub = p;
         setPreferredSize(new Dimension(2000,1000)); // 게임 화면의 크기를 지정해주고 
         setBackground(Color.white); // 색깔은 흰색으로 잡아주고
         setLayout(null);
         setVisible(false); // 보여주지 않는다
         
         gameL=new GameListener();
         
         LButton=new JButton(new ImageIcon("./Images/level1.png")); // 난이도 하임을 보여주는 이미지를 가진 JButton
         LButton.setBounds(400,400,400,300); // 위치와 사이즈를 지정해주고
         LButton.setBorderPainted(false); // JButton의 외각선을 없애준다
         LButton.setContentAreaFilled(false); // JButton이 내용영역 채우기 안함
         LButton.setFocusPainted(false);// JButton이 선택 되었을때 생기는 테두리 사용안함
         LButton.addActionListener(gameL);
         add(LButton); // 패널에 붙여준다
         
         MButton=new JButton(new ImageIcon("./Images/level2.png"));// 난이도 중임을 보여주는 이미지를 가진 JButton
         MButton.setBounds(800,400,400,300);// 위치와 사이즈를 지정해주고
         MButton.setBorderPainted(false);// JButton의 외각선을 없애준다
         MButton.setContentAreaFilled(false);// JButton이 내용영역 채우기 안함
         MButton.setFocusPainted(false);// JButton이 선택 되었을때 생기는 테두리 사용안함
         MButton.addActionListener(gameL);
         add(MButton); // 패널에 붙인다
         
         HButton=new JButton(new ImageIcon("./Images/level3.png"));// 난이도 상임을 보여주는 이미지를 가진 JButton
         HButton.setBounds(1200,400,400,300);// 위치와 사이즈를 지정해주고
         HButton.setBorderPainted(false);// JButton의 외각선을 없애준다
         HButton.setContentAreaFilled(false);// JButton이 내용영역 채우기 안함
         HButton.setFocusPainted(false);// JButton이 선택 되었을때 생기는 테두리 사용안함
         HButton.addActionListener(gameL);
         add(HButton); //패널에 붙여준다
         
         levelBackground=new ImageIcon("./Images/backpage.PNG");    

   }
  
   
   public void setPanel(boolean n) {
      setVisible(n);
   }//panel을 보여줄지 말지 정하는 함수

      private class GameListener implements ActionListener{
            public void actionPerformed(ActionEvent event) {
               Object obj=event.getSource();
               if(obj==LButton) { // 난이도 하 버튼을 눌렀을때
                  sub.LlevelAction(); //subMain에서 LlevelAction()매소를 호출하여서 하난이도의 게임화면으로 변환시켜준다
               }
               else if(obj==MButton) {// 난이도 중 버튼을 눌렀을때
                 sub.MlevelAction();//subMain에서 MlevelAction()매소를 호출하여서 하난이도의 게임화면으로 변환시켜준다
               }
               else if (obj==HButton) { // 난이도 상 버튼을 눌렀을때
                 sub.HlevelAction();//subMain에서 HlevelAction()매소를 호출하여서 하난이도의 게임화면으로 변환시켜준다
               }
               
            }
         }

      public void paintComponent(Graphics page) {
            super.paintComponent(page);
            page.drawImage(levelBackground.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
         }
}