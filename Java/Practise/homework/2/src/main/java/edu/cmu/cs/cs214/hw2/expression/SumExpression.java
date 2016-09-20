package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.Addition;
import edu.cmu.cs.cs214.hw2.operator.BinaryOperator;

/**
 * An implement of expression to calculate sum.
 * @author Landy
 *
 */
public class SumExpression implements Expression {

	private Expression arg1, arg2;
	private double result;
	private BinaryOperator op = new Addition();
	
	/**
	 * Creates an expression representing the sum of two specified expression
	 * @param passinnum1 the first expression to be added
	 * @param passinnum2 the second expression to be added
	 */
	public SumExpression(Expression passinnum1, Expression passinnum2){
		this.arg1=passinnum1;
		this.arg2=passinnum2;
	}
	
	/**
	 * a method returns the sum in double
	 */
	@Override
	public double eval() {
		result=op.apply(arg1.eval(), arg2.eval());
		return result;
	}
	@Override
	public String toString(){
		return "("+arg1.eval()+")"+op.toString()+"("+arg2.eval()+")";
	}
}
