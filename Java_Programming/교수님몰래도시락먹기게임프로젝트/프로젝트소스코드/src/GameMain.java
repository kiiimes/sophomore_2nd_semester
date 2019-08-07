   import javax.swing.*;
   import java.awt.*;
   import java.awt.event.*;
   
   public class GameMain extends JPanel { //���� ����ȭ��
      
      private GameListener gameL;
      private JButton startBtn,settingBtn; // ���� ���۹�ư�� ������ư
      private ImageIcon background; // ���ȭ��޾ƿ� ����
      private SubMain sub;
      
      public GameMain(SubMain p) {
    	  sub = p;//���� ����
         setPreferredSize(new Dimension(2000,1000)); // ȭ�� ������ ����
         setBackground(Color.white); // ������ �������
         setLayout(null); // ���̾ƿ��� ���� 
         
         gameL=new GameListener();
         
         startBtn=new JButton(new ImageIcon("./Images/play.png")); // ���ӽ��� ��ư�� �̹���
         startBtn.setBounds(500,450,400,200); // ��ġ�� ������ ����
         startBtn.setBorderPainted(false); // JButton�� �ܰ����� �����ش�
         startBtn.setContentAreaFilled(false); // JButton�� ���뿵�� ä��� ����
         startBtn.setFocusPainted(false); // JButton�� ���� �Ǿ����� ����� �׵θ� ������
         startBtn.addActionListener(gameL);
         add(startBtn);
         
         settingBtn=new JButton(new ImageIcon("./Images/setting.png")); // ������ư�� �̹���
         settingBtn.setBounds(1000,420,500,200); //��ġ�� ������ ����
         settingBtn.setBorderPainted(false);// JButton�� �ܰ����� �����ش�
         settingBtn.setContentAreaFilled(false);// JButton�� ���뿵�� ä��� ����
         settingBtn.setFocusPainted(false);// JButton�� ���� �Ǿ����� ����� �׵θ� ������
         settingBtn.addActionListener(gameL);
         add(settingBtn);
        
         background=new ImageIcon("./Images/main.png");
      }
     
      private class GameListener implements ActionListener{
         public void actionPerformed(ActionEvent event) {
            Object obj=event.getSource();
            if(obj==startBtn) { // ���� ��ư�� �������� ���� �����ϴ� ȭ��(startAction())���� �Űܰ�
                 sub.startAction();
             }
             else if(obj==settingBtn) {// ���� ��ư�� �������� ���� ���� ȭ��(settingAction(1))���� �Űܰ�
                 sub.settingAction(1); //
             }
         }
      }
      
      public void paintComponent(Graphics page) {
            super.paintComponent(page);
            page.drawImage(background.getImage(), 10, 10,this.getWidth(),this.getHeight(),null);
         }//���ȭ�� �׷���
   }
                                  
                          