/*
 * BugFraim.java
 *
 * Created on June 10, 2002, 7:45 PM
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
/**
 *
 * @author  adam
 * @version 
 */
public class BugFraim extends JFrame{
    private JMenuBar MainMenu;

    /** Creates new BugFraim */
    public BugFraim() {
        setSize(500,500);
        setTitle("Bugs");
        
        Container cont = getContentPane();
        
        cont.add(desktop,"Center");
        MainMenu = new JMenuBar();
        setUpFile();
        setUpMap();
        setJMenuBar(MainMenu);
        //setResizable(false);
        /*BugMapBuilder mb = new BugMapBuilder();
        desktop.add(mb);
        //setJMenuBar(mb.MainBar);
        mb.setSize(200,200);
        mb.show();*/
        
    }
    
    protected void setUpFile(){
        JMenu mnu = new JMenu("File");
        JMenuItem mnui;
        mnu.setMnemonic('F');
        mnui = new JMenuItem("Exit");
        mnui.setMnemonic('x');
        mnui.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });
        mnu.add(mnui);
        MainMenu.add(mnu);
        
    }
    
    protected void setUpMap(){
        JMenu mnu = new JMenu("Map");
        JMenuItem mnui;
        mnu.setMnemonic('M');
        mnui = new JMenuItem("Editer");
        mnui.setMnemonic('E');
        mnui.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                BugMapBuilder map = new BugMapBuilder();
                desktop.add(map);
                map.show();
                map.setSize(300,300);
            }
        });
        mnu.add(mnui);
        MainMenu.add(mnu);
    }
    
    private final JDesktopPane desktop = new JDesktopPane();
}
