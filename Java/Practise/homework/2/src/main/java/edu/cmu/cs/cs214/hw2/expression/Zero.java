package edu.cmu.cs.cs214.hw2.expression;

/**
 *
 * This Zero class is for the static method, it will not be instantiated,
 * so the "public class Zero{}" sentence will not be covered in the test.
 * 
 * @author Landy
 *
 */
public class Zero {
/**
 * zero method is for finding a root for a variable expression.
 * it uses Newton's Method which works for many expression but not all
 * @param fn the function whose zero is to be found
 * @param x the independent variable of the function
 * @param approxZero initial approximation for the zero of the function
 * @param tolerance how close to zero f(the return value) has to be
 * @return a value x for which f(x) is close to zero (<= tolerance)
 */
	public static double zero(Expression fn, Variable x,double approxZero, double tolerance) {
		double temp = 0;
		Expression dfndx = new DerivativeExpression(fn,x);
		x.store(approxZero);
		do {
			temp = x.eval() - fn.eval() / dfndx.eval();
			x.store(temp);
		} while (Math.abs(fn.eval()) > tolerance);
		return x.eval();
		
	}
	
}
