import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class SettingPanel extends JPanel {
   private SubMain sub;
   private JButton backButton,backgroundOnBtn,effectOnBtn, backgroundOffBtn,effectOffBtn;
   //������� �������ε��ư��¹�ư,���ȭ�� �� ��ư ,ȿ���� �� ��ư, ���ȭ�� ������ư, ȿ���� ������ư
   private JLabel settingNamelbl,backgroundNamelbl,effectNamelbl;
   //������� ���ȭ���,"ȯ�漳��"��, "���������"�� , "ȿ��������"��
   private JLabel programedBy;
   private GameListener gameL;
   //�¿��� ��ư ��ȯ�� ���� ������
   private BtnMenuListener btnL;
   //�Ҹ� ��� ������ ���� ������
   private SettingSound sound;
   
   private ImageIcon background;//SettingPanel ����̹���
   
   public SettingPanel(SubMain p,SettingSound gameSound) {
      sub = p;//SubMain���� �޾ƿ�  SubMain�� ��ü p�� sub�� ���� 
      sound = gameSound;//SubMain���� �޾ƿ� SettingSound�� ��ü gameSound�� sound�� ���� 
      
      gameL = new GameListener();//�׼Ǹ����� ����,����
      btnL = new BtnMenuListener();//���콺������ ����,����
      
      setLayout(null);//���̾ƿ� ���ֱ�
      setPreferredSize(new Dimension(2000,1000));
      
      //"ȯ�漳��" �� ����
      settingNamelbl = new JLabel("ȯ�漳��");
      settingNamelbl.setFont(new Font("210 ��ǻŸ��Ź L",Font.BOLD,60));
      settingNamelbl.setLayout(null);
      settingNamelbl.setBounds(800,70,450,200);
      add(settingNamelbl);
      
    //"���������" �� ����
      backgroundNamelbl = new JLabel("����� ����");
      backgroundNamelbl.setFont(new Font("210 ��ǻŸ��Ź L",Font.BOLD,50));
      backgroundNamelbl.setLayout(null);
      backgroundNamelbl.setBounds(600,370,450,200);
      add(backgroundNamelbl);

      //����� ������ on��ư
      backgroundOnBtn = new JButton(new ImageIcon("images/onBtn.png"));
      backgroundOnBtn.setLayout(null);
      backgroundOnBtn.setBounds(1000,440,200,60);
      backgroundOnBtn.addActionListener(gameL);//�׼Ǹ����� �߰�
      backgroundOnBtn.addMouseListener(btnL);//���콺������ �߰�
      backgroundOnBtn.setContentAreaFilled(false);
      backgroundOnBtn.setBorderPainted(false);
      add(backgroundOnBtn);

      //����� ������ off��ư
      backgroundOffBtn = new JButton(new ImageIcon("images/offBtn.png"));
      backgroundOffBtn.setLayout(null);
      backgroundOffBtn.setBounds(1000,440,200,60);
      backgroundOffBtn.addActionListener(gameL);//�׼Ǹ����� �߰�
      backgroundOffBtn.addMouseListener(btnL);//���콺������ �߰�
      backgroundOffBtn.setContentAreaFilled(false);
      backgroundOffBtn.setBorderPainted(false);
      add(backgroundOffBtn);
      backgroundOffBtn.setVisible(false);

      //"ȿ��������" �� ����
      effectNamelbl = new JLabel("ȿ���� ����");
      effectNamelbl.setFont(new Font("210 ��ǻŸ��Ź L",Font.BOLD,50));
      effectNamelbl.setLayout(null);
      effectNamelbl.setBounds(600,540,400,200);
      add(effectNamelbl);

      //ȿ���� ������ on��ư
      effectOnBtn = new JButton(new ImageIcon("images/onBtn.png"));
      effectOnBtn.setLayout(null);
      effectOnBtn.setSize(110,60);
      effectOnBtn.setBounds(1000,610,200,60);
      effectOnBtn.addActionListener(gameL);//�׼Ǹ����� �߰�
      effectOnBtn.setContentAreaFilled(false);
      effectOnBtn.setBorderPainted(false);
      add(effectOnBtn);

      //ȿ���� ������ off��ư
      effectOffBtn = new JButton(new ImageIcon("images/offBtn.png"));
      effectOffBtn.setLayout(null);
      effectOffBtn.setSize(110,60);
      effectOffBtn.setBounds(1000,610,200,60);
      effectOffBtn.addActionListener(gameL);//�׼Ǹ����� �߰�
      effectOffBtn.setContentAreaFilled(false);
      effectOffBtn.setBorderPainted(false);
      add(effectOffBtn);
      effectOffBtn.setVisible(false);

      //Ȩ���� ���ư��� ��ư
      backButton = new JButton(new ImageIcon("images/btnhome.png"));
      backButton.setLayout(null);
      backButton.setBounds(1500,750,180,180);
      backButton.addMouseListener(btnL);//���콺������ �߰�
      backButton.setContentAreaFilled(false);
      backButton.setBorderPainted(false);
      add(backButton);

      //programedBy ��
      programedBy = new JLabel("Programed By.. ������   ������   �̼���   ����ȣ");
      programedBy.setFont(new Font("210 ��ǻŸ��Ź L",Font.BOLD,18));
      programedBy.setLayout(null);
      programedBy.setBounds(700,950,500,50);
      add(programedBy);
      
      //����̹���
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
            //����� on��ư ������ off��ư ������ on��ư �����
            //backgroundIsOn �����͸� false�� �ٲ㼭 �ٽ� Ȩ���� ���ƿ͵� �Ҹ� �ȳ���.
         }
         else if(obj == backgroundOffBtn) {
            backgroundOffBtn.setVisible(false);
            backgroundOnBtn.setVisible(true);
            sound.setBackgroundIsOn(true);
            //ȿ���� on��ư ������ on��ư ������ off��ư �����
            //backgrondInOn �����͸� true�� �ٲ㼭 �ٽ� Ȩ���� ���ƿ͵� �Ҹ� ����.
         }
            
         else if(obj == effectOnBtn) {
            effectOnBtn.setVisible(false);
            effectOffBtn.setVisible(true);
            sound.setEffectIsOn(false);
            //ȿ���� on��ư ������ off��ư ������ on��ư �����
            //effectIsOn �����͸� false�� �ٲ㼭 �ٽ� Ȩ���� ���ƿ͵� �Ҹ� �ȳ���.
         }

         else if(obj == effectOffBtn) {
            effectOffBtn.setVisible(false);
            effectOnBtn.setVisible(true);
            sound.setEffectIsOn(true);

            //ȿ���� off��ư ������ on��ư ������ off��ư �����
            //effectIsOn �����͸� true�� �ٲ㼭 �ٽ� Ȩ���� ���ƿ͵� �Ҹ� ����.
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
               //on��ư ������ ����� ����
            }
            else if(btn == backgroundOffBtn) {
               sound.playBackgroundSound();
               //off��ư ������ ����� ����
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