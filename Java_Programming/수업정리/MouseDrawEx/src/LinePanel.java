import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class LinePanel extends JPanel {

	private Point ptOne, ptTwo;
	private JTextField txtSize;
	private int nSize;
	// 2.
	private LineListener lineL;
	
	public LinePanel() {
		setPreferredSize(new Dimension(400,400));
		setBackground(Color.white);
		
		// 2.
		lineL = new LineListener();
		// 3.
		addMouseListener(lineL);
		addMouseMotionListener(lineL);
		
		ptOne = new Point();
		ptTwo = new Point();
		
		nSize = 1;
		txtSize = new JTextField(6);
		txtSize.setText(Integer.toString(nSize));
		add(txtSize);
		
	} // LinePanel()
	
	public void paintComponent(Graphics page) {
		super.paintComponent(page);
		
		Graphics2D page2 = (Graphics2D)page;
		page2.setStroke(new BasicStroke(nSize));
				
		page.drawLine(ptOne.x, ptOne.y, ptTwo.x, ptTwo.y);
		
	} // paintComponent()
	
	// 1.
	private class LineListener implements 	MouseListener, 
											MouseMotionListener
	{
		public void mouseClicked(MouseEvent event) {}
		
		public void mousePressed(MouseEvent event) {
			ptOne = event.getPoint();
			nSize = Integer.parseInt(txtSize.getText());
		} // mousePressed()
		
		public void mouseReleased(MouseEvent event) {
			ptTwo = event.getPoint();
			repaint();
		} // mouseReleased()
		
		public void mouseEntered(MouseEvent event) {}
		public void mouseExited(MouseEvent event) {}
		
		public void mouseMoved(MouseEvent event) {}
		
		public void mouseDragged(MouseEvent event) {
			ptTwo = event.getPoint();
			repaint();
		} // mouseDragged()
		
	} // LineListener class
	
	
} // LinePanel class
