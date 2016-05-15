import java.awt.*;
    // Demonstrate fillPolygon and drawPolyline methods of the
    // Graphics class.
public class PolyFrame extends Frame {
    public void init(){
        setBackground(Color.white);
	add(new PolyCanvas());
    }
}

    // Graphics class.
class PolyCanvas extends Canvas {
        // Draw three diamond shapes, side by side.
    public void paint(Graphics g){
        Dimension size = getSize();

        // Define the width and height of the shapes.
        final int width = size.width/4, height = size.height/2;
        // Shift right between drawing the shapes.
        final int shapeGap = 5;

        // Offset from the edges.
        int gap = (size.width-(3*width+2*shapeGap))/2;
        if(gap < 0){
            gap = 5;
        }

        // The (x,y) coordinate pairs of the first shape.
        final int[] xvals = {
                gap, gap+width/2, gap+width, gap+width/2,
        };
        final int[] yvals = {
                height, height/2, height, 3*height/2,
        };

        // Draw a polygon shape.
        g.drawPolygon(xvals,yvals,xvals.length);

        // Shift the coordinate space to the right.
        g.translate(width+shapeGap,0);

        // Fill a Polygon object.
        Polygon poly = new Polygon(xvals,yvals,xvals.length);
        g.fillPolygon(poly);

        // Shift again.
        g.translate(width+shapeGap,0);

        // Draw a polyline.
        g.drawPolyline(xvals,yvals,xvals.length);
    }
}
