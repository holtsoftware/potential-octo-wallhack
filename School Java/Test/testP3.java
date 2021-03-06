// Adam Holt
// week 12
// problem 3 
// test lab part

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class testP3 extends JApplet {
    final String[] INames = {"Train 1","Train 2","Train 3"};
    public void init() throws RuntimeException{
        final Container con = getContentPane();
	con.setLayout(new BorderLayout());

	con.add(setUpButtons(),"North");
	fetchImages();
	con.add(tdimgs,"Center");
    }

    private Container setUpButtons(){
        JButton[] butts = new JButton[INames.length];
	Container con = new Container();
	con.setLayout(new FlowLayout());

	for(int i = 0; i < butts.length; i++)
	{
	    butts[i] = new JButton(INames[i]);
	    con.add(butts[i]);
	    final int t = i;
	    butts[i].addActionListener(new ActionListener(){
	        public void actionPerformed(ActionEvent e){
		    tdimgs.setImage(img[t]);
		    tdimgs.repaint();
		}
	    });
	}
	return con;
    }

    private void fetchImages() throws RuntimeException
    {
	MediaTracker tracker = new MediaTracker(this);
        for(int i = 0; i<INames.length;i++)
	{
	    String value = getParameter("Image"+ (i+1));
	    System.out.println(getDocumentBase() + value);
	    if(value == null){
	        throw new RuntimeException("Parameter: Image"+(i+1)+" is missing.");
	    }

	    img[i] = getImage(getDocumentBase(), value);
	    tracker.addImage(img[i],0);
        }

	try{
	    tracker.waitForAll();
	}
	catch(InterruptedException e){
	}

	if(tracker.isErrorAny()){
	    throw new RuntimeException("Image loading problem");
	}
    }

    public Image[] img = new Image[INames.length];
    private piamges tdimgs = new piamges();
}

class piamges extends JPanel {
    public void paint(Graphics g){
        super.paint(g);

	Dimension size = getSize();

	if(img != null){
	    g.drawImage(img,0,0,size.width,size.height,getBackground(),this);
	}
    }

    public void setImage(Image im){
	    img = im;
    }

    private Image img;
}
