/*************************************************************************
	> File Name: test.java
	> Author: Riho.Yoshioka
	> Mail:   riho.yoshioka@yandex.com
	> Created Time: Sun 10 Jul 2016 05:21:29 PM CST
*************************************************************************/

import java.io.*;

class Dog {
  private String name;
  private int size;
  public String GetName() {
    return name;
  }
  public int GetSize() {
    return size;
  }
  public void SetName(String str) {
    name = str;
  }
}

public class test {
  public static void main (String[] args) {
    Dog dog = new Dog();
    int [] array = new int[10];
    System.out.println("Array's size is " + array.length);
    array[0] = 0;
    System.out.println("Array's size is " + array.length);
    System.out.println("Dog size is " + dog.GetSize());
    System.out.println("Dog name is " + dog.GetName());
    dog.SetName("null");
    System.out.println("Dog name is " + dog.GetName());
  }
}

