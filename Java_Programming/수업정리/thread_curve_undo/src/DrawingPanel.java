import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class DrawingPanel extends JPanel {

	private ArrayList<DrawData> dataList;
	private DrawData			data;
	private boolean				bDrag;
	private PrimaryPanel		primary;
	
	private DrawListener		drawL;
	
	public DrawingPanel(PrimaryPanel p) {
		setBackground(Color.white);
		setLayout(null);
		
		primary = p;
		
		drawL = new DrawListener();
		addMouseListener(drawL);
		addMouseMotionListener(drawL);
		
		dataList = new ArrayList<DrawData>();
		data = new DrawData();
		
		bDrag = false;
		
	} // DrawingPanel()
	
	public DrawData getDrawData()	{ return data; }
	public Color getForeColor()		{ return data.getForeColor(); }
	public void setDrawData(DrawData temp) { 
		//data = temp;
		data.setDrawMode(temp.getDrawMode());
		data.setFill(temp.getFill());
		data.setForeColor(temp.getForeColor());
		data.setPointOne(temp.getPointOne());
		data.setPointTwo(temp.getPointTwo());
		data.setSize(temp.getSize());
	}
	public void setDrawMode(int mode) { 
		data.setDrawMode(mode);
	}
	public void setFill(boolean fill) {
		data.setFill(fill);		
	}
	public void setForeColor(Color fore) {
		data.setForeColor(fore);
	}
	public void setPointOne(Point pt) {
		data.setPointOne(pt);
	}
	public void setPointTwo(Point pt) {
		data.setPointTwo(pt);
	}
	public void setSize(int size) {
		data.setSize(size);
	}
	
	public void UNDO() {
		if(dataList.size()>0)
			dataList.remove(dataList.size()-1);
	}
	
	
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
				repaint();
				break;
			case DrawConstants.LINE:
				page2.setStroke(new BasicStroke(data.getSize()));
				page.drawLine(	data.getPointOne().x, 
								data.getPointOne().y,
								data.getPointTwo().x,
								data.getPointTwo().y);
				repaint();
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
			case DrawConstants.CURVE:
				page2.setStroke(new BasicStroke(data.getSize()));
				page.drawLine(	data.getPointOne().x, 
								data.getPointOne().y,
								data.getPointTwo().x,
								data.getPointTwo().y);
				repaint();
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
			case DrawConstants.CURVE:
				page2.setStroke(new BasicStroke(saved.getSize()));
				page.drawLine(	saved.getPointOne().x, 
								saved.getPointOne().y,
								saved.getPointTwo().x,
								saved.getPointTwo().y);
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
		
		repaint();
		
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
				data.setSize(primary.getTextSize());
				dataList.add(new DrawData(data));
				
				primary.stop_Thread();
				primary.setSLoc(event.getX(), event.getY());
				primary.setELoc(event.getX(), event.getY());
				primary.start_Thread();
				
				repaint();
			} // if
		} // mouseClicked()
		
		public void mousePressed(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ) {
				
				data.setPointOne(event.getPoint());
				data.setSize(primary.getTextSize());
				data.setFill(primary.getFill());
				bDrag = true;
				
			} // if
			if(data.getDrawMode() == DrawConstants.CURVE) { // 여기서 처음 좌표 입력을 받게 되지!
				data.setPointOne(event.getPoint());
				data.setSize(primary.getTextSize());
				primary.setELoc(data.getPointOne().x,data.getPointOne().y);
				bDrag = true;
			}
			primary.setSLoc(data.getPointOne().x, data.getPointOne().y);
		} // mousePressed()
		public void mouseReleased(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ) {
				
				data.setPointTwo(event.getPoint());
				dataList.add(new DrawData(data));
				repaint();
				primary.stop_Thread();
				primary.setELoc(data.getPointTwo().x,data.getPointTwo().y);
				primary.start_Thread();
				bDrag = false;
			} // if
			else if(data.getDrawMode() == DrawConstants.CURVE) {
				data.setPointTwo(event.getPoint());
				dataList.add(new DrawData(data));
				primary.stop_Thread();
				primary.setELoc(data.getPointTwo().x,data.getPointTwo().y);
				primary.start_Thread();
				repaint();
			}
		} // mouseReleased()
		
		public void mouseEntered(MouseEvent event) {}
		public void mouseExited(MouseEvent event) {}
		
		public void mouseMoved(MouseEvent event) {}
		public void mouseDragged(MouseEvent event) {
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ) {
				
				data.setPointTwo(event.getPoint());
				primary.setELoc(data.getPointTwo().x,data.getPointTwo().y);
				repaint();
				
			} // if
			else if(data.getDrawMode() == DrawConstants.CURVE) {
				data.setPointTwo(event.getPoint());
				dataList.add(new DrawData(data));
				data.setPointOne(event.getPoint());
				primary.setELoc(data.getPointTwo().x,data.getPointTwo().y);
				repaint();
			}
			
		} // mouseDragged()
		
	} // DrawListener class
	
	
} // DrawingPanel class
