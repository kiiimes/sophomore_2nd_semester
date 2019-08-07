import javax.swing.JFrame;

public class MouseDraw {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		JFrame frame = new JFrame("MOUSE DRAW EXAMPLE");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//DrawPanel draw = new DrawPanel();
		LinePanel draw = new LinePanel();
		frame.getContentPane().add(draw);
		
		frame.pack();
		frame.setVisible(true);
		
	} // main()

} // MouseDraw class
