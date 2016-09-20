package edu.cmu.cs.cs214.hw2.expression;

/**
 * An implement of expression to represent a number.
 * @author Landy
 *
 */
public class NumberExpression implements Expression {
	private double arg;
	
	/**
	 * Creates an expression representing a number.
	 * @param passinnum the number being expressed
	 */
	public NumberExpression(double passinnum){
		this.arg=passinnum;
	}

	/**
	 * return the value of the number
	 */
	@Override
	public double eval() {
		return arg;
	}
	@Override
	public String toString(){
		return Double.toString(arg);
	}

}
