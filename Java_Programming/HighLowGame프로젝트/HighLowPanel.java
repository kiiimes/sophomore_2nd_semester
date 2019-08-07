import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class HighLowPanel extends JPanel {
	
	private JPanel leftPanel,rightPanel;// ���� �гΰ� ������ �г�
	private JLabel lblTitle,/*lblMark*/lblHint;//high low panel�� ����� ���� ������ �˷��ִ� hint label
	private JLabel lblCount;//ī��Ʈ ���°��� �����ֱ� ���� label
	
	private JButton btnRandom,btnInput;//���� ��ư�� �Է� ��ư
	private JTextField txtInput;//���� �Է��� �� �ִ� ĭ
	private int nRandom,nInput;//������ ���� �Է��� �� ���� ����
	
	private JLabel lblRange;//���� ���� ��Ÿ���� label
	private int nMin,nMax;//���� ���� ����
	private int cnt;//ī��Ʈ ���� ����
	
	private LabelThread lblMark;//? �� ���� ���ڸ� �����ִ� labelThread
	//2. declaration listener object;
	private GameListener gameL;//Ŭ�� ���� �� �� ���� �����ϴ� ���� 
	
	public HighLowPanel() {
		//this highlowpanel�� ����
		setPreferredSize(new Dimension(430,350));
		setBackground(Color.white);
		setLayout(null);
		
		//2.creating listener object
		gameL=new GameListener();
		
		//���� �г� ����
		leftPanel=new JPanel();
		leftPanel.setBounds(10, 10, 200, 300);
		leftPanel.setBackground(Color.cyan);
		leftPanel.setLayout(null);
		add(leftPanel);
		
		//������ �г� ����
		rightPanel=new JPanel();
		rightPanel.setBounds(220,10,200,300);
		rightPanel.setBackground(Color.yellow);
		rightPanel.setLayout(null);
		add(rightPanel);
		
		// title ����
		lblTitle=new JLabel("High-Low Game");
		lblTitle.setBounds(10,40,180,40);
		lblTitle.setFont(new Font("Consolas",Font.BOLD,24));
		lblTitle.setHorizontalAlignment(SwingConstants.CENTER);
		leftPanel.add(lblTitle);
		
		//���� ���̴� �κ� ����
		lblMark=new LabelThread(this);
		lblMark.setBounds(10,80,180,140);
		lblMark.setFont(new Font("Verdana",Font.BOLD,80));
		lblMark.setHorizontalAlignment(SwingConstants.CENTER);
		lblMark.setVisible(false);
		leftPanel.add(lblMark);
		
		//��Ʈ �� ����
		lblHint=new JLabel("right");
		lblHint.setBounds(10, 220, 180, 40);
		lblHint.setFont(new Font("Consolas",Font.BOLD,20));
		lblHint.setHorizontalAlignment(SwingConstants.CENTER);
		lblHint.setVisible(false);
		leftPanel.add(lblHint);
		
		//ī��Ʈ �� ����
		lblCount=new JLabel("");
		lblCount.setBounds(10,220,180,40);
		lblCount.setFont(new Font("Consolas",Font.BOLD,15));
		lblCount.setHorizontalAlignment(SwingConstants.CENTER);
		lblCount.setVisible(false);
		rightPanel.add(lblCount);
		
		//�����ϴ� ��ư ����
		btnRandom=new JButton("Generates");
		btnRandom.setBounds(30,50,140,40);
		btnRandom.setFont(new Font("Consolas",Font.BOLD,16));
		//3. add the listener object to the component
		btnRandom.addActionListener(gameL);//Ŭ������ �� actionListener�� �ҷ��´�.
		rightPanel.add(btnRandom);
		
		//���� �Է� �޴� �ʵ� ����
		txtInput = new JTextField();
		txtInput.setBounds(30, 100, 70, 40);
		txtInput.setEnabled(false);//ó������ ��ư�� ����� �� ���� ����
		txtInput.addActionListener(gameL);//Ŭ������ �� actinoListener�� �ҷ��´�.
		rightPanel.add(txtInput);
		
		//���ڸ� �Է��ϰ� ������ ��ư ����
		btnInput=new JButton("Input");
		btnInput.setBounds(105,100,65,40);
		btnInput.setEnabled(false);
		btnInput.setFont(new Font("Consolas",Font.PLAIN,11));
		btnInput.addActionListener(gameL);
		rightPanel.add(btnInput);
		
		//�������� ���� �ʱ�ȭ ��Ų��.
		nRandom=0;
		nInput=0;
		
		//�ּҰ��� �ִ밪�� 1~100���� ����, ī��Ʈ�� 0���� countup�ǹǷ� 0���� ����
		nMin=1;
		nMax=100;
		cnt=0;
		
		//���ڸ� �Է� �� �� ���� ���� ������ �ٲ�µ� �� ���� ������ �����ִ� �� ����
		lblRange=new JLabel("("+nMin+"~"+nMax+")");
		lblRange.setBounds(30,145,140,40);
		lblRange.setFont(new Font("Consolas",Font.BOLD,14));
		rightPanel.add(lblRange);
		
	}//HighLowPanel()
	
	//gameContine �Լ� ����
	public void gameContinue() {
		int result;//��� ���� ���������� �����ϴ�  ����
		
		result=JOptionPane.showConfirmDialog(rightPanel,"Continue");// ������ ����ǰ� �� ���� â�� �ߴ� ��ġ�� �˸�â �ȿ� ���� �ִ� �� ����
		
		// �� ��ư ������ �ʱ�ȭ�� ��Ų��. 
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
		
		//�ƴϿ� ��ư�� ���� �� ����
		else if(result==JOptionPane.NO_OPTION) {
			
		}
		//��� ��ư�� ������ �� ����
		else {
			
		}//cancle option
	}
	
	//1.listener class
	private class GameListener implements ActionListener{
		public void actionPerformed(ActionEvent event) {
			//4.event handling
			Object obj=event.getSource();//Ŭ���� ���� ������ ��ü�� ��ȯ����
			//��ȯ ������ btnRandom �� ������ ����
			if(obj==btnRandom) {
				nRandom=(int)(Math.random()*100)+1;//1~100�� ���� ������ nRandom�� ����
				lblMark.setText("?");
				lblMark.setVisible(true);//������ ���۵Ǹ� ? �� ȭ�鿡 �����ش�.
				
				btnRandom.setEnabled(false);// ���� �߿��� ���� ��ư�� �ٽ� ���� �� ������ ����������.
				//���� �Է¶��� �Է� ��ư�� ��� �����ϰ� �����.
				txtInput.setEnabled(true);
				btnInput.setEnabled(true);
			}
			//��ü�� �����Է¶��̳� �Է¹�ư�� ������ ����
			else if(obj==txtInput||obj==btnInput) {
				//���� �Է¶��� �Է��� ���ڸ� ���ڷ� �ٲ��ش�. 
				nInput=Integer.parseInt(txtInput.getText());
				txtInput.setText("");
				
				//�Է��� ���ڰ� ���� ���ں��� ũ�� high�� ����ϰ� hint ���� ������ �������ش�.
				if(nInput>nRandom) {
					nMax=nInput-1;
					lblHint.setText("High! ("+nMin+"~"+nMax+")");
				}
				//�Է��� ���ڰ� ���� ���ں��� ������ low�� ����ϰ� hint ���� ������ �������ش�.
				else if(nInput<nRandom) {
					nMin=nInput+1;
					lblHint.setText("Low ("+nMin+"~"+nMax+")");
				}
				//�Է��� ���ڿ� ���� ���ڰ� ������ right!�� ����Ѵ�
				else {
					lblHint.setText("Right!");
					//lblMark.setText(Integer.toString(nRandom));
					lblMark.setRange(1, nRandom+1);
					lblMark.start();
					
					//gameContinue();
					//�̷��� �ϰų� �ƴϤ��� ""+nRandom ���� ���ָ� �� 
				}
				cnt++; //���� �Է� Ƚ���� ���� �Է� �� ������ �ϳ��� �ø���.
				lblCount.setText("COUNTING : "+cnt);
				lblCount.setVisible(true);
				lblHint.setVisible(true);
			}
		}//actionPerformed
	}
	
}//HighLow class()
