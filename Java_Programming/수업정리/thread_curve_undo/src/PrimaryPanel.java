import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PrimaryPanel extends JPanel {

	private JPanel 			menuPanel, menuBtnPanel;
	private JPanel			menuOptPanel, menuMsgPanel;
	private DrawingPanel	drawPanel;
	private JButton[]		btnMenuArray;
	
	private JLabel			lblSize;
	private JTextField		txtSize;
	private JPanel			tempPanel;
	private JCheckBox		chkFill;
	private JButton			btnColor;
	
	private LabelThread 	SlblLoc;
	private LabelThread 	ElblLoc;
	
	private BtnMenuListener btnMenuL;
	private MenuActionListener menuActionL;
	
	public PrimaryPanel() {
		
		setPreferredSize(new Dimension(630,420));
		setBackground(Color.white);
		setLayout(null);
		
		btnMenuL = new BtnMenuListener();
		menuActionL = new MenuActionListener();
		
		menuPanel = new JPanel();
		menuPanel.setBounds(10, 10, 200, 400);
		menuPanel.setBackground(Color.white);
		menuPanel.setLayout(null);
		menuPanel.setBorder(BorderFactory.createTitledBorder("MENU"));
		add(menuPanel);
		
		drawPanel = new DrawingPanel(this); // upcall
		drawPanel.setBounds(220, 10, 400, 400);
		drawPanel.setBorder(BorderFactory.createTitledBorder("DRAWING"));
		add(drawPanel);		
		
		menuBtnPanel = new JPanel();
		menuBtnPanel.setBounds(10,30,180,140);
		menuBtnPanel.setLayout(new GridLayout(3,2));
		menuPanel.add(menuBtnPanel);
		
		btnMenuArray = new JButton[6];
		for (int i=0; i<6; i++) {
			btnMenuArray[i] = new JButton(DrawConstants.MENU[i]);
			btnMenuArray[i].setBackground(DrawConstants.EXIT[0]);
			btnMenuArray[i].setForeground(DrawConstants.EXIT[1]);
			btnMenuArray[i].addMouseListener(btnMenuL);
			btnMenuArray[i].addActionListener(menuActionL);
			menuBtnPanel.add(btnMenuArray[i]);
		} //for	
		
		menuOptPanel = new JPanel();
		menuOptPanel.setBounds(10, 180, 180, 140);
		menuOptPanel.setBorder(BorderFactory.createTitledBorder("OPTION"));
		menuOptPanel.setBackground(Color.white);
		menuOptPanel.setLayout(new GridLayout(3,1));
		menuPanel.add(menuOptPanel);
		
		tempPanel = new JPanel();
		tempPanel.setBackground(Color.white);
		menuOptPanel.add(tempPanel);
		
		lblSize = new JLabel("SIZE : ");
		tempPanel.add(lblSize);		
		txtSize = new JTextField(6);
		tempPanel.add(txtSize);
		
		chkFill = new JCheckBox("FILL");
		chkFill.setBackground(Color.white);
		chkFill.setHorizontalAlignment(SwingConstants.CENTER);
		chkFill.setEnabled(false);
		menuOptPanel.add(chkFill);
		
		btnColor = new JButton("COLOR");
		btnColor.addActionListener(new ColorBtnListener());
		menuOptPanel.add(btnColor);
		
		
		menuMsgPanel = new JPanel();
		menuMsgPanel.setBounds(10, 330, 180, 60);
		menuMsgPanel.setLayout(new GridLayout(2,1));
		menuMsgPanel.setBackground(Color.white);
		menuPanel.add(menuMsgPanel);
		
		SlblLoc = new LabelThread("-");
		ElblLoc = new LabelThread("-");
		SlblLoc.setHorizontalAlignment(SwingConstants.CENTER);
		ElblLoc.setHorizontalAlignment(SwingConstants.CENTER);
		//lblLoc.setVerticalAlignment(SwingConstants.CENTER);
		menuMsgPanel.add(SlblLoc);
		menuMsgPanel.add(ElblLoc);
		
		
	} // PrimaryPanel()
	
	public int getTextSize() {
		return Integer.parseInt(txtSize.getText());
	}
	public boolean getFill() {
		return chkFill.isSelected();
	}
	public void setSLoc(int x, int y) {
		SlblLoc.setText("( "+x+" , "+y+" )");
	}
	public void setELoc(int x, int y) {
		ElblLoc.setText("( "+x+" , "+y+" )");
	}
	public void start_Thread() {
		SlblLoc.start();
		ElblLoc.start();
	}
	public void stop_Thread() {
		SlblLoc.stop();
		ElblLoc.stop();
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
		} // mouseEntered()
		
		public void mouseExited(MouseEvent event){
			JButton btnMenu = (JButton)event.getSource();
			btnMenu.setBackground(DrawConstants.EXIT[0]);
			btnMenu.setForeground(DrawConstants.EXIT[1]);
		} // mouseExited()
	} // MouseListener class
	
	private class MenuActionListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			Object obj = event.getSource();
			
			for (int i=0; i<6; i++) {
				if (obj == btnMenuArray[i]) {
					if(i==2 || i==3)
						chkFill.setEnabled(true);
					drawPanel.setDrawMode(i);
					break;
				} // if
				if(obj == btnMenuArray[5]) {
					drawPanel.UNDO();
					repaint();
				}
			} // for
			
		} // actionPeformed()
	} // BtnMenuListener class
	
	private class ColorBtnListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event) {
			
			Color selectedColor = JColorChooser.showDialog(
									btnColor, 
									"COLOR CHOOSER", 
									drawPanel.getForeColor());
			drawPanel.setForeColor(selectedColor);
			
		} // actionPerformed()
	} // ColorBtnListener class
	
	
} // PrimaryPanel class
