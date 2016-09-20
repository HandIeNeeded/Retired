package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.BinaryOperator;
import edu.cmu.cs.cs214.hw2.operator.Exponentiation;

/**
 * An implement of expression to calculate exponentiation.
 * @author Landy
 *
 */
public class ExponentiationExpression implements Expression {

	private Expression arg1, arg2;
	private double result;
	private BinaryOperator op = new Exponentiation();
	
	/**
	 * Creates an expression representing the exponential of two expressions
	 * @param passinnum1 the base expression
	 * @param passinnum2 the exponential expression
	 */
	public ExponentiationExpression(Expression passinnum1, Expression passinnum2) {
		this.arg1=passinnum1;
		this.arg2=passinnum2;
	}
	
	/**
	 *  return the exponential operation's result in double
	 */
	@Override
	public double eval() {
		result = op.apply(arg1.eval(), arg2.eval());
		return result;
	}
	@Override
	public String toString(){
		return "("+arg1.eval()+")"+op.toString()+"("+arg2.eval()+")";
	}

}
