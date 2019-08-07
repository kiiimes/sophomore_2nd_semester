import java.awt.*;

public class DrawData {

	private int nDrawMode;//모드 변수
	private Point ptOne, ptTwo;//좌표 변수
	private int nSize;//크기 변수
	private boolean bFill;//색채울지 말지 변수
	private Color foreColor;//색 설정 변수
	private int buttonOption;
	
	//생성자
	public DrawData() {
		nDrawMode = DrawConstants.NONE;//모드 선택
		ptOne = new Point();//좌표 생성
		ptTwo = new Point();//좌표 생성
		nSize = 4;//크기 설정
		bFill = false;//채우기 설정
		foreColor = Color.black; // new Color(0,0,0);
	} // DrawData()
	public DrawData(DrawData data) {
		nDrawMode = data.getDrawMode();//모드 받아옴
		ptOne 		= data.getPointOne();//좌표 받아옴
		ptTwo 		= data.getPointTwo();//좌표 받아옴
		nSize 		= data.getSize();//크기 받아옴
		bFill 		= data.getFill();//채우기 받아옴
		foreColor 	= data.getForeColor();//선 색 받아옴
		buttonOption=data.getButtonOption();
		
	} // DrawData()
	
	//get/set method
	public int getDrawMode()	{ return nDrawMode; }
	public Point getPointOne()	{ return ptOne; }
	public Point getPointTwo()	{ return ptTwo; }
	public int getSize()		{ return nSize; }
	public boolean getFill()	{ return bFill; }
	public Color getForeColor()	{ return foreColor; }
	public int getButtonOption() {return buttonOption;}
	
	public void setDrawMode(int mode)	{ nDrawMode = mode; }
	public void setPointOne(Point pt)	{ ptOne = pt; }
	public void setPointTwo(Point pt)	{ ptTwo = pt; }
	public void setSize(int size)		{ nSize = size; }
	public void setFill(boolean fill)	{ bFill = fill; }
	public void setForeColor(Color fore){ foreColor = fore; }
	public void setButtonOption(int n) {buttonOption=n;}
	
} // DrawData class
