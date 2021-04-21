
public class Virus {
	private double infectRate;
	private double deathRate;
	private double recoverRate;
	private int killTime;
	private int recoverTime;
	private String name;
	
	public Virus(String n, double ir, double dr, int killTime, double rr, int recoverTime) {
		name = n;
		setInfectRate(ir);
		setDeathRate(dr);
		setKillTime(killTime);
		setRecoverRate(rr);
		setRecoverTime(recoverTime);
	} // end constructor Virus
	
	public String getName() {
		return name;
	} // end getDeathRate
	
	public double getInfectRate() {
		return infectRate;
	} // end getInfectRate
	
	public double getDeathRate() {
		return deathRate;
	} // end getDeathRate
	
	public int getKillTime() {
		return killTime;
	} // end getKillTime
	
	public int getRecoverTime() {
		return recoverTime;
	}// end getRecoverTime
	
	public double getRecoverRate() {
		return recoverRate;
	}

	public void setInfectRate(double value) {
		if (value < 0)
			throw new IllegalArgumentException("Infect rate must be 0 or positive.");
		infectRate = value;
	} // end setInfectedRate
	
	public void setDeathRate(double value) {
		if (value < 0)
			throw new IllegalArgumentException("Death rate must be 0 or positive.");
		deathRate = value;
	} // end setInfectedRate
	
	public void setKillTime(int value) {
		if (value < 0)
			throw new IllegalArgumentException("killTime must be at least 0.");
		killTime = value;
	} // end setInfectedRate
	
	public void setRecoverTime(int value) {
		if (value < 0)
			throw new IllegalArgumentException("recoverTime must be at least 0.");
		recoverTime = value;
	} // end setRecoverTime
	
	
	public void setRecoverRate(double value) {
		if (value < 0)
			throw new IllegalArgumentException("recoverTime must be at least 0.");
		recoverRate = value;
	} // end setInfectedRate
	
	
} // end Virus

