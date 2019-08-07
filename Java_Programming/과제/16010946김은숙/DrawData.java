import java.awt.*;

public class DrawData {

	private int nDrawMode;//��� ����
	private Point ptOne, ptTwo;//��ǥ ����
	private int nSize;//ũ�� ����
	private boolean bFill;//��ä���� ���� ����
	private Color foreColor;//�� ���� ����
	private int buttonOption;
	
	//������
	public DrawData() {
		nDrawMode = DrawConstants.NONE;//��� ����
		ptOne = new Point();//��ǥ ����
		ptTwo = new Point();//��ǥ ����
		nSize = 4;//ũ�� ����
		bFill = false;//ä��� ����
		foreColor = Color.black; // new Color(0,0,0);
	} // DrawData()
	public DrawData(DrawData data) {
		nDrawMode = data.getDrawMode();//��� �޾ƿ�
		ptOne 		= data.getPointOne();//��ǥ �޾ƿ�
		ptTwo 		= data.getPointTwo();//��ǥ �޾ƿ�
		nSize 		= data.getSize();//ũ�� �޾ƿ�
		bFill 		= data.getFill();//ä��� �޾ƿ�
		foreColor 	= data.getForeColor();//�� �� �޾ƿ�
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
