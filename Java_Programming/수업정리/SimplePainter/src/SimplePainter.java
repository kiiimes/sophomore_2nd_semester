import javax.swing.JFrame;

public class SimplePainter {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//frame �⺻ ����
		JFrame frame = new JFrame("SIMPLE PAINTER");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		PrimaryPanel primary = new PrimaryPanel();
		frame.getContentPane().add(primary);
		
		//frame �⺻ ����
		frame.pack();
		frame.setVisible(true);		
		
	} // main()

} // SimplePainter class
