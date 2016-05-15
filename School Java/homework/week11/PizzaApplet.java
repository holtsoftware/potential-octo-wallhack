// Adam Holt
// week 11
// Pizza ordering service

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Double;

public class PizzaApplet extends JApplet {
    final String[] PSIZES = {"Small","Medium","Large"};
    final double[] PPRICE = {1.33,1.85,2.05};
    final double PTOPINGS = 0.51, MAX_PIZZAS = 15;
    final String[] TOPINGS = {"Extra Cheese","Pepperoni","Sausage","Mushrooms","Italian Sausage",
                              "Ham","Ground Beef","Bacon","Onions","Green Peppers","Black Olives",
                              "Pineapple","Banana Peppers","Jalapeno Peppers","Anchovies"};

    public void init(){
        final Container con = getContentPane();

        con.setLayout(new BorderLayout());

        con.add(new JLabel("Holt-softwares pizza ordering system.",JLabel.CENTER),"North");

        con.add(setUpPizza(),"Center");
        con.add(getText(),"South");
    }

    private Container setUpPizza(){
        Container con = new Container();

        con.setLayout(new BorderLayout());
     
        con.add(setUpNorth(),"North");
        con.add(setUpTopings(),"Center");
        getText().setEditable(false);
        con.add(new JLabel("Total",JLabel.LEFT),"South");
        return con;
    }

    private Container setUpTopings(){
        Container con = new Container();
        
        con.setLayout(new GridLayout((TOPINGS.length/2)+1,2));
       
        for(int i = 0;i < TOPINGS.length; i++)
        {
            JCheckBox cbox = new JCheckBox(TOPINGS[i]);
            con.add(cbox);
            cbox.addItemListener(new ItemListener(){
                public void itemStateChanged(ItemEvent e){
                    int change = e.getStateChange();
                    if(change == ItemEvent.SELECTED){
                        changeTValue(lastNC,NTS,lastNC,++NTS);
                    }
                    else{
                        changeTValue(lastNC,NTS,lastNC,--NTS);
                    }
                }
            });
        }
        return con;
    }

    private Container setUpNorth(){
        final JComboBox box = getBox(), NBox = new JComboBox(new DefaultComboBoxModel());
        final DefaultComboBoxModel model = (DefaultComboBoxModel) box.getModel(),
              model2 = (DefaultComboBoxModel) NBox.getModel();

        Container con = new Container();
        con.setLayout(new BorderLayout());
        con.add(NBox,"West");
        con.add(box,"Center");

        for(int i = 0; i < PSIZES.length; i++)
        {
            model.addElement(PSIZES[i] + " $" + PPRICE[i]);
            box.addItemListener(new ItemListener(){
                public void itemStateChanged(ItemEvent e){
                    int index = box.getSelectedIndex();
                    changeValue(lastNC,PPRICE[lastSize],lastNC,PPRICE[index]);	
                    lastSize = index;
                }
            });
        }

        for(int j = 0;j < MAX_PIZZAS;j++)
        {
            model2.addElement((j +1)+"");
            NBox.addItemListener(new ItemListener(){
                public void itemStateChanged(ItemEvent e){
                    int index = NBox.getSelectedIndex();
                    changeValue(lastNC ,PPRICE[lastSize],index,PPRICE[lastSize]);
                    changeTValue(lastNC,NTS,index,NTS);
                    lastNC = index;
                }
            });
        }

        return con;
    }

    /**
       minuses(Onum * Oprice) from the JTextField total then 
       addes(Nnum * Nprice) to the JTextField total
    */
    private void changeValue(int Onum,double Oprice,int Nnum,double Nprice)
    {
        double strv;
        Onum++;
        Nnum++;
        strv = Double.valueOf(getText().getText()).doubleValue();
        strv -= Onum * Oprice;
        strv += Nnum * Nprice;
        getText().setText(strv + "");
        FText();
    }

    /**
       minuses(Onum * TC * PTOPINGS) from the JTextField total then 
       addes(Nnum * NTC * PTOPINGS) to the JTextField total
    */
    private void changeTValue(int Onum,int TC,int Nnum,int NTC)
    {
        double strv;
        Onum++;
        Nnum++;
        strv = Double.valueOf(getText().getText()).doubleValue();
        strv -= Onum * TC * PTOPINGS;
        strv += Nnum * NTC * PTOPINGS;
        getText().setText(strv + "");
        FText();
    }        

    /**
       make shure that (JTextField)total is formated so it dont have any desmals past the second one
    */
    private void FText(){
       total.setText((double)(Math.round(Double.valueOf(total.getText()).doubleValue()*100))/100+"");
    }

    private JTextField getText(){
        return total;
    }

    private JComboBox getBox(){
        return box;
    }

    private int lastSize = 0, lastNC = 0, NTS = 0;
    private final JComboBox box = new JComboBox(new DefaultComboBoxModel());
    private final JTextField total = new JTextField(PPRICE[0] + "");
}
