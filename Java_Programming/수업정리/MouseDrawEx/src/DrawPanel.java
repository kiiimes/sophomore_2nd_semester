import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class DrawPanel extends JPanel {

	//private Point 	ptDot;
	//private int		nDotSize;
	//private DotData		data;
	private ArrayList<DotData> dataList;
	private JTextField txtDotSize;
	
	// 2. declaration of listener object
	private DotListener dotL;
	
	public DrawPanel() {
		setPreferredSize(new Dimension(400,400));
		setBackground(Color.white);
		
		// 2. creating listener object
		dotL = new DotListener();		
		// 3. add the listener object
		addMouseListener(dotL);
		
		//ptDot = new Point(); // ptDot.x = ptDot.y = 0;
		//nDotSize = 40;
		//data = new DotData();
		dataList = new ArrayList<DotData>();
		
		txtDotSize = new JTextField(6);
		add(txtDotSize);
		
	} // DrawPanel()
	
	public void paintComponent(Graphics page) {
		super.paintComponent(page);
		
		//for (int i=0; i<dataList.size(); i++) {
			
			//DotData data = dataList.get(i);
		
		for (DotData data:dataList) {
			
			page.fillOval(	data.getX()-data.getSize()/2,
							data.getY()-data.getSize()/2,
							data.getSize(),
							data.getSize());
		} // for
		
		
		/*
		page.fillOval(	data.getX()-data.getSize()/2,
						data.getY()-data.getSize()/2,
						data.getSize(),
						data.getSize());*/
				
				
				
						/*ptDot.x-nDotSize/2, 
						ptDot.y-nDotSize/2, 
						nDotSize, 
						nDotSize);*/
		
	} // paintComponent()	
	
	
	// 1. listener class
	private class DotListener implements MouseListener
	{
		public void mouseClicked(MouseEvent event) 	{
			// 4. event handling
			//ptDot = event.getPoint();
			//data.setDot(event.getPoint());
			
			//nDotSize = Integer.parseInt(txtDotSize.getText());
			//data.setSize(Integer.parseInt(txtDotSize.getText()));
			
			dataList.add(new DotData(	
					event.getPoint(),
					Integer.parseInt(txtDotSize.getText())
					));
			
			repaint();
			
		} // mouseClicked()
		
		public void mousePressed(MouseEvent event) 	{}
		public void mouseReleased(MouseEvent event)	{}
		public void mouseEntered(MouseEvent event) 	{}
		public void mouseExited(MouseEvent event) 	{}		
	} // DotListener class
	
} // DrawPanel class
