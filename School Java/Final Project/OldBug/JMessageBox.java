/*
 * JMessageBox.java
 *
 * Created on June 11, 2002, 5:58 PM
 */
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
/**
 *
 * @author  adam
 * @version 
 */
public class JMessageBox {

    /** Creates new JMessageBox */
    public JMessageBox() {
    }
    
    static public void Message(String s){
        MBox m = new MBox(s);
        m.show();
        
    }

}

class MBox extends JDialog{
    public MBox(String s){
        setSize(200,100);
        Container con = getContentPane();
        JLabel lb = new JLabel(s);
        con.add(lb,"Center");
        JButton bt = new JButton("Ok");
        bt.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                hide();
                dispose();
            }
        });
        con.add(bt,"South");
    }
}
