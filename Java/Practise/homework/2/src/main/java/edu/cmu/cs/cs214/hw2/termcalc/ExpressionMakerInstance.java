package edu.cmu.cs.cs214.hw2.termcalc;

import edu.cmu.cs.cs214.hw2.expression.AbsoluteValueExpression;
import edu.cmu.cs.cs214.hw2.expression.DifferenceExpression;
import edu.cmu.cs.cs214.hw2.expression.DivisionExpression;
import edu.cmu.cs.cs214.hw2.expression.ExponentiationExpression;
import edu.cmu.cs.cs214.hw2.expression.Expression;
import edu.cmu.cs.cs214.hw2.expression.NegationExpression;
import edu.cmu.cs.cs214.hw2.expression.NumberExpression;
import edu.cmu.cs.cs214.hw2.expression.ProductExpression;
import edu.cmu.cs.cs214.hw2.expression.SumExpression;

/**
 * Instantiate the ExpressionMaker to use the wrote Expressions 
 * and pass the results to the TA's codes to realize the expression calculation function 
 * @author Landy
 *
 */
public class ExpressionMakerInstance implements ExpressionMaker {

	@Override
	public Expression sumExpression(Expression addend1, Expression addend2) {
		Expression sum=new SumExpression(addend1, addend2);
		return sum;
	}

	@Override
	public Expression differenceExpression(Expression op1, Expression op2) {
		Expression diff = new DifferenceExpression(op1, op2);
		return diff;
	}

	@Override
	public Expression productExpression(Expression factor1, Expression factor2) {
		Expression product = new ProductExpression(factor1,factor2);
		return product;
	}

	@Override
	public Expression divisionExpression(Expression dividend, Expression divisor) {
		Expression division = new DivisionExpression(dividend,divisor);
		return division;
	}

	@Override
	public Expression exponentiationExpression(Expression base, Expression exponent) {
		Expression expon = new ExponentiationExpression(base,exponent);
		return expon;
	}

	@Override
	public Expression negationExpression(Expression operand) {
		Expression neg = new NegationExpression(operand);
		return neg;
	}

	@Override
	public Expression absoluteValueExpression(Expression value) {
		Expression abs = new AbsoluteValueExpression(value);
		return abs;
	}

	@Override
	public Expression numberExpression(double value) {
		Expression val = new NumberExpression(value);
		return val;
	}

}
