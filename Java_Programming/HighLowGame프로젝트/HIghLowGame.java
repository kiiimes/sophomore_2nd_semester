import javax.swing.*;

public class HIghLowGame {

	public static void main(String[] args) {
		
		JFrame frame=new JFrame("High-Low Game");//�гε��� ������� ������ ����
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//�ݱ� ��ư�� �������� ����� ���α׷��� ����ǰ� ����
		frame.setResizable(false);//ȭ�� ũ�� ���� ���� ���ϰ� ����
		
		HighLowPanel gamePanel=new HighLowPanel();//���� �г� ���� 
		frame.getContentPane().add(gamePanel);//frame�� gamePanel ����
		
		//�⺻ frame setting
		frame.pack();
		frame.setVisible(true);//���� ���̵��� ���� 
		
	}

}
