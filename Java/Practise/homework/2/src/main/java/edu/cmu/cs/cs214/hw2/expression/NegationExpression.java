package edu.cmu.cs.cs214.hw2.expression;

import edu.cmu.cs.cs214.hw2.operator.Negation;
import edu.cmu.cs.cs214.hw2.operator.UnaryOperator;

/**
 * An implement of expression to calculate negation.
 * @author Landy
 *
 */
public class NegationExpression implements Expression {

	private Expression arg;
	private double result;
	private UnaryOperator op = new Negation();
	
	/**
	 * Creates an expression representing the negation of another specified expression
	 * @param passinnum the expression being negated
	 */
	public NegationExpression(Expression passinnum){
		this.arg=passinnum;
	}
	
	/**
	 * returns the negation value in double
	 */
	@Override
	public double eval() {
		result = op.apply(arg.eval());
		return result;
	}
	@Override
	public String toString(){
		return op.toString()+"("+arg.eval()+")";
	}

}
