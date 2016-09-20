package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.BinaryOperator;
import edu.cmu.cs.cs214.hw2.operator.Multiplication;

/**
 * An implement of expression to calculate product.
 * @author Landy
 *
 */
public class ProductExpression implements Expression {
	private Expression arg1, arg2;
	private double result;
	private BinaryOperator op = new Multiplication();
	
	/**
	 * Creates an expression representing the product of two specified expression
	 * @param passinnum1 the first multiplier
	 * @param passinnum2 the second multiplier
	 */
	public ProductExpression(Expression passinnum1, Expression passinnum2) {
		this.arg1=passinnum1;
		this.arg2=passinnum2;
	}
	
	/**
	 * a method return the product in double
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
