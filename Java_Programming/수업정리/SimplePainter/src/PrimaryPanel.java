import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PrimaryPanel extends JPanel {

	private JPanel 			menuPanel, menuBtnPanel;
	private JPanel			menuOptPanel, menuMsgPanel;
	private JLabel[]		btnMenuArray;
	
	private JLabel			switchButtonName1;
	private JLabel			switchButtonName2;
	private JLabel			switchName1;
	private JLabel			switchName2;
	
	private JTextField		txtSize;//textField ���� 
	private JPanel			tempPanel;
	private JCheckBox		chkFill;
	private JButton			switchBtn1;
	private JButton			switchBtn2;
	
	private LabelThread lblMark;
	private LabelThread lblMark1;
	private LabelThread lblMark3;
	
	private int flag=0;
	
	public PrimaryPanel() {
		
		//�����̸Ӹ� �г��� ũ��� ������ �����ְ� ���̾ƿ��� �������� �ʴ´�.
		setPreferredSize(new Dimension(630,420));
		setBackground(Color.white);
		setLayout(null);
		
		//메뉴패널
		menuPanel = new JPanel();
		menuPanel.setBounds(10, 10, 600, 400);//�г� ũ�� ����
		menuPanel.setBackground(Color.white);//�г� ���� ����
		menuPanel.setLayout(null);//���̾ƿ� ���� ���� 
		menuPanel.setBorder(BorderFactory.createTitledBorder("MENU"));//�г��� �׵θ� ����
		add(menuPanel);//�����̸Ӹ� �гο� add
		
		menuBtnPanel = new JPanel();
		menuBtnPanel.setBounds(25,30,550,140);//�г� ũ�� ����
		menuBtnPanel.setLayout(new GridLayout(2,3));//��ġ�� 3�� 2���� ��ġ�� ����
		menuBtnPanel.setBorder(BorderFactory.createTitledBorder("VALUE"));//�׵θ� ����
		menuBtnPanel.setBackground(Color.white);//���� ����
		menuPanel.add(menuBtnPanel);//�޴��гο� add
		
		btnMenuArray = new JLabel[6];//�޴� ��ư �迭 ����
		
		for (int i=0; i<3; i++) {
			btnMenuArray[i] = new JLabel(DrawConstants.MENU[i]);//��ư 6�� ����
			btnMenuArray[i].setBackground(DrawConstants.EXIT[0]);//��ư ���� ����
			btnMenuArray[i].setForeground(DrawConstants.EXIT[1]);//��ư ���� �۾��� ����
			btnMenuArray[i].setFont(new Font("Verdana",Font.BOLD,18));
			btnMenuArray[i].setHorizontalAlignment(SwingConstants.CENTER);
			menuBtnPanel.add(btnMenuArray[i]);
		} //for	
		
		lblMark=new LabelThread(1);
		lblMark.setBounds(10,80,180,140);
		lblMark.setFont(new Font("Verdana",Font.BOLD,15));
		lblMark.setHorizontalAlignment(SwingConstants.CENTER);
		lblMark.start();
		//lblMark.setVisible(false);
		menuBtnPanel.add(lblMark);
		
		lblMark1=new LabelThread(2);
		lblMark1.setBounds(10,80,180,140);
		lblMark1.setFont(new Font("Verdana",Font.BOLD,15));
		lblMark1.setHorizontalAlignment(SwingConstants.CENTER);
		lblMark1.start();
		//lblMark.setVisible(false);
		menuBtnPanel.add(lblMark1);
		
		lblMark3=new LabelThread(3);
		lblMark3.setBounds(10,80,180,140);
		lblMark3.setFont(new Font("Verdana",Font.BOLD,15));
		lblMark3.setHorizontalAlignment(SwingConstants.CENTER);
		lblMark3.start();
		menuBtnPanel.add(lblMark3);
		
		
		
		
		//�����ϴ� �г� ����
		menuOptPanel = new JPanel();
		menuOptPanel.setBounds(30, 180, 550, 140);//�ɼ� �г� ũ�� ����
		menuOptPanel.setBorder(BorderFactory.createTitledBorder("OPTION"));//�׵θ� ����
		menuOptPanel.setBackground(Color.white);//���� ����
		menuOptPanel.setLayout(new GridLayout(3,1));//3��1�� ����
		menuPanel.add(menuOptPanel);
		
		tempPanel = new JPanel();//size �󺧰� textfield ��� �г� ����
		tempPanel.setBackground(Color.white);
		menuOptPanel.add(tempPanel);
		menuOptPanel.setLayout(null);
		
		switchButtonName1 = new JLabel("Start");//Size : ���� ����
		
		switchName1 = new JLabel("SWITCH1");
		switchName1.setBounds(160,10,120,60);
		switchName1.setFont(new Font("Verdana",Font.BOLD,15));
		
		switchName2 = new JLabel("SWITCH2");
		switchName2.setBounds(320,10,120,60);
		switchName2.setFont(new Font("Verdana",Font.BOLD,15));
		
		menuOptPanel.add(switchName1);
		menuOptPanel.add(switchName2);
		
		switchButtonName1 = new JLabel("Start");//Size : ���� ����
		switchButtonName1.setBounds(0,0,120,60);
		switchButtonName1.setFont(new Font("Verdana",Font.BOLD,14));
		switchButtonName1.setHorizontalAlignment(SwingConstants.CENTER);
		
		
		switchBtn1 = new JButton();//�� ������ �� �ִ� ��ư ����
		switchBtn1.setBounds(140, 60, 120, 60);
		switchBtn1.setLayout(null);
		switchBtn1.addActionListener(new ColorBtnListener());//��ư�� ������ ����Ʈ �� �������� actionListener�� add����

		menuOptPanel.add(switchBtn1);
		switchBtn1.add(switchButtonName1);
		
		switchButtonName2 = new JLabel("Start");//Size : ���� ����
		switchButtonName2.setBounds(0,0,120,60);
		switchButtonName2.setFont(new Font("Verdana",Font.BOLD,14));
		switchButtonName2.setHorizontalAlignment(SwingConstants.CENTER);
		
		switchBtn2 = new JButton();//�� ������ �� �ִ� ��ư ����
		switchBtn2.setBounds(300, 60, 120, 60);
		switchBtn2.setLayout(null);
		switchBtn2.addActionListener(new ColorBtnListener1());//��ư�� ������ ����Ʈ �� �������� actionListener�� add����

		menuOptPanel.add(switchBtn2);
		switchBtn2.add(switchButtonName2);
		
		
	} // PrimaryPanel()
	
	public int getFlag() {
		return flag;
	}
	
	
	private class ColorBtnListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			if(flag==0) {
				flag=1;
				switchButtonName1.setText("Stop");
			}
			else {
				flag=0;
				switchButtonName1.setText("Start");
			}
		} // actionPerformed()
	} // ColorBtnListener class
	
	private class ColorBtnListener1 implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			if(flag==0) {
				flag=1;
				switchButtonName2.setText("Stop");
			}
			else {
				flag=0;
				switchButtonName2.setText("Start");
			}
		} // actionPerformed()
	} // C
	
} // PrimaryPanel class
