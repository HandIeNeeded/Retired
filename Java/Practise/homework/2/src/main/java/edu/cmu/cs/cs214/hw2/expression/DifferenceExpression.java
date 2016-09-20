package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.BinaryOperator;
import edu.cmu.cs.cs214.hw2.operator.Subtraction;

/**
 * An implement of expression to calculate difference.
 * @author Landy
 *
 */
public class DifferenceExpression implements Expression {
	private Expression arg1, arg2;
	private double result;
	private BinaryOperator op = new Subtraction();

        /**
         * Creates an expression representing the difference of two 
         * specified expressions.
         * @param passinnum1 the expression from which subtraction operates
         * @param passinnum2 the expression being subtracted
         */
	public DifferenceExpression(Expression passinnum1, Expression passinnum2){
		this.arg1=passinnum1;
		this.arg2=passinnum2;
	}
	
	/**
	 *  a method to return the result of subtraction
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
