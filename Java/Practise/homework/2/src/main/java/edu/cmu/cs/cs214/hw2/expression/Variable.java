package edu.cmu.cs.cs214.hw2.expression;

/**
 * An expression that represents a variable. Its value may be set as well as read.
 * Unlike other expressions in this assignment, variables are mutable. Using a variable
 * within a containing expression makes the expression a function of the current value of 
 * the variable.
 *
 * <p>Variables have immutable string names, which are used in their string representations. If an 
 * expression contains multiple distinct variables as subexpressions, it's important that they 
 * have different names, or the string representation of the containing expression will be 
 * misleading.
 */
public class Variable implements Expression {
        /**
         * Constructs a variable with the specified name, whose initial value is zero.
         */
	private String name;
	private double result = 0;
	
        /**
         * Creates an expression representing a variable
         * @param name the string name of the variable
         */
        public Variable(String name) {
            this.name=name;
        }
         /**
          * return the value of the variable
          */
        @Override
        public double eval() {
            return result;
        }
        /**
         * override the toString method so the output will in format like "variable.name = value"
         */
        @Override
        public String toString() { 
            return name()+"="+ result;
        }

        /**
         * Sets the value of this variable.
         *
         * @param value the new value of this variable
         */
        public void store(double value) {
	    result=value;
        }

        /**
         * Returns the name of this variable
         * @return the name of this variable
         */
        public String name() { 
            return name;
        }
}

