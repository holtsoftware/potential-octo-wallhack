import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class MessageInterface extends 
	JFrame {
	//JApplet {

	private final bool scrol = new bool(true);
	
	public MessageInterface(){
	//public void init(){
		setSize(600,400);
		Container pane = getContentPane();
		
		final JTextArea txt = new JTextArea();//messages from the server are to be desplayed here
		txt.setLineWrap(true);
		txt.setEditable(false);
		txt.setFont(new Font("courier",Font.PLAIN,12)); 

		final JScrollPane scroller = new JScrollPane(txt);
		final JToolBar TBar = new JToolBar(JToolBar.HORIZONTAL);
		final MessageSocket mesg = new MessageSocket();
		try{
			mesg.activateSocket("grinder.kwsn.org",24101,txt,scroller.getVerticalScrollBar());
		}
		catch(Exception e){
			txt.append(e.getMessage()+"\n");
		}

		final JScrollBar bar = scroller.getVerticalScrollBar(); 
		bar.addAdjustmentListener(new AdjustmentListener(){
			public void adjustmentValueChanged(AdjustmentEvent e){
				if(scrol.getValue())
					bar.setValue(bar.getMaximum());
			}
		});

		final JCheckBox CBox = new JCheckBox("Auto Scroll.");
		CBox.setToolTipText("Stops it from scrolling down to the bottom.");
		CBox.setSelected(true);
		CBox.addItemListener(new ItemListener(){
			public void itemStateChanged(ItemEvent e){
				if(e.getStateChange() == ItemEvent.SELECTED){
					scrol.setValue(true);
				}
				else{
					scrol.setValue(false);
				}
			}
		});
		TBar.add(CBox);
	
		final JTextField fld = new JTextField();
		fld.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				try{
					mesg.sendLine(fld.getText());
					fld.setSelectionStart(0);
					fld.setSelectionEnd(fld.getText().length());
				}
				catch(Exception ev){
					txt.append(ev.getMessage()+"\n");
				}
			}
		});

		pane.add(TBar,"North");
		pane.add(scroller,"Center");
		pane.add(fld,"South");
	}
}


// vim:ts=4
