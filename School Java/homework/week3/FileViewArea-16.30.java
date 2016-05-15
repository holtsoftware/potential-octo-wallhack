// Adam Holt
// week 3
// exercise 16.30

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.Date;

        // Display the contents of a file in a TextArea with
        // two scrollbars. Maintain details of the current file
        // so that these can be displayed with a popup menu.
public class FileViewArea extends TextArea implements MouseListener {
    public FileViewArea(int rows, int cols){
        super("",rows,cols,SCROLLBARS_BOTH);
        setBackground(Color.white);

        // Create a popup menu for displaying the file's details.
        PopupMenu popup = new PopupMenu("File Details");// I changed this constructer
        setPopup(popup);
        add(popup);
        // Trigger the popup on mouse events.
        addMouseListener(this);
    }

    public void display(File details,String text){
        setDetails(details);
        setText(text);
    }

        // Methods of MouseListener.
    public void mousePressed(MouseEvent e){
        if(e.isPopupTrigger()){
            showPopup(e.getX(),e.getY());
            e.consume();
        }
    }

    public void mouseReleased(MouseEvent e){
        if(e.isPopupTrigger()){
            showPopup(e.getX(),e.getY());
            e.consume();
        }
    }

        // Display details of the current file.
    protected void showPopup(int x, int y){
        File details = getDetails();
        if(details != null){
            PopupMenu popup = getPopup();
            // Clean it out from the last time it was used.
            popup.removeAll();
            popup.add(new MenuItem("File:     "+details.getName()));//made it so this wasn't the menu lable
            popup.add(new MenuItem("Path:     "+details.getPath()));
            if(!details.isAbsolute())
            {
                // if the path isn't absolute ill add the absolute path
                popup.add(new MenuItem("AbsPath:  " + details.getAbsolutePath()));
            }
            popup.add(new MenuItem("Size:     "+details.length()));
            popup.add(new MenuItem("Modified: "+
                                new Date(details.lastModified())));
            popup.show(this,x,y);
        }
    }

        // The remaining methods are of no interest.
    public void mouseClicked(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}

    protected File getDetails(){
        return details;
    }

    protected void setDetails(File d){
        details = d;
    }

    protected PopupMenu getPopup(){
        return popup;
    }

    protected void setPopup(PopupMenu p){
        popup = p;
    }

    // Details of the currently displayed file.
    File details = null;
    // The popup menu used to display the file's details.
    PopupMenu popup;
}

