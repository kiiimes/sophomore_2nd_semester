import java.awt.*;

public class DrawData {

	private int nDrawMode;
	private Point ptOne, ptTwo;
	private int nSize;
	private boolean bFill;
	private Color foreColor;
	
	public DrawData() {
		nDrawMode = DrawConstants.NONE;
		ptOne = new Point();
		ptTwo = new Point();
		nSize = 4;
		bFill = false;
		foreColor = Color.black; // new Color(0,0,0);
	} // DrawData()
	public DrawData(DrawData data) {
		nDrawMode = data.getDrawMode();
		ptOne 		= data.getPointOne();
		ptTwo 		= data.getPointTwo();
		nSize 		= data.getSize();
		bFill 		= data.getFill();
		foreColor 	= data.getForeColor();
	} // DrawData()
	
	public int getDrawMode()	{ return nDrawMode; }
	public Point getPointOne()	{ return ptOne; }
	public Point getPointTwo()	{ return ptTwo; }
	public int getSize()		{ return nSize; }
	public boolean getFill()	{ return bFill; }
	public Color getForeColor()	{ return foreColor; }
	
	public void setDrawMode(int mode)	{ nDrawMode = mode; }
	public void setPointOne(Point pt)	{ ptOne = pt; }
	public void setPointTwo(Point pt)	{ ptTwo = pt; }
	public void setSize(int size)		{ nSize = size; }
	public void setFill(boolean fill)	{ bFill = fill; }
	public void setForeColor(Color fore){ foreColor = fore; }
	
} // DrawData class
