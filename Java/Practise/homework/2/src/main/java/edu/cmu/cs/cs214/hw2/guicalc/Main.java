package edu.cmu.cs.cs214.hw2.guicalc;

import java.util.LinkedHashSet;
import java.util.Set;

import edu.cmu.cs.cs214.hw2.operator.AbsoluteValue;
import edu.cmu.cs.cs214.hw2.operator.Addition;
import edu.cmu.cs.cs214.hw2.operator.BinaryOperator;
import edu.cmu.cs.cs214.hw2.operator.Division;
import edu.cmu.cs.cs214.hw2.operator.Exponentiation;
import edu.cmu.cs.cs214.hw2.operator.Multiplication;
import edu.cmu.cs.cs214.hw2.operator.Negation;
import edu.cmu.cs.cs214.hw2.operator.Subtraction;
import edu.cmu.cs.cs214.hw2.operator.UnaryOperator;

/**
 * Main program that runs the GUI Calculator
 */
public class Main {
    public static void main(String[] args) {

        Set<UnaryOperator> unaryOperators = new LinkedHashSet<>();
        UnaryOperator negation = new Negation();
        unaryOperators.add(negation);
        UnaryOperator absolutevalue = new AbsoluteValue();
        unaryOperators.add(absolutevalue);
        
        Set<BinaryOperator> binaryOperators = new LinkedHashSet<>();
        BinaryOperator addition = new Addition();
        binaryOperators.add(addition);
        BinaryOperator subtraction = new Subtraction();
        binaryOperators.add(subtraction);
        BinaryOperator multiplication = new Multiplication();
        binaryOperators.add(multiplication);
        BinaryOperator division = new Division();
        binaryOperators.add(division);
        BinaryOperator exponentiation = new Exponentiation();
        binaryOperators.add(exponentiation);
        

        // Run the calculator!
        new GuiCalculator(unaryOperators, binaryOperators);
    }
}