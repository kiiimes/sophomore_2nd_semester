import javax.swing.*;

public class HIghLowGame {

	public static void main(String[] args) {
		
		JFrame frame=new JFrame("High-Low Game");//패널들을 담기위한 프레임 생성
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//닫기 버튼을 눌렀을때 제대로 프로그램이 종료되게 설정
		frame.setResizable(false);//화면 크기 조정 하지 못하게 설정
		
		HighLowPanel gamePanel=new HighLowPanel();//메인 패널 설정 
		frame.getContentPane().add(gamePanel);//frame에 gamePanel 붙임
		
		//기본 frame setting
		frame.pack();
		frame.setVisible(true);//눈에 보이도록 설정 
		
	}

}
