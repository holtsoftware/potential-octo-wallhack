// Adam Holt
// week 4
// Home Work #2
// This program is spose to look like windows accessories calculater


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.Integer;

public class SwingCalcMain {
    public static void main(String[] args){
        JFrame frame = new SwingCalcFrame();
        frame.addWindowListener(new WindowCloser());
        frame.setVisible(true);
    }
}


class SwingCalcFrame extends JFrame {
    private final int numButtons = 27;
    private final String defaultvalue = "0";
    public SwingCalcFrame(){
        super("A Java Calculator.");
        setSize(320,160);
        int j = 1;
        
        Container pane = getContentPane();

        pane.add(getTextField(),"North");
        setText(defaultvalue);
        getTextField().setHorizontalAlignment(JTextField.RIGHT);
        setButtons();
        setBActions();
        pane.add(setUpButtons(),"Center");

  
    }

    private Container setUpButtons()
    {
        int i,j,k;
        Container bc = new Container();
        GridBagConstraints con = new GridBagConstraints();

        bc.setLayout(new GridBagLayout());
        
        initCon(con,1,1,1,1);
        bc.add(new JTextField(),con);

        initCon(con,2,1,2,1);
        bc.add(calcButton[0],con);

        initCon(con,4,1,2,1);
        bc.add(calcButton[1],con);
 
        initCon(con,6,1,1,1);
        bc.add(calcButton[2],con);
        
        j = 1;
        k = 2;
        for(i = 3;i < numButtons; i++)
        {
            if(j>6)
            {
                j = 1;
                k++;
            }
            initCon(con,j,k,1,1);
            bc.add(calcButton[i],con);
            j++;
        }
        
        return bc;
    }

    /**
       make it so we have less typeing to set up a GridBagConstraints object for adding
       so we can add a componet as we like in a GridBagLayout
     */
    protected void initCon(GridBagConstraints con,int x, int y, int width, int height){
        con.gridx = x;
        con.gridy = y;
        con.gridwidth = width;
        con.gridheight = height;
        con.fill = GridBagConstraints.BOTH;
    }

    private JTextField getTextField()
    {
        return myTextField;
    }
    
    private String getText()
    {
        return myTextField.getText();
    }

    private void addValue(String value)
    {
        if(getText().equals(defaultvalue) || errase == 1)
        {
            errase = 0;
            setText(value);
        }
        else
        {
            setText(getText() + value);
        }
    }

    private void setText(String the_Text)
    {
        myTextField.setText(the_Text);
    }

    private int getivalue()
    {
        return ivalue;
    }

    private void setivalue(int newivalue)
    {
        ivalue = newivalue; 
        setText(Integer.toString(ivalue));
    }

    /**
       das the last command and sets the next command to be executed
       -1 = nocommand
       0 = equal
       1 = +
       2 = -
       3 = *
       4 = /
    */
    private void doncommand(int next)
    {
        errase = 1;
        switch(lastcom){
        case -1:
        case 0:
            setivalue(Integer.valueOf(getText()).intValue());
            break;
        case 1:
            setivalue(getivalue() + Integer.valueOf(getText()).intValue());
            break;
        case 2:
            setivalue(getivalue() - Integer.valueOf(getText()).intValue());
            break;
        case 3:
            setivalue(getivalue() * Integer.valueOf(getText()).intValue());
            break;
        case 4:
            setivalue(getivalue() / Integer.valueOf(getText()).intValue());
            break;
        default:
            System.out.println("Invalid value for command " + lastcom);
        }
        lastcom = next;
    }
    
    /**
        sets up the button with the correct names
     */
    private void setButtons()
    {
        calcButton[0] = new JButton("Backspace");
        calcButton[1] = new JButton("CE");
        calcButton[2] = new JButton("C");
        calcButton[3] = new JButton("MC");
        calcButton[4] = new JButton("7");
        calcButton[5] = new JButton("8");
        calcButton[6] = new JButton("9");
        calcButton[7] = new JButton("/");
        calcButton[8] = new JButton("sqrt");
        calcButton[9] = new JButton("MR");
        calcButton[10] = new JButton("4");
        calcButton[11] = new JButton("5");
        calcButton[12] = new JButton("6");
        calcButton[13] = new JButton("*");
        calcButton[14] = new JButton("%");
        calcButton[15] = new JButton("MS");
        calcButton[16] = new JButton("1");
        calcButton[17] = new JButton("2");
        calcButton[18] = new JButton("3");
        calcButton[19] = new JButton("-");
        calcButton[20] = new JButton("1/x");
        calcButton[21] = new JButton("M+");
        calcButton[22] = new JButton("0");
        calcButton[23] = new JButton("+/-");
        calcButton[24] = new JButton(".");
        calcButton[25] = new JButton("+");
        calcButton[26] = new JButton("=");
    }

    /**
        adds the action listeners to calcbutton
    */
    private void setBActions()
    {
        calcButton[0].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                setText(getText().substring(0,getText().length()-1));
            }
        });

        calcButton[1].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                setText("0");
                setivalue(0);
            }
        });

        calcButton[2].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                setText("0");
            }
        });

        calcButton[4].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[4].getText());
            }
        });
        
        calcButton[5].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[5].getText());
            }
        });

        calcButton[6].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[6].getText());
            }
        });
        
        calcButton[7].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                doncommand(4);
            }
        });

        calcButton[10].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[10].getText());
            }
        });
        
        calcButton[11].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[11].getText());
            }
        });

        calcButton[12].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[12].getText());
            }
        });

        calcButton[13].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                doncommand(3);
            }
        });

        calcButton[16].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[16].getText());
            }
        });

        calcButton[17].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[17].getText());
            }
        });

        calcButton[18].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[18].getText());
            }
        });

        calcButton[19].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                doncommand(2);
            }
        });

        calcButton[22].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                addValue(calcButton[22].getText());
            }
        });

        calcButton[25].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                doncommand(1);
            }
        });

        calcButton[26].addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                doncommand(0);
            }
        });
    }

    private int lastcom = -1, errase = 0;
    private JTextField myTextField = new JTextField();
    private int ivalue = 0;
    private final JButton[] calcButton = new JButton [numButtons];
}
