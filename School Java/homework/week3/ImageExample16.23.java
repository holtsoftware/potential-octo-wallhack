// Adam Holt
// week3
// Exercise 16.23

        // View an image in a frame that exactly surrounds it.
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.File;

        // Load and display the image files passed as command-line
        // arguments.
class ImageExample {
    public static void main(String[] args){

        for(int i = 0; i < args.length; i++){
            File f = new File(args[i]);
            if(f.exists() && f.isFile() && f.canRead()){
                System.out.println("Loading: "+args[i]);
                // Display it.
                new ImageFrame(args[i]);
            }
            else{
                System.err.println("Unable to load: "+args[i]);
            }
        }
    }
}

class ImageFrame extends Frame {
    public ImageFrame(String str){
        // Get the default toolkit for this environment.
        Toolkit tk = Toolkit.getDefaultToolkit();
        Image graphic = tk.getImage(str);
		Canvas can = new ImageViewer(graphic,getInsets());
		add(can);
		can.repaint();
		setSize(can.getWidth(),can.getHeight());
		setVisible(true);
	}	

}

class ImageViewer extends Canvas {
    public ImageViewer(Image image,Insets ins){
        setImage(image);
		setInsets(ins);
		setup();
    }

        // Obtain the image from the producer.
    public ImageViewer(ImageProducer producer){
        setImage(createImage(producer));
		setup();
    }


        // Perform common frame setup for the two constructors.
    protected void setup(){
        // Dimensions are adjusted once the dimensions of
        // the image are known.
        final int initialWidth = 200, initialHeight = 200;
        setSize(initialWidth,initialHeight);

        // Quit on a keypress.
        addKeyListener(new KeyAdapter(){
            public void keyTyped(KeyEvent e){
                setVisible(false);
                Container parent = getParent();
                if(parent != null){
                    parent.remove(ImageViewer.this);
                }
                else{
                    System.exit(0);
                }
            }
        });
        setVisible(true);
    }

    public void paint(Graphics g){
        // Make sure it appears just within the frame's insets.
        Insets insets = getInsets();
        g.drawImage(getImage(),insets.left,insets.top,this);
    }

    // Override Frame.imageUpdate - the implemention of ImageObserver.
    public boolean imageUpdate(Image img,int infoflags,int x, int y,
                                int width, int height){
        // Find out what has changed.
        boolean result = super.imageUpdate(img,infoflags,x,y,width,height);
        // See if the image is complete.
        if((infoflags & ImageObserver.ALLBITS) != 0){
            // Set the frame's size according to the image size.
            Insets insets = getInsets();
            // Include in the width and height the insets space required
            // for the frame's decoration.
            int newWidth = insets.left+width+insets.right;
            int newHeight = insets.top+height+insets.bottom;
            setSize(newWidth,newHeight);
        }
        else if((infoflags & (ImageObserver.ABORT | ImageObserver.ERROR)) != 0){
            System.err.println("Image error.");
        }
        else{
            // Ignore.
        }
        return result;
    }

	protected Image getImage(){
        return image;
    }

    protected void setImage(Image i){
        image = i;
    }    
	
	protected Insets getInsets()
	{
		return insets;
	}

	protected void setInsets(Insets ins)
	{
		insets = ins;
	}

    private Image image;
	private Insets insets;
}
