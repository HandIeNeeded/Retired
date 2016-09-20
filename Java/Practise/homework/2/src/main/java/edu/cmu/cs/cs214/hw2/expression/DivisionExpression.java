package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.BinaryOperator;
import edu.cmu.cs.cs214.hw2.operator.Division;

/**
 * An implement of expression to calculate division.
 * @author Landy
 *
 */
public class DivisionExpression implements Expression {
	private Expression arg1,arg2;
	private double result;
	private BinaryOperator op = new Division();
	
	/**
	 * Creates an expression representing two expressions' division operating
	 * @param passinnum1 the expression from which division operates
	 * @param passinnum2 the expression representing dividend
	 */
	public DivisionExpression(Expression passinnum1, Expression passinnum2){
		this.arg1=passinnum1;
		this.arg2=passinnum2;
	}

	/**
	 *  a method return a double result of division
	 */
	@Override
	public double eval() {
		result= op.apply(arg1.eval(), arg2.eval());
		return result;
	}
	@Override
	public String toString(){
		return "("+arg1.eval()+")"+op.toString()+"("+arg2.eval()+")";
	}

}
