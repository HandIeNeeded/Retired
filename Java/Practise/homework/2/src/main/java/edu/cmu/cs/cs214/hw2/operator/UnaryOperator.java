package edu.cmu.cs.cs214.hw2.operator;

/** 
 * UnaryOperator - an arithmetic operator with a single operand.
 *
 */
public interface UnaryOperator extends Operator {
	/**
	 * Applies the Operator on the number given.
	 * 
	 * @param arg a number to apply the operator on
	 * @return the number outputted by the operation given input arg
	 */
	double apply(double arg);
}
//
//public class Negation implements UnaryOperator {
//	//constructor
////        double argument;
////	public Negation(double arg){
////		this.argument = arg;
////	}
//
//	@Override
//	public double apply(double arg) {
//		double result = - arg;
//		return result;
//	}
//	@Override
//	public String toString(){
//		return "-";
//	};
//	
//}
//
//
//class AbsoluteValue implements UnaryOperator {
//
//	@Override
//	public double apply(double arg) {
//		double result = Math.abs(arg);
//		return result;
//	}
//	@Override
//	public String toString(){
//		return "abs";
//	};
//	
//}
//
//
