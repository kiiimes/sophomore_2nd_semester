import javax.swing.*;
import java.awt.*;

public class TeamProject {

   public static void main(String[] args) {
      // TODO Auto-generated method stub

      JFrame frame = new JFrame("TEAM PROJECT");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setResizable(false);//frame �⺻ ����
      
      SubMain mainP=new SubMain();// ��� Ŭ�����гε� ��Ƴ��� Ŭ������ ����

      frame.getContentPane().add(mainP);
      frame.pack();
      frame.setVisible(true);//frame �⺻ ����
   }
      
}