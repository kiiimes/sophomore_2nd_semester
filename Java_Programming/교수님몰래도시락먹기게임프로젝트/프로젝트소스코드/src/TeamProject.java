import javax.swing.*;
import java.awt.*;

public class TeamProject {

   public static void main(String[] args) {
      // TODO Auto-generated method stub

      JFrame frame = new JFrame("TEAM PROJECT");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setResizable(false);//frame 기본 설정
      
      SubMain mainP=new SubMain();// 모든 클래스패널들 모아놓는 클래스를 생성

      frame.getContentPane().add(mainP);
      frame.pack();
      frame.setVisible(true);//frame 기본 설정
   }
      
}