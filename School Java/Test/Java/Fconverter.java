/*
 * Fconverter.java
 *
 * Created on December 2, 2001, 4:28 PM
 */
import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
/**
 *
 * @author  Adam Holt
 * @version 
 */
public class Fconverter extends Applet implements ActionListener
{
    private int APPLET_WIDTH = 200;
    private int APPLET_HEIGHT = 100;
    
    private Label inputLabel, outputLabel, resultLabel;
    private TextField fahrenheit;
    
    /** Creates new Fconverter */
    public Fconverter() 
    {
    }
    
    public void init()
    {
        inputLabel = new Label ("Enter Fahrenheit:");
        outputLabel = new Label ("Temperature in Celsius:");
        resultLabel = new Label ("N/A");
        
        fahrenheit = new TextField (5);
        fahrenheit.addActionListener(this);
        
        add(inputLabel);
        add(fahrenheit);
        add(outputLabel);
        add(resultLabel);
        
        setBackground(Color.white);
        setSize(APPLET_WIDTH, APPLET_HEIGHT);
    }
    
    public void actionPerformed (ActionEvent event)
    {
        int FahrenheitTemp, celsiusTemp;
        
        String text = fahrenheit.getText();
        
        FahrenheitTemp = Integer.parseInt(text);
        celsiusTemp = (FahrenheitTemp - 32) * 5/9;
        
        resultLabel.setText (Integer.toString(celsiusTemp));
    }
}
