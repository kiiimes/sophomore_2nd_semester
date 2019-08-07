import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class EndDisplay extends JPanel{ //끝나는 화면
   private ImageIcon background; // 배경화면
   private JButton RstartBtn,HomeBtn; // 다시시작하는 버튼과 홈으로 돌아가는 버튼
   private GameListener gameL; // 게임 리스너
   private SubMain sub; // 객체 받아오기 위한 변수
   
   public EndDisplay(SubMain p) {
      sub = p; //이미 생성된 subMain을 해당 클래스에서도 쓰기 위해 가져와서 대입해줌
      setPreferredSize(new Dimension(2000,1000)); // 끝나는 화면 크기 설정
      setBackground(Color.white); // 배경색
      setLayout(null); // 레이아웃은 널로
      
      //GameListener객체 생성
      gameL=new GameListener();
      
      //다시시작 버튼 생성 및 버튼 설정
      RstartBtn = new JButton(new ImageIcon("images/btnreplay.png")); // 다시시작 이미지
      RstartBtn.setBounds(500,500,260,260); // 위치와 사이즈
      RstartBtn.setBorderPainted(false);// 태두리는 안보이게
      RstartBtn.setContentAreaFilled(false);
      RstartBtn.setFocusPainted(false);
      RstartBtn.addActionListener(gameL);
      add(RstartBtn);
        
      //홈버튼 생성 및 버튼 설정
      HomeBtn=new JButton(new ImageIcon("./Images/btnhome.png"));
      HomeBtn.setBounds(1250,500,280,280);
      HomeBtn.setBorderPainted(false);
      HomeBtn.setContentAreaFilled(false);
      HomeBtn.setFocusPainted(false);
      HomeBtn.addActionListener(gameL);
      add(HomeBtn);
   }
   
   public void setBackImg(String str) {
      background = new ImageIcon(str);
   }//이기고 짐에 따라 배경 이미지를 인자로 받아와서 지정해준다.
   
   private class GameListener implements ActionListener {
      public void actionPerformed(ActionEvent event) {
         Object obj=event.getSource();
         if(obj==RstartBtn) { // 실행했던 난이도를 다시 실행하면된다
              sub.replay(); // sub메인 속의 replay메소드를 호출해서 화면을 넘긴다
          }
         else if(obj==HomeBtn) { // 초기화면으로 다시 넘어가야된다
             sub.BackMain(); // sub메인속의 BackMain메소드를 호출하여서 화면을 넘긴다
          }
        }
     }//GameListener
   
   public void paintComponent(Graphics page) {
        super.paintComponent(page);
        page.drawImage(background.getImage(), 10, 10,this.getWidth(),this.getHeight(),null); // 배경화면을 바닥에 기본으로 셋팅
   }//배경화면을 그려준다.
}