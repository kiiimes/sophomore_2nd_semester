package midterm;
import java.awt.*;
import javax.swing.*;
import java.util.*;


public class GradeExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Grade g1,g2;
		g1=new Grade();
		g2=new Grade();
		
		String name1,name2;
		
		Scanner scan=new Scanner(System.in);
		
		name1=scan.next();
		name2=scan.next();
		
		//이름입력
		g1.setName(name1);
		g2.setName(name2);
		
		g1.setTotalHour((int)(Math.random()*100+1));
		g2.setTotalHour((int)(Math.random()*100+1));
		
		g1.setTotalScore((int)(Math.random()*100+1));
		g2.setTotalScore((int)(Math.random()*100+1));
		
		
		
		JFrame frame= new JFrame("MIDTERM EXAM");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel primary=new JPanel();
		primary.setPreferredSize(new Dimension(500,500));
		
		
		
		JPanel lbl1,lbl2,lbl3,lbl4,lbl5;
		lbl1= new JPanel();
		lbl1.setBackground(Color.cyan);
		lbl2= new JPanel();
		lbl2.setBackground(Color.pink);
		lbl3= new JPanel();
		lbl3.setBackground(Color.yellow);
		lbl4= new JPanel();
		lbl4.setBackground(Color.green);
		lbl5= new JPanel();
		lbl5.setBackground(Color.gray);
		
		lbl1.setPreferredSize(new Dimension(100,500));
		lbl2.setPreferredSize(new Dimension(100,500));
		lbl3.setPreferredSize(new Dimension(100,500));
		lbl4.setPreferredSize(new Dimension(100,500));
		lbl5.setPreferredSize(new Dimension(100,500));
		
		primary.add(lbl1);
		primary.add(lbl2);
		primary.add(lbl3);
		primary.add(lbl4);
		primary.add(lbl5);
		
		JLabel l1,l2,l3,l4,l5;
		l1=new JLabel("A");
		l2=new JLabel("B");
		l3=new JLabel("C");
		l4=new JLabel("D");
		l5=new JLabel("E");
		
		lbl1.add(l1);
		lbl2.add(l2);
		lbl3.add(l3);
		lbl4.add(l4);
		lbl5.add(l5);
		
		
		if("A"==g1.calcGrade()) {
			JLabel s1= new JLabel(g1.getName()+">>" + g1.getTotalScore());
			lbl1.add(s1);
		}
		if("B"==g1.calcGrade()) {
			JLabel s1= new JLabel(g1.getName()+">>" + g1.getTotalScore());
			lbl2.add(s1);
		}
		if("C"==g1.calcGrade()) {
			JLabel s1= new JLabel(g1.getName()+">>" + g1.getTotalScore());
			lbl3.add(s1);
		}
		if("D"==g1.calcGrade()) {
			JLabel s1= new JLabel(g1.getName()+">>" + g1.getTotalScore());
			lbl4.add(s1);
		}
		if("F"==g1.calcGrade()) {
			JLabel s1= new JLabel(g1.getName()+">>" + g1.getTotalScore());
			lbl5.add(s1);
		}
		
		
		if("A"==g2.calcGrade()) {
			JLabel s2= new JLabel(g2.getName()+">>" + g2.getTotalScore());
			lbl1.add(s2);
		}
		if("B"==g2.calcGrade()) {
			JLabel s2= new JLabel(g2.getName()+">>" + g2.getTotalScore());
			lbl2.add(s2);
		}
		if("C"==g2.calcGrade()) {
			JLabel s2= new JLabel(g2.getName()+">>" + g2.getTotalScore());
			lbl3.add(s2);
		}
		if("D"==g2.calcGrade()) {
			JLabel s2= new JLabel(g2.getName()+">>" + g2.getTotalScore());
			lbl4.add(s2);
		}
		if("F"==g2.calcGrade()) {
			JLabel s2= new JLabel(g2.getName()+">>" + g2.getTotalScore());
			lbl5.add(s2);
		}
	
	if(g1.calcGrade()==g2.calcGrade()) {
		if(g1.compareScore(g1,g2)==-1) {
			JLabel s3= new JLabel(g1.getName()+">"+g1.getName());
			if(g1.calcGrade()=="A") {
				lbl1.add(s3);
			}
			if(g1.calcGrade()=="B") {
				lbl2.add(s3);
			}
			if(g1.calcGrade()=="C") {
				lbl3.add(s3);
			}
			if(g1.calcGrade()=="D") {
				lbl4.add(s3);
			}
			if(g1.calcGrade()=="E") {
				lbl5.add(s3);
			}
			
		}
		
		
		
	}
	
		
		
		
		
		
		
		
		
		frame.getContentPane().add(primary);
		frame.pack();
		frame.setVisible(true);
		
	}

}
