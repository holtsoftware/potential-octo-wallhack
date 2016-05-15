// Adam Holt
// week3
// exercise 16.28
// answer
// if we didn't override the the update method in the AnimatedArcCanvas

        // Illustrate a basic animation of a filled arc drawn full circle.
import java.awt.*;

public class AWTAnimate1 {
    public static void main(String[] args){
        AnimationFrame frame = new AnimationFrame();
        frame.addWindowListener(new WindowCloser());
        frame.setVisible(true);
        // Hand over to the frame to run forever.
        frame.run();
    }
}

    // Repeatedly request a canvas to paint itself.
class AnimationFrame extends Frame {
    public AnimationFrame(){
        // Set the frame's size.
        final int width = 200, height = 200;
        setSize(width,height);
        setBackground(Color.white);

        add(getCanvas());
    }

    public void run(){
        // Animate the drawing 50 times per second.
        final int sleepTime = 1000/50;
        AnimatedArcCanvas canvas = getCanvas();
        while(true){
            try{
                Thread.sleep(sleepTime);
                // Perform the next animation step.
                canvas.step();
            }
            catch(InterruptedException e){
            }
        }
    }

    protected AnimatedArcCanvas getCanvas(){
        return animationCanvas;
    }

    private AnimatedArcCanvas animationCanvas = new AnimatedArcCanvas();
}

    // Animate an arc through a full circle before starting again.
class AnimatedArcCanvas extends Canvas {
    public void paint(Graphics g){
        Dimension size = getSize();

        final int x = size.width/4, y = size.height/4;
        final int width = size.width/2, height = size.height/2;

        final int sweep = getAngle();
        g.fillArc(x,y,width,height,sweep - angleIncrement, angleIncrement);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //made this only call the super update when you arc needs to be cleared
    public void update(Graphics g)
    {
	paint(g);
        if(getAngle() == 0)
	{
	    super.update(g);
	}
    }    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Perform the next animation step.
    public void step(){
        // Update the angle.
        setAngle(getAngle()+angleIncrement);

        // Clear last step and draw the current arc
        repaint();
    }

    protected int getAngle(){
        return angle;
    }

    protected void setAngle(int a){
        if(Math.abs(a) <= circleDegrees){
            angle = a;
        }
        else{
            // Time to restart.
            angle = 0;
        }
    }

    // Always start at the 3 o'clock position.
    private final int startAngle = 0;
    // The number of degrees in a circle.
    private final int circleDegrees = 360;
    // Update the angle by a fixed amount.
    final int angleIncrement = 12;
    // How many degrees of sweep for the arc.
    private int angle = 0;
}
