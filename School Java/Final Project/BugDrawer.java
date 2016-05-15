
package Bug;


public class BugDrawer extends Canvas
{
    getVisibleMatrix();
    Draw( int, int, image)/*gets the image of the subject*/
    /*Sees which image is needed and places it in a random location*/
    for()dirt
        if()water
        elseif()plant
        elseif()rock
        elseif()bug
        
    getNextWater();
    getNextPlant();
    getBug(int, int);
    LoadPictures();
    setImage(retrieveImage"bug2.gif");
    setImage(retrieveImage"plant.gif");
    setImage(retrieveImage"rock1.gif");
    setImage(retrieveImage"dirt2.gif");
    setImage(retrieveImage"Water.gif");
    

    /** Creates new BugDrawer */
    public BugDrawer() 
    {
    }

}
*Get Visible Matrix
 *Draw(row, col, getBug)//draws in the appropriate row and column and sees if the bug is there
 *public void Draw(Graphics g)
 *{final Dimension size = getSize();
 *Image image = getImage();
 *if(image !=null)
 {
 *  g.drawImage(image,0,0size.width,size.height,this);
 *
 *protected image retrieveImage(String filename) throws RuntimeException
 *{Image areaImage = getImage(getDocumentBase(), filename);
 *MediaTracker tracker = new MediaTracker(this);
 *tracker.addImage(areaImage,0);
 *try
 {
 *tracker.waitForAll();
 *}
 *catch(InterruptException e)
 {
 *}
 *if(tracker.isErrorAny())
 {
 *throw new RuntimeException("Image loading problem: "+fileName);
 *else
 {
 *  return areaImage;
 *}
 *}
 *protected Image getImage()
 {
 *return image;
 *}
 *protected void setImage(Image i)
 {
 *image = 1;
 *}
 }
