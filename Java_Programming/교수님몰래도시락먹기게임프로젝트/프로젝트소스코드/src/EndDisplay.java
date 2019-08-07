import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class EndDisplay extends JPanel{ //������ ȭ��
   private ImageIcon background; // ���ȭ��
   private JButton RstartBtn,HomeBtn; // �ٽý����ϴ� ��ư�� Ȩ���� ���ư��� ��ư
   private GameListener gameL; // ���� ������
   private SubMain sub; // ��ü �޾ƿ��� ���� ����
   
   public EndDisplay(SubMain p) {
      sub = p; //�̹� ������ subMain�� �ش� Ŭ���������� ���� ���� �����ͼ� ��������
      setPreferredSize(new Dimension(2000,1000)); // ������ ȭ�� ũ�� ����
      setBackground(Color.white); // ����
      setLayout(null); // ���̾ƿ��� �η�
      
      //GameListener��ü ����
      gameL=new GameListener();
      
      //�ٽý��� ��ư ���� �� ��ư ����
      RstartBtn = new JButton(new ImageIcon("images/btnreplay.png")); // �ٽý��� �̹���
      RstartBtn.setBounds(500,500,260,260); // ��ġ�� ������
      RstartBtn.setBorderPainted(false);// �µθ��� �Ⱥ��̰�
      RstartBtn.setContentAreaFilled(false);
      RstartBtn.setFocusPainted(false);
      RstartBtn.addActionListener(gameL);
      add(RstartBtn);
        
      //Ȩ��ư ���� �� ��ư ����
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
   }//�̱�� ���� ���� ��� �̹����� ���ڷ� �޾ƿͼ� �������ش�.
   
   private class GameListener implements ActionListener {
      public void actionPerformed(ActionEvent event) {
         Object obj=event.getSource();
         if(obj==RstartBtn) { // �����ߴ� ���̵��� �ٽ� �����ϸ�ȴ�
              sub.replay(); // sub���� ���� replay�޼ҵ带 ȣ���ؼ� ȭ���� �ѱ��
          }
         else if(obj==HomeBtn) { // �ʱ�ȭ������ �ٽ� �Ѿ�ߵȴ�
             sub.BackMain(); // sub���μ��� BackMain�޼ҵ带 ȣ���Ͽ��� ȭ���� �ѱ��
          }
        }
     }//GameListener
   
   public void paintComponent(Graphics page) {
        super.paintComponent(page);
        page.drawImage(background.getImage(), 10, 10,this.getWidth(),this.getHeight(),null); // ���ȭ���� �ٴڿ� �⺻���� ����
   }//���ȭ���� �׷��ش�.
}