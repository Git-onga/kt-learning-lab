/*
//INHERITANCE  - MULTIPLE
class creation program
public class Addition{
    public int add(int a, int b){
        return a + b;
    }
    public static void main(String[] args){
        Addition addition = new Addition();
        int results = addition.add(5,7);
        System.out.println("Sum: " + results);
    }
}


 // POLYMORPHISM  -(Runtime / overriding)
class Shape{
    public void draw(){
        System.out.println("Drawing a shape ...");
    }
}

class Circle extends Shape{
    @Override
    public void draw(){
        System.out.println("Drawing a circle ...");
    }
}

class Rectangle extends Shape{
    @Override
    public void draw(){
        System.out.println("Drawing a Rectangle ...");
    }
}
public class Addition {
    public static void main(String[] args){
        Shape shape = new Shape();
        shape.draw();

        Shape circle = new Circle();
        circle.draw();

        Shape rectangle = new Rectangle();
        rectangle.draw();
    }
}


class MathOperations{
    public int add(int a, int b){
        return a+b;
    }

    public int add(int a, int b, int c){
        return a+b+c;
    }

    public double add(double a, double b){
        return a+b;
    }

}

public class Addition {
    public static void main(String[] args){
        MathOperations mathOperations = new MathOperations();

        System.out.println("Sum (int a + int b: " + mathOperations.add(5,2));
        System.out.println("Sum (int a + int b + int c: " + mathOperations.add(2,6,8));
        System.out.println("Sum (double a + double b: " + mathOperations.add(5.435,2.123));

    }
}


 */

import javax.swing.*;
import java.awt.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
import javax.swing.*;

class GUIExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Sample Interface");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Components
        JLabel label = new JLabel("Enter your name:");
        JTextField textField = new JTextField(15);
        JButton button = new JButton("Submit");

        // Panel to hold components
        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(textField);
        panel.add(button);

        frame.add(panel);
        frame.setVisible(true); // Display the frame
    }
}
/*public class Main {
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        for (int i = 1; i <= 5; i++) {
            //TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint
            // for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
            System.out.println("i = " + i);
        }
    }
}
public class Addition{
    public static void main(String[] args){
        JFrame frame = new JFrame("Tip Calculator");
        frame.setSize(350,100);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        /*
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(1,4,5,5));
        */
/*
        JLabel label1 = new JLabel("bill:");
        JTextField txt1 = new JTextField();

        JLabel label2 = new JLabel("suggested tip:");
        JTextField txt2 = new JTextField(10);

        frame.add(label1);
        frame.add(txt1);
        frame.add(label2);
        frame.add(txt2);

        //frame.add(panel, BorderLayout.CENTER);
        frame.setVisible(true);
    }
}
*/