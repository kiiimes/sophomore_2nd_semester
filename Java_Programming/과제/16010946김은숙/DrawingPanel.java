import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.*;

public class DrawingPanel extends JPanel {

	private ArrayList<DrawData> dataList;//그리는 데이터를 저장하는 배열
	private DrawData			data;//그림의 데이터를 저장하는 변수
	private boolean				bDrag;//드래그 됐는지 아닌지 저장 변수
	private PrimaryPanel		primary;// 프라이머리 패널 변수
	
	private DrawListener		drawL;//그릴때 설정하는 변수
	
	//생성자
	public DrawingPanel(PrimaryPanel p) {
		setBackground(Color.white);
		setLayout(null);
		
		primary = p;//객체 인자 대입
		
		//객체들 생성
		drawL = new DrawListener();
		addMouseListener(drawL);
		addMouseMotionListener(drawL);
		
		dataList = new ArrayList<DrawData>();
		data = new DrawData();
		
		bDrag = false;//초기화
		
	} // DrawingPanel()
	
	//get/set method
	public DrawData getDrawData()	{ return data; }
	public Color getForeColor()		{ return data.getForeColor(); }
	public void setDrawData(DrawData temp) { 
		//data = temp;
		//data의 설정을 해준다.
		data.setDrawMode(temp.getDrawMode());//모드 받고
		data.setFill(temp.getFill());//채워줄지 말지를 받고
		data.setForeColor(temp.getForeColor());//글씨 색 받고
		data.setPointOne(temp.getPointOne());//좌표 시작값 받고
		data.setPointTwo(temp.getPointTwo());//좌표 끝나는 값 받고
		data.setSize(temp.getSize());//크기 지정
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
	
	//그려주는 함수
	public void paintComponent(Graphics page) {
		super.paintComponent(page);
		
		Graphics2D page2 = (Graphics2D)page;
		
		if (bDrag) {//drag되는 동안 그릴 때 
			page.setColor(data.getForeColor());
			
			switch(data.getDrawMode()) {
			case DrawConstants.DOT: //Dot할때 좌표 위치를 설정해줌 dot를 클릭했을때 가운데에 클릭되게 만들음 
				page.fillOval(	data.getPointOne().x-data.getSize()/2, 
								data.getPointOne().y-data.getSize()/2,
								data.getSize(),
								data.getSize());

				break;
			case DrawConstants.LINE://선 사이즈 받아서 그림 
				page2.setStroke(new BasicStroke(data.getSize()));
				page.drawLine(	data.getPointOne().x, 
								data.getPointOne().y,
								data.getPointTwo().x,
								data.getPointTwo().y);
				break;
			case DrawConstants.RECT://선 사이즈 받아서 사각형 그림 색을 채울지 말지도 정해줌
				page2.setStroke(new BasicStroke(data.getSize()));
				drawRectOval(	page, 
								data.getPointOne(),
								data.getPointTwo(),
								data.getFill(),
								DrawConstants.RECT);
				break;
			case DrawConstants.OVAL://선 사이즈 받아서 타원 그림 색을 채울지 말지도 정해줌
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
		
		for (DrawData saved:dataList) {//drawList 에 있는 내용들을  케이스에 맞게 나눠서 그려줌
			page.setColor(saved.getForeColor());//색을 설정해준다.
			
			switch(saved.getDrawMode()) {
			case DrawConstants.DOT://점일때
				page.fillOval(	saved.getPointOne().x-saved.getSize()/2, 
								saved.getPointOne().y-saved.getSize()/2,
								saved.getSize(),
								saved.getSize());
				break;
			case DrawConstants.LINE://선일때
				page2.setStroke(new BasicStroke(saved.getSize()));
				page.drawLine(	saved.getPointOne().x, 
								saved.getPointOne().y,
								saved.getPointTwo().x,
								saved.getPointTwo().y);
				break;
			case DrawConstants.RECT://사각형일때
				page2.setStroke(new BasicStroke(saved.getSize()));
				drawRectOval(	page, 
							saved.getPointOne(),
							saved.getPointTwo(),
							saved.getFill(),
								DrawConstants.RECT);
				break;
			case DrawConstants.OVAL://타원일때
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
	
	//어느쪽 좌표부터 시작해서 도형을 만들지 4가지 경우를 설정해서 option별로 그리는 함수
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
		
		if (option == DrawConstants.RECT) { //rect일때
			//fill에 따라 채운 도형 그릴지 안채운 도형 그릴지를 정함
			if (fill) 	page.fillRect(x, y, width, height);
			else		page.drawRect(x, y, width, height);			
			
		} else if (option == DrawConstants.OVAL) { //oval일때
			//fill에 따라 채운 도형 그릴지 안 채운 도형 그릴지를 정함
			if (fill) 	page.fillOval(x, y, width, height);
			else		page.drawOval(x, y, width, height);			
			
		} // if..else if
		
	} // drawRectOval()
	
	
	private class DrawListener implements 	MouseListener, 
											MouseMotionListener
	{
		public void mouseClicked(MouseEvent event) {//Dot일때 클릭하면 좌표값 얻고 크기 얻어서 설정해주고 dataList에 넣고 매번 다시 그려준다.
			if (data.getDrawMode() == DrawConstants.DOT) {
				data.setPointOne(event.getPoint());
				data.setSize(primary.getTextSize());
				dataList.add(new DrawData(data));
				repaint();
			} // if
			
		} // mouseClicked()
		
		public void mousePressed(MouseEvent event) {//각 경우를 선택해서 좌표값 받고 선 크기 설정해주고 채울지 말지를 설정핸다. 
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL ||
				data.getDrawMode()==DrawConstants.ARROW) {
				
				data.setPointOne(event.getPoint());
				data.setSize(primary.getTextSize());
				data.setFill(primary.getFill());
				bDrag = true;//bDrag가  드래그 됐는지 안됐는지 체크한다.
				
			} // if
			
		} // mousePressed()
		public void mouseReleased(MouseEvent event) {//각 경우를 선택해서 좌표값 받고 선 크기 설정해주고 채울지 말지를 설정핸다. 
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
				
				bDrag = false;//bDrag가  드래그 됐는지 안됐는지 체크한다.
			} // if
			
		} // mouseReleased()
		
		public void mouseEntered(MouseEvent event) {}
		public void mouseExited(MouseEvent event) {}
		
		public void mouseMoved(MouseEvent event) {}
		public void mouseDragged(MouseEvent event) {//각 모드를 확인해서 if문에 들어간다.
			if (data.getDrawMode() == DrawConstants.LINE ||
				data.getDrawMode() == DrawConstants.RECT ||
				data.getDrawMode() == DrawConstants.OVAL||
				data.getDrawMode()==DrawConstants.ARROW) {
				
				data.setPointTwo(event.getPoint());//끝점의 위치를 설정해주고 
				repaint();//다시 그려준다.
				
			} // if
			
		} // mouseDragged()
		
	} // DrawListener class
	
	
} // DrawingPanel class
