import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PrimaryPanel extends JPanel {

	private JPanel menuPanel, menuBtnPanel;
	private DrawingPanel drawPanel;
	private JButton[] btnMenuArray;
	private BtnMenuListener btnMenuL;
	
	public PrimaryPanel() {
		
		setPreferredSize(new Dimension(630,420));
		setBackground(Color.white);
		setLayout(null);
		
		btnMenuL = new BtnMenuListener();
		
		menuPanel = new JPanel();
		menuPanel.setBounds(10, 10, 200, 400);
		menuPanel.setBackground(Color.white);
		menuPanel.setLayout(null);
		menuPanel.setBorder(BorderFactory.createTitledBorder("MENU"));
		add(menuPanel);
		
		drawPanel = new DrawingPanel();
		drawPanel.setBounds(220,10,400,400);//이거 없으면 안그려짐
		drawPanel.setBorder(BorderFactory.createTitledBorder("DRAWING"));
		add(drawPanel);
		
		menuBtnPanel = new JPanel();
		menuBtnPanel.setBounds(10, 30, 180, 140);
		menuBtnPanel.setLayout(new GridLayout(3,2)); //행과 열
		menuPanel.add(menuBtnPanel);
		
		btnMenuArray = new JButton[6];
		for(int i=0;i<6;i++) {
			btnMenuArray[i] = new JButton(DrawConstants.MENU[i]);
			btnMenuArray[i].setBackground(DrawConstants.EXIT[0]);
			btnMenuArray[i].setForeground(DrawConstants.EXIT[1]);
			btnMenuArray[i].addMouseListener(btnMenuL);
			menuBtnPanel.add(btnMenuArray[i]);
		}
	}
	
	//mouse 처리 함수
	private class BtnMenuListener implements MouseListener{
		public void mouseClicked(MouseEvent event) {}
		public void mousePressed(MouseEvent event) {}
		public void mouseReleased(MouseEvent event) {}
		public void mouseEntered(MouseEvent event) {
			JButton btnMenu = (JButton)event.getSource();
			btnMenu.setBackground(DrawConstants.ENTER[0]);
			btnMenu.setForeground(DrawConstants.ENTER[1]);
			
		} //mouseEntered()
		public void mouseExited(MouseEvent event) {
			JButton btnMenu = (JButton)event.getSource();
			btnMenu.setBackground(DrawConstants.EXIT[0]);
			btnMenu.setForeground(DrawConstants.EXIT[1]);
			
		} //mouseExited()
		
	}
}
	
