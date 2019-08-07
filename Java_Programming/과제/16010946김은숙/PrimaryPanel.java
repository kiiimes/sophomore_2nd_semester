import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PrimaryPanel extends JPanel {

	private JPanel 			menuPanel, menuBtnPanel;
	private JPanel			menuOptPanel, menuMsgPanel;
	private DrawingPanel	drawPanel;
	private JButton[]		btnMenuArray;
	
	private JLabel			lblSize;
	private JTextField		txtSize;//textField ���� 
	private JPanel			tempPanel;
	private JCheckBox		chkFill;
	private JButton			btnColor;
	private JButton lButton,rButton,uButton,dButton;
	private JPanel aTempPanel;
	private JLabel ut,lt,rt,dt;
	private int sav;
	
	private BtnMenuListener btnMenuL;
	private MenuActionListener menuActionL;
	private ArrowActionListener arrowActionL;
	
	public PrimaryPanel() {
		
		//�����̸Ӹ� �г��� ũ��� ������ �����ְ� ���̾ƿ��� �������� �ʴ´�.
		setPreferredSize(new Dimension(630,420));
		setBackground(Color.white);
		setLayout(null);
		
		
		btnMenuL = new BtnMenuListener();//hover�� ���� menuListener ����
		menuActionL = new MenuActionListener();
		arrowActionL=new ArrowActionListener();
		
		//�޴� ��ư ���δ� �޴��κ� ����
		menuPanel = new JPanel();
		menuPanel.setBounds(10, 10, 200, 400);//�г� ũ�� ����
		menuPanel.setBackground(Color.white);//�г� ���� ����
		menuPanel.setLayout(null);//���̾ƿ� ���� ���� 
		menuPanel.setBorder(BorderFactory.createTitledBorder("MENU"));//�г��� �׵θ� ����
		add(menuPanel);//�����̸Ӹ� �гο� add
		
		//dwing �Ǵ� �г� ����
		drawPanel = new DrawingPanel(this); // upcall
		drawPanel.setBounds(220, 10, 400, 400);
		drawPanel.setBorder(BorderFactory.createTitledBorder("DRAWING"));
		add(drawPanel);		
		
		//�޴� ��ư ���� �г� ����
		menuBtnPanel = new JPanel();
		menuBtnPanel.setBounds(10,30,180,140);//�г� ũ�� ����
		menuBtnPanel.setLayout(new GridLayout(3,2));//��ġ�� 3�� 2���� ��ġ�� ����
		menuPanel.add(menuBtnPanel);//�޴��гο� add
		
		btnMenuArray = new JButton[6];//�޴� ��ư �迭 ����
		for (int i=0; i<6; i++) {
			btnMenuArray[i] = new JButton(DrawConstants.MENU[i]);//��ư 6�� ����
			btnMenuArray[i].setBackground(DrawConstants.EXIT[0]);//��ư ���� ����
			btnMenuArray[i].setForeground(DrawConstants.EXIT[1]);//��ư ���� �۾��� ����
			btnMenuArray[i].addMouseListener(btnMenuL);//��ư������ mouseListener ����
			btnMenuArray[i].addActionListener(menuActionL);//
			menuBtnPanel.add(btnMenuArray[i]);
		} //for	
		btnMenuArray[5].setEnabled(false);
		
		//�����ϴ� �г� ����
		menuOptPanel = new JPanel();
		menuOptPanel.setBounds(10, 180, 180, 180);//�ɼ� �г� ũ�� ����
		menuOptPanel.setBorder(BorderFactory.createTitledBorder("OPTION"));//�׵θ� ����
		menuOptPanel.setBackground(Color.white);//���� ����
		menuOptPanel.setLayout(new GridLayout(4,1));//3��1�� ����
		menuPanel.add(menuOptPanel);
		
		tempPanel = new JPanel();//size �󺧰� textfield ��� �г� ����
		tempPanel.setBackground(Color.white);
		menuOptPanel.add(tempPanel);
		
		lblSize = new JLabel("SIZE : ");//Size : ���� ����
		tempPanel.add(lblSize);	
		txtSize = new JTextField(6);//text���� ����
		tempPanel.add(txtSize);
		
		chkFill = new JCheckBox("FILL");//fill check �ϴ� üũ�ڽ� ����
		chkFill.setBackground(Color.white);
		chkFill.setHorizontalAlignment(SwingConstants.CENTER);//����� ����
		menuOptPanel.add(chkFill);
		
		btnColor = new JButton("COLOR");//�� ������ �� �ִ� ��ư ����
		btnColor.addActionListener(new ColorBtnListener());//��ư�� ������ ����Ʈ �� �������� actionListener�� add����
		menuOptPanel.add(btnColor);
		
		aTempPanel = new JPanel();//size �󺧰� textfield ��� �г� ����
		aTempPanel.setBackground(Color.white);
		aTempPanel.setLayout(new GridLayout(4,1));
		menuOptPanel.add(aTempPanel);
		
		lButton=new JButton("Left");
		aTempPanel.add(lButton);
		rButton=new JButton("Right");
		aTempPanel.add(rButton);	
		uButton=new JButton("Up");
		aTempPanel.add(uButton);	
		dButton=new JButton("Down");
		aTempPanel.add(dButton);

		lButton.addActionListener(arrowActionL);
		rButton.addActionListener(arrowActionL);
		uButton.addActionListener(arrowActionL);
		dButton.addActionListener(arrowActionL);
		
		menuMsgPanel = new JPanel();
		menuMsgPanel.setBounds(10, 330, 180, 60);//option Panel ������ ũ�� ��������
		menuPanel.add(menuMsgPanel);
		
	} // PrimaryPanel()
	
	public int getTextSize() {
		return Integer.parseInt(txtSize.getText());
	}//textũ�� ��ȯ���ִ� �Լ�
	public boolean getFill() {
		return chkFill.isSelected();
	}//fill checkBox�� ���� �Ǿ��ִ����� return ���ִ� �Լ� 
	public int getButtonOption() {
		return sav;
	}
	public void setEnableButton(boolean n) {
		btnMenuArray[5].setEnabled(n);
	}
	
	
	private class BtnMenuListener implements MouseListener
	{
		public void mouseClicked(MouseEvent event){}
		public void mousePressed(MouseEvent event){}
		public void mouseReleased(MouseEvent event){}
		
		public void mouseEntered(MouseEvent event){
			JButton btnMenu = (JButton)event.getSource(); 
			btnMenu.setBackground(DrawConstants.ENTER[0]);
			btnMenu.setForeground(DrawConstants.ENTER[1]);
		} // mouseEntered() ���콺 ��ư���� ������ ������ �۾��� ����
		
		public void mouseExited(MouseEvent event){
			JButton btnMenu = (JButton)event.getSource();
			btnMenu.setBackground(DrawConstants.EXIT[0]);
			btnMenu.setForeground(DrawConstants.EXIT[1]);
		} // mouseExited() ���콺 ��ư���� �������� ������ �۾��� ����
	} // MouseListener class
	
	private class MenuActionListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			
			Object obj = event.getSource();
			
			for (int i=0; i<6; i++) {
				if (obj == btnMenuArray[i]) {
					if(i==4) {chkFill.setVisible(false);} 
					if(i==5) {
						drawPanel.undo();
						if(drawPanel.getDataList().size()==0) btnMenuArray[5].setEnabled(false); 
					}
					
					drawPanel.setDrawMode(i);//�ش��ϴ� ����� �׸��� drawingPanel�� �׸�
					break;
				} // if
			} // for
			
		} // actionPeformed()
	} // BtnMenuListener class
	
	private class ColorBtnListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			
			Color selectedColor = JColorChooser.showDialog(
									btnColor, 
									"COLOR CHOOSER", 
									drawPanel.getForeColor()); //�������� �������ִ� �Լ� 
			drawPanel.setForeColor(selectedColor);
			
		} // actionPerformed()
	} // ColorBtnListener class
	
	private class ArrowActionListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			
			Object obj = event.getSource();
			
			if(obj==lButton) {
				sav=0;
			}
			else if(obj==rButton) {
				sav=1;
			}
			else if(obj==uButton) {
				sav=2;	
			}
			else if(obj==dButton) {
				sav=3;
			}
								
		} // actionPeformed()
	}
	
} // PrimaryPanel class
