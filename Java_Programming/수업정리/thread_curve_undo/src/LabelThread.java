import java.awt.*;
import javax.swing.*;

public class LabelThread extends JLabel implements Runnable{
	private Color FontColor;
	private Thread FontThread;
	
	public LabelThread() {
		FontColor = Color.black;
		FontThread = null;
	}
	public LabelThread(String str) {
		super(str);
		FontColor = Color.BLACK;
		FontThread = null;
	}
	public void setThread(Thread t) {
		FontThread = t;
	}
	public void start() {
		if (FontThread == null) {
			FontThread = new Thread(this);
			FontThread.start();
		}
	}
	public void stop() {
		if (FontThread != null) {
			FontThread.stop();
			FontThread = null;
		}
	}
	public void run() {
		try {
			for (int i = 0; i<4; i++) {
				FontColor = new Color(30*i*2,123,200-(i*30));
				
				setForeground(FontColor);
				setVisible(false);
				FontThread.sleep(100);
				setVisible(true);
				FontThread.sleep(100);
			}
		} catch(Exception e) {}
	}

}
