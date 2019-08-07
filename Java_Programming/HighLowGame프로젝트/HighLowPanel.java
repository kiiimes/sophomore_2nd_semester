import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HighLowPanel extends JPanel {
	
	private JPanel leftPanel,rightPanel;// 왼쪽 패널과 오른쪽 패널
	private JLabel lblTitle,/*lblMark*/lblHint;//high low panel의 제목과 숫자 범위를 알려주는 hint label
	private JLabel lblCount;//카운트 세는것을 보여주기 위한 label
	
	private JButton btnRandom,btnInput;//시작 버튼과 입력 버튼
	private JTextField txtInput;//숫자 입력할 수 있는 칸
	private int nRandom,nInput;//랜덤한 수와 입력한 수 저장 변수
	
	private JLabel lblRange;//숫자 범위 나타내는 label
	private int nMin,nMax;//숫자 범위 변수
	private int cnt;//카운트 세는 변수
	
	private LabelThread lblMark;//? 와 맞춘 숫자를 보여주는 labelThread
	//2. declaration listener object;
	private GameListener gameL;//클릭 했을 때 그 내용 저장하는 변수 
	
	public HighLowPanel() {
		//this highlowpanel의 설정
		setPreferredSize(new Dimension(430,350));
		setBackground(Color.white);
		setLayout(null);
		
		//2.creating listener object
		gameL=new GameListener();
		
		//왼쪽 패널 설정
		leftPanel=new JPanel();
		leftPanel.setBounds(10, 10, 200, 300);
		leftPanel.setBackground(Color.cyan);
		leftPanel.setLayout(null);
		add(leftPanel);
		
		//오른쪽 패널 설정
		rightPanel=new JPanel();
		rightPanel.setBounds(220,10,200,300);
		rightPanel.setBackground(Color.yellow);
		rightPanel.setLayout(null);
		add(rightPanel);
		
		// title 설정
		lblTitle=new JLabel("High-Low Game");
		lblTitle.setBounds(10,40,180,40);
		lblTitle.setFont(new Font("Consolas",Font.BOLD,24));
		lblTitle.setHorizontalAlignment(SwingConstants.CENTER);
		leftPanel.add(lblTitle);
		
		//숫자 보이는 부분 설정
		lblMark=new LabelThread(this);
		lblMark.setBounds(10,80,180,140);
		lblMark.setFont(new Font("Verdana",Font.BOLD,80));
		lblMark.setHorizontalAlignment(SwingConstants.CENTER);
		lblMark.setVisible(false);
		leftPanel.add(lblMark);
		
		//힌트 라벨 설정
		lblHint=new JLabel("right");
		lblHint.setBounds(10, 220, 180, 40);
		lblHint.setFont(new Font("Consolas",Font.BOLD,20));
		lblHint.setHorizontalAlignment(SwingConstants.CENTER);
		lblHint.setVisible(false);
		leftPanel.add(lblHint);
		
		//카운트 라벨 설정
		lblCount=new JLabel("");
		lblCount.setBounds(10,220,180,40);
		lblCount.setFont(new Font("Consolas",Font.BOLD,15));
		lblCount.setHorizontalAlignment(SwingConstants.CENTER);
		lblCount.setVisible(false);
		rightPanel.add(lblCount);
		
		//시작하는 버튼 설정
		btnRandom=new JButton("Generates");
		btnRandom.setBounds(30,50,140,40);
		btnRandom.setFont(new Font("Consolas",Font.BOLD,16));
		//3. add the listener object to the component
		btnRandom.addActionListener(gameL);//클릭햇을 때 actionListener를 불러온다.
		rightPanel.add(btnRandom);
		
		//숫자 입력 받는 필드 설정
		txtInput = new JTextField();
		txtInput.setBounds(30, 100, 70, 40);
		txtInput.setEnabled(false);//처음에는 버튼을 사용할 수 없게 설정
		txtInput.addActionListener(gameL);//클릭했을 때 actinoListener를 불러온다.
		rightPanel.add(txtInput);
		
		//숫자를 입력하고 누르는 버튼 설정
		btnInput=new JButton("Input");
		btnInput.setBounds(105,100,65,40);
		btnInput.setEnabled(false);
		btnInput.setFont(new Font("Consolas",Font.PLAIN,11));
		btnInput.addActionListener(gameL);
		rightPanel.add(btnInput);
		
		//변수들을 전부 초기화 시킨다.
		nRandom=0;
		nInput=0;
		
		//최소값과 최대값은 1~100으로 설정, 카운트는 0부터 countup되므로 0으로 설정
		nMin=1;
		nMax=100;
		cnt=0;
		
		//숫자를 입력 할 때 마다 값의 범위가 바뀌는데 그 값의 범위를 보여주는 라벨 설정
		lblRange=new JLabel("("+nMin+"~"+nMax+")");
		lblRange.setBounds(30,145,140,40);
		lblRange.setFont(new Font("Consolas",Font.BOLD,14));
		rightPanel.add(lblRange);
		
	}//HighLowPanel()
	
	//gameContine 함수 설정
	public void gameContinue() {
		int result;//어느 것을 눌렀는지를 저장하는  변수
		
		result=JOptionPane.showConfirmDialog(rightPanel,"Continue");// 게임이 종료되고 난 후의 창이 뜨는 위치와 알림창 안에 쓰여 있는 말 설정
		
		// 예 버튼 누르면 초기화를 시킨다. 
		if(result==JOptionPane.YES_OPTION) {
			
			lblHint.setVisible(false);
			lblMark.setVisible(false);
			lblCount.setVisible(false);
			btnRandom.setEnabled(true);
			txtInput.setEnabled(false);
			btnInput.setEnabled(false);
			
			lblMark.setForeground(Color.BLACK);
			
			nMin=1;
			nMax=100;
			cnt=0;
			
		}
		
		//아니오 버튼을 누를 때 실행
		else if(result==JOptionPane.NO_OPTION) {
			
		}
		//취소 버튼을 눌렀을 때 실행
		else {
			
		}//cancle option
	}
	
	//1.listener class
	private class GameListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			//4.event handling
			Object obj=event.getSource();//클릭한 것의 정보를 객체로 반환해줌
			//반환 내용이 btnRandom 과 같으면 실행
			if(obj==btnRandom) {
				nRandom=(int)(Math.random()*100)+1;//1~100의 랜덤 변수를 nRandom에 저장
				lblMark.setText("?");
				lblMark.setVisible(true);//게임이 시작되면 ? 를 화면에 보여준다.
				
				btnRandom.setEnabled(false);// 게임 중에는 시작 버튼을 다시 누를 수 없도록 설정ㅎ나다.
				//숫자 입력란과 입력 버튼을 사용 가능하게 만든다.
				txtInput.setEnabled(true);
				btnInput.setEnabled(true);
			}
			//객체가 숫자입력란이나 입력버튼과 같으면 실행
			else if(obj==txtInput||obj==btnInput) {
				//숫자 입력란에 입력한 문자를 숫자로 바꿔준다. 
				nInput=Integer.parseInt(txtInput.getText());
				txtInput.setText("");
				
				//입력한 숫자가 정답 숫자보다 크면 high를 출력하고 hint 숫자 범위를 수정해준다.
				if(nInput>nRandom) {
					nMax=nInput-1;
					lblHint.setText("High! ("+nMin+"~"+nMax+")");
				}
				//입력한 숫자가 정답 숫자보다 작으면 low를 출력하고 hint 숫자 범위를 수정해준다.
				else if(nInput<nRandom) {
					nMin=nInput+1;
					lblHint.setText("Low ("+nMin+"~"+nMax+")");
				}
				//입력한 숫자와 정답 숫자가 같으면 right!를 출력한다
				else {
					lblHint.setText("Right!");
					//lblMark.setText(Integer.toString(nRandom));
					lblMark.setRange(1, nRandom+1);
					lblMark.start();
					
					//gameContinue();
					//이렇게 하거나 아니ㅏ면 ""+nRandom 으로 써주면 됨 
				}
				cnt++; //숫자 입력 횟수를 숫자 입력 할 때마다 하나씩 올린다.
				lblCount.setText("COUNTING : "+cnt);
				lblCount.setVisible(true);
				lblHint.setVisible(true);
			}
		}//actionPerformed
	}
	
}//HighLow class()
