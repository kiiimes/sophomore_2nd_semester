import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class DrawingPanel extends JPanel {

	private ArrayList<DrawData> dataList;
	private DrawData			data;
	private boolean				bDrag;
	
	private DrawListener		drawL;
	
	public DrawingPanel() {
		setBackground(Color.white);
		setLayout(null);
		
		drawL = new DrawListener();
		addMouseListener(drawL);
		addMouseMotionListener(drawL);
		
		dataList = new ArrayList<DrawData>();
		data = new DrawData();
		// test
		data.setDrawMode(DrawConstants.LINE);
		data.setSize(2);
		//data.setFill(true);
		data.setForeColor(Color.red);
		
		bDrag = false;
		
	} // DrawingPanel()
	
	public void paintComponent(Graphics page) {
		super.paintComponent(page);
		
		Graphics2D page2 = (Graphics2D)page;
		
		if (bDrag) {
			page.setColor(data.getForeColor());
			
			switch(data.getDrawMode()) {
			case DrawConstants.DOT:
				page.fillOval(	data.getPointOne().x-data.getSize()/2, 
								data.getPointOne().y-data.getSize()/2,
								data.getSize(),
								data.getSize());
				break;
			case DrawConstants.LINE:
				page2.setStroke(new BasicStroke(data.getSize()));
				page.drawLine(	data.getPointOne().x, 
								data.getPointOne().y,
								data.getPointTwo().x,
								data.getPointTwo().y);
				break;
			case DrawConstants.RECT:
				page2.setStroke(new BasicStroke(data.getSize()));
				drawRectOval(	page, 
								data.getPointOne(),
								data.getPointTwo(),
								data.getFill(),
								DrawConstants.RECT);
				break;
			case DrawConstants.OVAL:
				page2.setStroke(new BasicStroke(data.getSize()));
				drawRectOval(	page, 
								data.getPointOne(),
								data.getPointTwo(),
								data.getFill(),
								DrawConstants.OVAL);
				break;			
			} // switch			
		} // if
		
		for (DrawData saved:dataList) {
			page.setColor(saved.getForeColor());
			
			switch(saved.getDrawMode()) {
			case DrawConstants.DOT:
				page.fillOval(	saved.getPointOne().x-saved.getSize()/2, 
								saved.getPointOne().y-saved.getSize()/2,
								saved.getSize(),
								saved.getSize());
				break;
			case DrawConstants.LINE:
				page2.setStroke(new BasicStroke(saved.getSize()));
				page.drawLine(	saved.getPointOne().x, 
								saved.getPointOne().y,
								saved.getPointTwo().x,
								saved.getPointTwo().y);
				break;
			case DrawConstants.RECT:
				page2.setStroke(new BasicStroke(saved.getSize()));
				drawRectOval(	page, 
							saved.getPointOne(),
							saved.getPointTwo(),
							saved.getFill(),
								DrawConstants.RECT);
				break;
			case DrawConstants.OVAL:
				page2.setStroke(new BasicStroke(saved.getSize()));
				drawRectOval(	page, 
							saved.getPointOne(),
							saved.getPointTwo(),
							saved.getFill(),
								DrawConstants.OVAL);
				break;			
			} // switch
		} // for
		
	} // paintComponent()
	
	private void drawRectOval(	Graphics page, 
								Point pt1, 
								Point pt2,
								boolean fill,
								int option) {
		
		int x, y, width, height;
		x = y = width = height = 0;
		
		if (pt1.x<pt2.x && pt1.y<pt2.y) {
			x = pt1.x;
			y = pt1.y;
			width = pt2.x - pt1.x;
			height = pt2.y - pt1.y;
		} else if (pt1.x<pt2.x && pt1.y>pt2.y) {
			x = pt1.x;
			y = pt2.y;
			width = pt2.x - pt1.x;
			height = pt1.y - pt2.y;
		} else if (pt1.x>pt2.x && pt1.y<pt2.y) {
			x = pt2.x;
			y = pt1.y;
			width = pt1.x - pt2.x;
			height = pt2.y - pt1.y;
		} else if (pt1.x>pt2.x && pt1.y>pt2.y) {
			x = pt2.x;
			y = pt2.y;
			width = pt1.x - pt2.x;
			height = pt1.y - pt2.y;
		} // if..else if
		
		if (option == DrawConstants.RECT) {
			
			if (fill) 	page.fillRect(x, y, width, height);
			else		page.drawRect(x, y, width, height);			
			
		} else if (option == DrawConstants.OVAL) {
			
			if (fill) 	page.fillOval(x, y, width, height);
			else		page.drawOval(x, y, width, height);			
			
		} // if..else if
		
	} // drawRectOval()
	
	
	private class DrawListener implements 	MouseListener, 
											MouseMotionListener
	{
		public void mouseClicked(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.DOT) {
				data.setPointOne(event.getPoint());
				dataList.add(new DrawData(data));
				repaint();
			} // if
			
		} // mouseClicked()
		
		public void mousePressed(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ) {
				
				data.setPointOne(event.getPoint());
				bDrag = true;
				
			} // if
			
		} // mousePressed()
		public void mouseReleased(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ) {
				
				data.setPointTwo(event.getPoint());
				dataList.add(new DrawData(data));
				repaint();
				
				bDrag = false;
			} // if
			
		} // mouseReleased()
		
		public void mouseEntered(MouseEvent event) {}
		public void mouseExited(MouseEvent event) {}
		
		public void mouseMoved(MouseEvent event) {}
		public void mouseDragged(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ) {
				
				data.setPointTwo(event.getPoint());
				repaint();
				
			} // if
			
		} // mouseDragged()
		
	} // DrawListener class
	
	
} // DrawingPanel class
