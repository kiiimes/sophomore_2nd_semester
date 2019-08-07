import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class SetLevel extends JPanel {// ������ ���̵��� ������ �⺻ ������ ���ִ� Ŭ�����̴�
   private JButton LButton,MButton,HButton; // ���̵� �����ϸ� �� ���ְ� �����ִ� JButton�� 
   private ImageIcon levelBackground; //���̵��� ���� ȭ�鿡�� �����ִ� ���ȭ��
   private GameListener gameL;//Ŭ���� ���� ������ ��� ���� ����
   private SubMain sub;//submain Ŭ������ �ޱ����� ����
   
   //������
   public SetLevel(SubMain p) {
	     sub = p;
         setPreferredSize(new Dimension(2000,1000)); // ���� ȭ���� ũ�⸦ �������ְ� 
         setBackground(Color.white); // ������ ������� ����ְ�
         setLayout(null);
         setVisible(false); // �������� �ʴ´�
         
         gameL=new GameListener();
         
         LButton=new JButton(new ImageIcon("./Images/level1.png")); // ���̵� ������ �����ִ� �̹����� ���� JButton
         LButton.setBounds(400,400,400,300); // ��ġ�� ����� �������ְ�
         LButton.setBorderPainted(false); // JButton�� �ܰ����� �����ش�
         LButton.setContentAreaFilled(false); // JButton�� ���뿵�� ä��� ����
         LButton.setFocusPainted(false);// JButton�� ���� �Ǿ����� ����� �׵θ� ������
         LButton.addActionListener(gameL);
         add(LButton); // �гο� �ٿ��ش�
         
         MButton=new JButton(new ImageIcon("./Images/level2.png"));// ���̵� ������ �����ִ� �̹����� ���� JButton
         MButton.setBounds(800,400,400,300);// ��ġ�� ����� �������ְ�
         MButton.setBorderPainted(false);// JButton�� �ܰ����� �����ش�
         MButton.setContentAreaFilled(false);// JButton�� ���뿵�� ä��� ����
         MButton.setFocusPainted(false);// JButton�� ���� �Ǿ����� ����� �׵θ� ������
         MButton.addActionListener(gameL);
         add(MButton); // �гο� ���δ�
         
         HButton=new JButton(new ImageIcon("./Images/level3.png"));// ���̵� ������ �����ִ� �̹����� ���� JButton
         HButton.setBounds(1200,400,400,300);// ��ġ�� ����� �������ְ�
         HButton.setBorderPainted(false);// JButton�� �ܰ����� �����ش�
         HButton.setContentAreaFilled(false);// JButton�� ���뿵�� ä��� ����
         HButton.setFocusPainted(false);// JButton�� ���� �Ǿ����� ����� �׵θ� ������
         HButton.addActionListener(gameL);
         add(HButton); //�гο� �ٿ��ش�
         
         levelBackground=new ImageIcon("./Images/backpage.PNG");    

   }
  
   
   public void setPanel(boolean n) {
      setVisible(n);
   }//panel�� �������� ���� ���ϴ� �Լ�

      private class GameListener implements ActionListener{
            public void actionPerformed(ActionEvent event) {
               Object obj=event.getSource();
               if(obj==LButton) { // ���̵� �� ��ư�� ��������
                  sub.LlevelAction(); //subMain���� LlevelAction()�żҸ� ȣ���Ͽ��� �ϳ��̵��� ����ȭ������ ��ȯ�����ش�
               }
               else if(obj==MButton) {// ���̵� �� ��ư�� ��������
                 sub.MlevelAction();//subMain���� MlevelAction()�żҸ� ȣ���Ͽ��� �ϳ��̵��� ����ȭ������ ��ȯ�����ش�
               }
               else if (obj==HButton) { // ���̵� �� ��ư�� ��������
                 sub.HlevelAction();//subMain���� HlevelAction()�żҸ� ȣ���Ͽ��� �ϳ��̵��� ����ȭ������ ��ȯ�����ش�
               }
               
            }
         }

      public void paintComponent(Graphics page) {
            super.paintComponent(page);
            page.drawImage(levelBackground.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
         }
}