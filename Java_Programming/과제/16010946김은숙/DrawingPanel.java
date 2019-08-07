import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class DrawingPanel extends JPanel {

	private ArrayList<DrawData> dataList;//�׸��� �����͸� �����ϴ� �迭
	private DrawData			data;//�׸��� �����͸� �����ϴ� ����
	private boolean				bDrag;//�巡�� �ƴ��� �ƴ��� ���� ����
	private PrimaryPanel		primary;// �����̸Ӹ� �г� ����
	
	private DrawListener		drawL;//�׸��� �����ϴ� ����
	
	//������
	public DrawingPanel(PrimaryPanel p) {
		setBackground(Color.white);
		setLayout(null);
		
		primary = p;//��ü ���� ����
		
		//��ü�� ����
		drawL = new DrawListener();
		addMouseListener(drawL);
		addMouseMotionListener(drawL);
		
		dataList = new ArrayList<DrawData>();
		data = new DrawData();
		
		bDrag = false;//�ʱ�ȭ
		
	} // DrawingPanel()
	
	//get/set method
	public DrawData getDrawData()	{ return data; }
	public Color getForeColor()		{ return data.getForeColor(); }
	public void setDrawData(DrawData temp) { 
		//data = temp;
		//data�� ������ ���ش�.
		data.setDrawMode(temp.getDrawMode());//��� �ް�
		data.setFill(temp.getFill());//ä������ ������ �ް�
		data.setForeColor(temp.getForeColor());//�۾� �� �ް�
		data.setPointOne(temp.getPointOne());//��ǥ ���۰� �ް�
		data.setPointTwo(temp.getPointTwo());//��ǥ ������ �� �ް�
		data.setSize(temp.getSize());//ũ�� ����
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
	public ArrayList<DrawData> getDataList() {
		return dataList;
	}
	
	public void undo() {
			dataList.remove(dataList.size()-1);
		
		repaint();
	}
	
	//�׷��ִ� �Լ�
	public void paintComponent(Graphics page) {
		super.paintComponent(page);
		
		Graphics2D page2 = (Graphics2D)page;
		
		if (bDrag) {//drag�Ǵ� ���� �׸� �� 
			page.setColor(data.getForeColor());
			
			switch(data.getDrawMode()) {
			case DrawConstants.DOT: //Dot�Ҷ� ��ǥ ��ġ�� �������� dot�� Ŭ�������� ����� Ŭ���ǰ� ������ 
				page.fillOval(	data.getPointOne().x-data.getSize()/2, 
								data.getPointOne().y-data.getSize()/2,
								data.getSize(),
								data.getSize());

				break;
			case DrawConstants.LINE://�� ������ �޾Ƽ� �׸� 
				page2.setStroke(new BasicStroke(data.getSize()));
				page.drawLine(	data.getPointOne().x, 
								data.getPointOne().y,
								data.getPointTwo().x,
								data.getPointTwo().y);
				break;
			case DrawConstants.RECT://�� ������ �޾Ƽ� �簢�� �׸� ���� ä���� ������ ������
				page2.setStroke(new BasicStroke(data.getSize()));
				drawRectOval(	page, 
								data.getPointOne(),
								data.getPointTwo(),
								data.getFill(),
								DrawConstants.RECT);
				break;
			case DrawConstants.OVAL://�� ������ �޾Ƽ� Ÿ�� �׸� ���� ä���� ������ ������
				page2.setStroke(new BasicStroke(data.getSize()));
				drawRectOval(	page, 
								data.getPointOne(),
								data.getPointTwo(),
								data.getFill(),
								DrawConstants.OVAL);
				break;		
			case DrawConstants.ARROW:
				page2.setStroke(new BasicStroke(data.getSize()));
				drawArrow(	page,data.getPointOne(),data.getPointTwo(),data.getButtonOption());
			} // switch			
		} // if
		
		for (DrawData saved:dataList) {//drawList �� �ִ� �������  ���̽��� �°� ������ �׷���
			page.setColor(saved.getForeColor());//���� �������ش�.
			
			switch(saved.getDrawMode()) {
			case DrawConstants.DOT://���϶�
				page.fillOval(	saved.getPointOne().x-saved.getSize()/2, 
								saved.getPointOne().y-saved.getSize()/2,
								saved.getSize(),
								saved.getSize());
				break;
			case DrawConstants.LINE://���϶�
				page2.setStroke(new BasicStroke(saved.getSize()));
				page.drawLine(	saved.getPointOne().x, 
								saved.getPointOne().y,
								saved.getPointTwo().x,
								saved.getPointTwo().y);
				break;
			case DrawConstants.RECT://�簢���϶�
				page2.setStroke(new BasicStroke(saved.getSize()));
				drawRectOval(	page, 
							saved.getPointOne(),
							saved.getPointTwo(),
							saved.getFill(),
								DrawConstants.RECT);
				break;
			case DrawConstants.OVAL://Ÿ���϶�
				page2.setStroke(new BasicStroke(saved.getSize()));
				drawRectOval(	page, 
							saved.getPointOne(),
							saved.getPointTwo(),
							saved.getFill(),
								DrawConstants.OVAL);
				break;		
			case DrawConstants.ARROW:
				page2.setStroke(new BasicStroke(saved.getSize()));
				drawArrow(page,saved.getPointOne(),saved.getPointTwo(),saved.getButtonOption());
				break;
			} // switch
		} // for
		
	} // paintComponent()
	
	private void drawArrow(Graphics page,Point pt1,Point pt2,int option) {
			int x,y,width,height;
			x=y=width=height=0;
		if(option==0) {
			y=(pt2.y+pt1.y)/2;
			x=((pt1.x+pt2.x)/2)+((pt1.y+pt2.y)/2);
		}
		page.drawLine(pt1.x, pt1.y, pt2.x, pt2.y);
			
	}
	
	//����� ��ǥ���� �����ؼ� ������ ������ 4���� ��츦 �����ؼ� option���� �׸��� �Լ�
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
		
		if (option == DrawConstants.RECT) { //rect�϶�
			//fill�� ���� ä�� ���� �׸��� ��ä�� ���� �׸����� ����
			if (fill) 	page.fillRect(x, y, width, height);
			else		page.drawRect(x, y, width, height);			
			
		} else if (option == DrawConstants.OVAL) { //oval�϶�
			//fill�� ���� ä�� ���� �׸��� �� ä�� ���� �׸����� ����
			if (fill) 	page.fillOval(x, y, width, height);
			else		page.drawOval(x, y, width, height);			
			
		} // if..else if
		
	} // drawRectOval()
	
	
	private class DrawListener implements 	MouseListener, 
											MouseMotionListener
	{
		public void mouseClicked(MouseEvent event) {//Dot�϶� Ŭ���ϸ� ��ǥ�� ��� ũ�� �� �������ְ� dataList�� �ְ� �Ź� �ٽ� �׷��ش�.
			if (data.getDrawMode() == DrawConstants.DOT) {
				data.setPointOne(event.getPoint());
				data.setSize(primary.getTextSize());
				dataList.add(new DrawData(data));
				repaint();
			} // if
			
		} // mouseClicked()
		
		public void mousePressed(MouseEvent event) {//�� ��츦 �����ؼ� ��ǥ�� �ް� �� ũ�� �������ְ� ä���� ������ �����ڴ�. 
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ||
				data.getDrawMode()==DrawConstants.ARROW) {
				
				data.setPointOne(event.getPoint());
				data.setSize(primary.getTextSize());
				data.setFill(primary.getFill());
				bDrag = true;//bDrag��  �巡�� �ƴ��� �ȵƴ��� üũ�Ѵ�.
				
			} // if
			
		} // mousePressed()
		public void mouseReleased(MouseEvent event) {//�� ��츦 �����ؼ� ��ǥ�� �ް� �� ũ�� �������ְ� ä���� ������ �����ڴ�. 
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ||
				data.getDrawMode()==DrawConstants.ARROW) {
				
				data.setPointTwo(event.getPoint());
				dataList.add(new DrawData(data));
				repaint();
				if(dataList.size()>0) {
					primary.setEnableButton(true);
				}
				if(dataList.size()==0) {
					primary.setEnableButton(false);
				}
				
				bDrag = false;//bDrag��  �巡�� �ƴ��� �ȵƴ��� üũ�Ѵ�.
			} // if
			
		} // mouseReleased()
		
		public void mouseEntered(MouseEvent event) {}
		public void mouseExited(MouseEvent event) {}
		
		public void mouseMoved(MouseEvent event) {}
		public void mouseDragged(MouseEvent event) {//�� ��带 Ȯ���ؼ� if���� ����.
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL||
				data.getDrawMode()==DrawConstants.ARROW) {
				
				data.setPointTwo(event.getPoint());//������ ��ġ�� �������ְ� 
				repaint();//�ٽ� �׷��ش�.
				
			} // if
			
		} // mouseDragged()
		
	} // DrawListener class
	
	
} // DrawingPanel class
