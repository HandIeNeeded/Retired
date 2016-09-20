package edu.cmu.cs.cs214.hw2.expression;

/**
 * An implement of expression to calculate derivative.
 * @author Landy
 *
 */
public class DerivativeExpression implements Expression {

	private double DELTA_X = 1e-9;
	private Expression fn;
	private Variable independentVar;
	
	/**
	 * Creates an expression representing the derivative of the specified 
	 * function with respect to the specified variable
	 * @param fn the function whose derivative this expression represents
	 * @param independentVar the variable with respect to which we are differentiating
	 */
	public DerivativeExpression(Expression fn, Variable independentVar){
		this.fn=fn;
		this.independentVar=independentVar;
	}
	
	/**
	 *  a method to return the derivative value of a function
	 */
	@Override
	public double eval() {
		double temp=fn.eval();
		independentVar.store(independentVar.eval()+DELTA_X);
		temp=fn.eval()-temp;
		return temp/DELTA_X;
	}
	@Override
	public String toString(){
		return "df/d"+independentVar.name();
	}

}
