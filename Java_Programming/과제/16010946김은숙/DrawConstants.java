import java.awt.*;

public class DrawConstants {

	public static final int DOT 	= 0;//Dot 상수 정의
	public static final int LINE 	= 1;//Line 상수 정의
	public static final int RECT	= 2;//Rect 상수 정의
	public static final int OVAL	= 3;//Oval 상수 정의
	public static final int ARROW	=4;
	public static final int UNDO=5;
	public static final int NONE	= 6;//6번칸 상수 정의 (이름 생기면 이름 넣어라)
	
	public static final String[] MENU = {	"DOT",
											"LINE",
											"RECT",
											"OVAL",
											"ARROW",
											"UNDO"
										};//메뉴에 들어갈 이름들 배열 정의
	public static final Color[] EXIT = {Color.white,Color.black};//마우스 exit일때 글씨랑 배경색 정의
	public static final Color[] ENTER ={Color.white,Color.red};//마우스 enter일때 글씨랑 배경색 정의
	
} // DrawConstants class
