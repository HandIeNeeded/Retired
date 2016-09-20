package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.AbsoluteValue;
import edu.cmu.cs.cs214.hw2.operator.UnaryOperator;

/**
 * An implement of Expression to calculate absolute value.
 * @author Landy
 *
 */
public class AbsoluteValueExpression implements Expression {
	private Expression arg;
	private UnaryOperator op = new AbsoluteValue();
	private double result;
	
	/**
	 * Creates an expression representing another expression's absolute value.
	 * @param passinnum the expression this class is going to calculate result with
	 */
	public AbsoluteValueExpression(Expression passinnum) {
		this.arg = passinnum;
	}

	@Override
	/**
	 *  a method return the absolute value of a expression
	 */
	public double eval() {
		result = op.apply(arg.eval());
		return result;
	}
	
	@Override
	public String toString() {
		return op.toString() + "("+arg.eval() + ")";
	}

}
