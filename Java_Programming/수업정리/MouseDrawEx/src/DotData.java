import java.awt.*;

public class DotData {
	private Point 	ptDot;
	private int		nDotSize;
	
	public DotData() {
		ptDot = new Point();
		nDotSize = 40;
	} // DotData()
	public DotData(Point pt, int size) {
		ptDot = pt;
		nDotSize = size;
	} // DotData()
	
	public Point getDot()			{ return ptDot; }
	public int getSize()			{ return nDotSize; }
	public int getX()				{ return ptDot.x; }
	public int getY()				{ return ptDot.y; }
	
	public void setDot(Point pt)	{ ptDot = pt; }
	public void setX(int x)			{ ptDot.x = x; }
	public void setY(int y)			{ ptDot.y = y; }
	public void setSize(int size)	{ nDotSize = size; }
	public void setData(Point pt, int size) {
		ptDot = pt;
		nDotSize = size;
	}
	public void setData(int x, int y, int size) {
		ptDot.x = x;
		ptDot.y = y;
		nDotSize = size;
	}
	
} // DotData class
