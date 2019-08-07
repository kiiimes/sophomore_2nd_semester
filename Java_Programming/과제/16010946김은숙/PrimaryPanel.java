import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PrimaryPanel extends JPanel {

	private JPanel 			menuPanel, menuBtnPanel;
	private JPanel			menuOptPanel, menuMsgPanel;
	private DrawingPanel	drawPanel;
	private JButton[]		btnMenuArray;
	
	private JLabel			lblSize;
	private JTextField		txtSize;//textField 변수 
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
		
		//프라이머리 패널의 크기와 배경색을 정해주고 레이아웃을 지정하지 않는다.
		setPreferredSize(new Dimension(630,420));
		setBackground(Color.white);
		setLayout(null);
		
		
		btnMenuL = new BtnMenuListener();//hover를 위한 menuListener 생성
		menuActionL = new MenuActionListener();
		arrowActionL=new ArrowActionListener();
		
		//메뉴 버튼 감싸는 메뉴부분 생성
		menuPanel = new JPanel();
		menuPanel.setBounds(10, 10, 200, 400);//패널 크기 지정
		menuPanel.setBackground(Color.white);//패널 배경색 지정
		menuPanel.setLayout(null);//레이아웃 지정 해제 
		menuPanel.setBorder(BorderFactory.createTitledBorder("MENU"));//패널의 테두리 생성
		add(menuPanel);//프라이머리 패널에 add
		
		//dwing 되는 패널 생성
		drawPanel = new DrawingPanel(this); // upcall
		drawPanel.setBounds(220, 10, 400, 400);
		drawPanel.setBorder(BorderFactory.createTitledBorder("DRAWING"));
		add(drawPanel);		
		
		//메뉴 버튼 담을 패널 생성
		menuBtnPanel = new JPanel();
		menuBtnPanel.setBounds(10,30,180,140);//패널 크기 지정
		menuBtnPanel.setLayout(new GridLayout(3,2));//위치를 3행 2열로 위치를 조정
		menuPanel.add(menuBtnPanel);//메뉴패널에 add
		
		btnMenuArray = new JButton[6];//메뉴 버튼 배열 생성
		for (int i=0; i<6; i++) {
			btnMenuArray[i] = new JButton(DrawConstants.MENU[i]);//버튼 6개 생성
			btnMenuArray[i].setBackground(DrawConstants.EXIT[0]);//버튼 배경색 설정
			btnMenuArray[i].setForeground(DrawConstants.EXIT[1]);//버튼 안의 글씨색 설정
			btnMenuArray[i].addMouseListener(btnMenuL);//버튼누르면 mouseListener 실행
			btnMenuArray[i].addActionListener(menuActionL);//
			menuBtnPanel.add(btnMenuArray[i]);
		} //for	
		btnMenuArray[5].setEnabled(false);
		
		//설정하는 패널 생성
		menuOptPanel = new JPanel();
		menuOptPanel.setBounds(10, 180, 180, 180);//옵션 패널 크기 설정
		menuOptPanel.setBorder(BorderFactory.createTitledBorder("OPTION"));//테두리 생성
		menuOptPanel.setBackground(Color.white);//배경색 생성
		menuOptPanel.setLayout(new GridLayout(4,1));//3행1열 정렬
		menuPanel.add(menuOptPanel);
		
		tempPanel = new JPanel();//size 라벨과 textfield 담는 패널 생성
		tempPanel.setBackground(Color.white);
		menuOptPanel.add(tempPanel);
		
		lblSize = new JLabel("SIZE : ");//Size : 러밸 샹송
		tempPanel.add(lblSize);	
		txtSize = new JTextField(6);//text상자 생성
		tempPanel.add(txtSize);
		
		chkFill = new JCheckBox("FILL");//fill check 하는 체크박스 생성
		chkFill.setBackground(Color.white);
		chkFill.setHorizontalAlignment(SwingConstants.CENTER);//가운데로 정렬
		menuOptPanel.add(chkFill);
		
		btnColor = new JButton("COLOR");//색 설정할 수 있는 버튼 생성
		btnColor.addActionListener(new ColorBtnListener());//버튼을 누르면 페인트 통 나오도록 actionListener를 add해줌
		menuOptPanel.add(btnColor);
		
		aTempPanel = new JPanel();//size 라벨과 textfield 담는 패널 생성
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
		menuMsgPanel.setBounds(10, 330, 180, 60);//option Panel 생성후 크기 지정해줌
		menuPanel.add(menuMsgPanel);
		
	} // PrimaryPanel()
	
	public int getTextSize() {
		return Integer.parseInt(txtSize.getText());
	}//text크기 반환해주는 함수
	public boolean getFill() {
		return chkFill.isSelected();
	}//fill checkBox가 선택 되어있는지를 return 해주는 함수 
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
		} // mouseEntered() 마우스 버튼위에 있을때 배경색과 글씨색 설정
		
		public void mouseExited(MouseEvent event){
			JButton btnMenu = (JButton)event.getSource();
			btnMenu.setBackground(DrawConstants.EXIT[0]);
			btnMenu.setForeground(DrawConstants.EXIT[1]);
		} // mouseExited() 마우스 버튼에서 나왔을때 배경색과 글씨색 설정
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
					
					drawPanel.setDrawMode(i);//해당하는 모드의 그림을 drawingPanel에 그림
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
									drawPanel.getForeColor()); //선색깔을 설정해주는 함수 
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
