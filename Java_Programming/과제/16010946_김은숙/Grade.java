package midterm;

public class Grade {
	private int data,totalHour,totalScore;
	private String name;
	public static final int MIN=3,MAX=21;
	
	public Grade() {
	
	}

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public int getTotalHour() {
		
		return totalHour;
	}

	public int getTotalScore() {
		return totalScore;
	}

	public void setTotalScore(int totalScore) {
		if(totalScore<0||totalScore>99) {
			this.totalScore=-1;
		}
		else {
			this.totalScore = totalScore;
		}
	}

	public void setTotalHour(int totalHour) {
		if(totalScore<MIN||totalScore>MAX) {
			this.totalHour=-1;
		}
		else {
			this.totalHour = totalHour;
		}
		
		
		
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public String calcGrade() {
		if(totalScore>=90&&totalScore<=100) {
			return "A";
		}
	else if(totalScore>=80&&totalScore<=89) {
		return "B";
	}
	else if(totalScore>=70&&totalScore<=79) {
		return "C";
	}
	else if(totalScore>=60&&totalScore<=69) {
		return "D";
	}
	else {
		return "F";
	}
		
}
//	public boolean isEqualGrade(Grade student) {
//		String sav;
//		sav=calcGrade();
//		if(sav=="A") {
//			
//		}
//		
//	}
//	
//	public int compareScore(Grade student) {
//		
//	}
	
	public static int compareScore(Grade student1,Grade student2) {
		if(student1.totalScore>student2.totalScore) {
			return -1;
		}
		else if(student1.totalScore>student2.totalScore) {
			return 0;
		}
		else {
			return 1;
		}
		
	}
	
	public String toString(Grade student1) {
		return "student";
	}
	
	
	
	
}
