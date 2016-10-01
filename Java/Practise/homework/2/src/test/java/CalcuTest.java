
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import edu.cmu.cs.cs214.hw2.expression.AbsoluteValueExpression;
import edu.cmu.cs.cs214.hw2.expression.DerivativeExpression;
import edu.cmu.cs.cs214.hw2.expression.DifferenceExpression;
import edu.cmu.cs.cs214.hw2.expression.DivisionExpression;
import edu.cmu.cs.cs214.hw2.expression.ExponentiationExpression;
import edu.cmu.cs.cs214.hw2.expression.Expression;
import edu.cmu.cs.cs214.hw2.expression.NegationExpression;
import edu.cmu.cs.cs214.hw2.expression.NumberExpression;
import edu.cmu.cs.cs214.hw2.expression.ProductExpression;
import edu.cmu.cs.cs214.hw2.expression.SumExpression;
import edu.cmu.cs.cs214.hw2.expression.Variable;
import edu.cmu.cs.cs214.hw2.expression.Zero;

public class CalcuTest {

	private Expression varexp;
	private Variable x = new Variable("x");
	private Expression num2;
	private Expression temp;
	private Expression dfdx;
	private Expression division;
	private Expression negation;
	private Expression absolute;
	private Expression exponent;
	private Expression sum;
	private Expression product;
	private Expression difference;

	/**
	 * called before each test. declare some Expressions
	 */
	@Before
	public void setUp() {
		num2 = new NumberExpression(2);
		temp = new ProductExpression(x, x);
		varexp = new DifferenceExpression(temp, num2);
		dfdx = new DerivativeExpression(varexp, x);
	}

	/**
	 * to test zero method to find the root of x^2-2 using 1 as an initial
	 * approximation and 0.01 as an tolerance
	 */
	@Test
	public void zeroTest() {
		double result = 0;
		result = Zero.zero(varexp, x, 1, 0.00001);
		System.out.println(x);
		assertEquals(result, Math.sqrt(2), 0.00001);
	}

	/**
	 * use several calculations to test + - / * ^ abs neg derivative expressions
	 * who use the operator classes's toString and methods so it can also test
	 * operator classes
	 */
	@Test
	public void expressionText() {
		division = new DivisionExpression(num2, num2);
		negation = new NegationExpression(division);
		absolute = new AbsoluteValueExpression(negation);
		exponent = new ExponentiationExpression(num2, absolute);
		sum = new SumExpression(exponent, num2);
		product = new ProductExpression(sum, num2);
		difference = new DifferenceExpression(product, num2);
		assertEquals(difference.eval(), 6, 0);
		assertEquals(num2.toString(), "2.0");
		assertEquals(division.toString(), "(2.0)/(2.0)");
		assertEquals(negation.toString(), "neg(1.0)");
		assertEquals(absolute.toString(), "abs(-1.0)");
		assertEquals(exponent.toString(), "(2.0)^(1.0)");
		assertEquals(sum.toString(), "(2.0)+(2.0)");
		assertEquals(product.toString(), "(4.0)*(2.0)");
		assertEquals(difference.toString(), "(8.0)-(2.0)");
		assertEquals(dfdx.toString(), "df/dx");
	}

}