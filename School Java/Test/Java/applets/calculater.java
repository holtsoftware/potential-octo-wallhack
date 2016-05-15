/*
 * calculater.java
 *
 * Created on December 2, 2001, 11:12 PM
 */

import java.awt.*;
import java.awt.event.*;

/**
 *
 * @author  Adam Holt
 * @version 
 */
public class calculater extends java.applet.Applet implements ActionListener
{
    private TextField results;
    private Button[] buttons;

    /** Initialization method that will be called after the applet is loaded
     *  into the browser.
     */
    public void init () 
    {
        results = new TextField();
        results.setColumns(10);
        buttons = new Button[12];
        
        for(int t=0;t<12;t++)
        {
            buttons[t] = new Button();
        }
        
        for(int i=0;i<12;i++)
        {
            switch(i)
            {
                case 9:
                    buttons[i].setLabel("  *  ");
                    buttons[i].addActionListener(this);
                    break;
                case 10:
                    buttons[i].setLabel("  0  ");
                    buttons[i].addActionListener(this);
                    break;
                case 11:
                    buttons[i].setLabel("  #  ");
                    buttons[i].addActionListener(this);
                    break;
                default:
                    buttons[i].setLabel("  " + (i+1) + "  ");
                    buttons[i].addActionListener(this);
            }
        }
        
        add(results);
        for(int k=0;k<12;k++)
        {
            this.add(buttons[k]);
        }
        setSize(100,150);
    }
    
    public void actionPerformed(ActionEvent event)
    {
        results.setText(results.getText() + ((Button)event.getSource()).getLabel().trim());
    }

}
