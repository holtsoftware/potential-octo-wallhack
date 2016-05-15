// Adam Holt
// week5
// homework #2
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class weather {
    public static void main(String[] args){
        JFrame frame = new WeatherFrame();
        frame.addWindowListener(new WindowCloser());
        frame.setVisible(true);
        ((WeatherFrame)frame).run();
    }
}

class WeatherFrame extends JFrame implements Runnable {
    public WeatherFrame(){
        setSize(150,90);
    
        Container con = getContentPane();
        JButton butintr = new JButton("Update");
        
        tLabels[0] = new JLabel("Wind Speed:");
        tLabels[1] = new JLabel("Humidity  :");
        tLabels[2] = new JLabel("Tempiture :");
        tLabels[3] = new JLabel("0 ");
        tLabels[4] = new JLabel("0 ");
        tLabels[5] = new JLabel("0 ");

        butintr.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                update();
            }
        });

        doadd(con,tLabels,butintr);
    }

    private void doadd(Container con, JLabel [] toaddL,JButton intr){
        Container con1 = new Container();
        con1.setLayout(new BorderLayout());
        con1.add(toaddL[0],"Center");
        con1.add(toaddL[3],"East");
        
        con.add(con1,"North");

        con1 = new Container();
        con1.setLayout(new BorderLayout());
        con1.add(toaddL[1],"Center");
        con1.add(toaddL[4],"East");
        con.add(con1,"Center");

        con1 = new Container();
        con1.setLayout(new BorderLayout());
        con1.add(toaddL[2],"Center");
        con1.add(toaddL[5],"East");
        con1.add(intr,"South");
        con.add(con1,"South");
    }

    public void run(){
        while(true)
        {
            try{
                update();
                Thread.sleep(5000);
            }
            catch(InterruptedException e){
            }
        }
    }

    public void update(){
        tLabels[3].setText(Math.round(Math.random()*60) + " ");
        tLabels[4].setText(Math.round(Math.random()*50) + " ");
        tLabels[5].setText((Math.round(Math.random()*160)-40) + " "); 
    }
    public final JLabel[] tLabels = new JLabel[6];
}
