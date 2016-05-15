// Adam Holt
// week 4
// Home Work #3
// a simple program that just add the number of times that a button is pushed and shows it on a lable

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.Integer;

public class SwingGULMain {
    public static void main(String[] args){
        JFrame frame = new SwingPushFrame();
        frame.addWindowListener(new WindowCloser());
        frame.setVisible(true);
    }
}

class SwingPushFrame extends JFrame{
    public SwingPushFrame()
    {
        setSize(200,100);
        Container con = getContentPane();

        final JLabel labe = new JLabel("0");
        labe.setHorizontalTextPosition(JLabel.CENTER);
        JButton but = new JButton("add 1");

        but.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                labe.setText( Integer.toString(
                              Integer.decode(labe.getText()).intValue() + 1));
            }
        });
 
        con.add(labe,"North");
        con.add(but,"South");
    }

}
