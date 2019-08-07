import java.awt.*;

public class DrawConstants {

	public static final int DOT 	= 0;//Dot ��� ����
	public static final int LINE 	= 1;//Line ��� ����
	public static final int RECT	= 2;//Rect ��� ����
	public static final int OVAL	= 3;//Oval ��� ����
	public static final int ARROW	=4;
	public static final int UNDO=5;
	public static final int NONE	= 6;//6��ĭ ��� ���� (�̸� ����� �̸� �־��)
	
	public static final String[] MENU = {	"DOT",
											"LINE",
											"RECT",
											"OVAL",
											"ARROW",
											"UNDO"
										};//�޴��� �� �̸��� �迭 ����
	public static final Color[] EXIT = {Color.white,Color.black};//���콺 exit�϶� �۾��� ���� ����
	public static final Color[] ENTER ={Color.white,Color.red};//���콺 enter�϶� �۾��� ���� ����
	
} // DrawConstants class
