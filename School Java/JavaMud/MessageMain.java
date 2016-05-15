import javax.swing.*;


public class MessageMain{
	public static void main(String[] args){
		JFrame frame = new MessageInterface();
		frame.addWindowListener(new WindowCloser());
		frame.show();
	}
}

// vim:ts=4
