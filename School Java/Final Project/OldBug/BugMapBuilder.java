/*
 * BugMapBuilder.java
 *
 * Created on June 10, 2002, 7:42 PM
 */
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.filechooser.FileFilter;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.beans.*;
/**
 *
 * @author  adam
 * @version 
 */
public class BugMapBuilder extends JInternalFrame {
    private JMenuBar MainBar;
    private JMenu FileMenu;
    private JSlider colSld,rowSld;
    private Matrix ComBoxs;
    private Container Coms;
    private BugMap map;

    /** Creates new BugMapBuilder */
    public BugMapBuilder() {
        Container con = getContentPane();
        map = new BugMap();
        ComBoxs = new Matrix(5,5);
        Coms = new Container();
        MainBar = new JMenuBar();
        
        setUpFileMenu();
       
        MainBar.add(FileMenu);
        setJMenuBar(MainBar);
        
        con.add(setUpSliders(),"North");
        con.add(Coms,"Center");
        //con.add(MainBar,"North");
        setResizable(true);
        setIconifiable(true);
        setTitle("Map Builder");
        setClosable(true);
        setMaximizable(true);
        updateComs();
    }
    
    protected void setUpFileMenu(){
        JMenuItem mnu;
        FileMenu = new JMenu("File");
        FileMenu.setMnemonic('F');
        mnu = new JMenuItem("Open");
        mnu.setMnemonic('O');
        mnu.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                LoadMap();
            }
        });
        FileMenu.add(mnu);
        
        /*mnu = new JMenuItem("test Vector");
        mnu.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                Matrix m = map.getMap();
                Vector v;
                for(int i=0;i<m.getRows();i++){
                    for(int j=0;j<m.getCols();j++){
                        v = BugEnvironment.getVector(m,i,j);
                        for(int k=0;k<8;k++){
                            if(v.get(k) == null){
                                System.out.print("null");
                            }
                            else{
                                System.out.print((String)v.get(k));
                            }
                            System.out.print(",");
                        }
                        System.out.println();
                    }
                }
            }
        });
        FileMenu.add(mnu);*/
        
        mnu = new JMenuItem("Save");
        mnu.setMnemonic('S');
        mnu.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                SaveMap(false);
            }
        });
        FileMenu.add(mnu);
        
        mnu = new JMenuItem("Save As");
        mnu.setMnemonic('A');
        mnu.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                SaveMap(true);
            }
        });
        FileMenu.add(mnu);
        FileMenu.addSeparator();
        
        mnu = new JMenuItem("Close");
        mnu.setMnemonic('C');
        mnu.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                try{
                    setClosed(true);
                    dispose();
                }catch(PropertyVetoException ev){
                    System.err.println(ev);
                }
            }
        });
        FileMenu.add(mnu);
        
    }
    
    public void paint(Graphics g){
        Coms.paint(g);
        super.paint(g);
    }
    
    private Container setUpSliders(){
        Container con = new Container();
        con.setLayout(new GridLayout(1,2));
        
        colSld = new JSlider(1,10);
        rowSld = new JSlider(1,10);
        colSld.setPaintTicks(true);
        colSld.setMajorTickSpacing(1);
        colSld.setMinorTickSpacing(1);
        colSld.setPaintLabels(true);
        colSld.setSnapToTicks(true);
        colSld.setToolTipText("Number of Coloms");
        colSld.addChangeListener(new ChangeListener(){
            public void stateChanged(ChangeEvent e){
                updateComs();
            }
        });
        
        rowSld.setPaintTicks(true);
        rowSld.setMajorTickSpacing(1);
        rowSld.setMinorTickSpacing(1);
        rowSld.setPaintLabels(true);
        rowSld.setSnapToTicks(true);
        rowSld.setToolTipText("Number of Rows");
        rowSld.addChangeListener(new ChangeListener(){
            public void stateChanged(ChangeEvent e){
                updateComs();
            }
        });
        
        con.add(colSld);
        con.add(rowSld);
        return con;
    }
    
    protected void updateComs(){
        int Col = colSld.getValue();
        int Row = rowSld.getValue();
        JComboBox box = new JComboBox();
        DefaultComboBoxModel model = (DefaultComboBoxModel)box.getModel();
        model.addElement("Plant");
        Coms.removeAll();
        Coms.setLayout(new GridLayout(Row,Col));
        
        ComBoxs.setSize(Col,Row);
        for(int i=0;i<Row;i++){
            for(int j=0;j<Col;j++){
                box = new JComboBox();
                model = (DefaultComboBoxModel)box.getModel();
                model.addElement("Dirt");
                model.addElement("Rock");
                model.addElement("Plant");
                model.addElement("Bug");
                ComBoxs.setAt(j,i,box);
                Coms.add(box);
            }
        }
        pack();
    }
    
    protected int getComBoxIndex(String s){
        s.toUpperCase();
        if(s.charAt(0) == 'D'){
            return 0;
        }
        else if(s.charAt(0) == 'R'){
            return 1;
        }
        else if(s.charAt(0) == 'P'){
            return 2;
        }
        else{
            return 3;
        }
    }
    
    public void LoadMap(){
        JFileChooser chooser = new JFileChooser();
        // Note: source for ExampleFileFilter can be found in FileChooserDemo,
        // under the demo/jfc directory in the Java 2 SDK, Standard Edition.
        final FileFilter filter = new SuffixFileFilter("map","Bug Map");
        
        chooser.setFileFilter(new FileFilter(){
            public boolean accept(File f){
                return (f != null) && (f.isDirectory() || filter.accept(f));
            }
            
            public String getDescription(){
                return "Folders and maps";
            }
        });
        chooser.addChoosableFileFilter(filter);
        int returnVal = chooser.showDialog(this,"Open");
        if(returnVal != JFileChooser.APPROVE_OPTION) {
           return;
        }
        
        if(map.LoadMap(chooser.getSelectedFile().getPath()) != true){
            JMessageBox.Message("Invalid file formate.");
        }
        Matrix mtr=map.getMap();
        int cols=mtr.getCols();
        int rows=mtr.getRows();
        
        colSld.setValue(cols);
        rowSld.setValue(rows);
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ((JComboBox)ComBoxs.getAt(j,i)).setSelectedIndex(getComBoxIndex(
                ((String)mtr.getAt(j,i))));
            }
        }
        pack();
    }
    
    public void SaveMap(boolean b){
        JFileChooser chooser = new JFileChooser();
        if(map.getFileName() != null && !b){
        }
        else{
        
        // Note: source for ExampleFileFilter can be found in FileChooserDemo,
        // under the demo/jfc directory in the Java 2 SDK, Standard Edition.
        final FileFilter filter = new SuffixFileFilter("map","Bug Map");
        
        chooser.setFileFilter(new FileFilter(){
            public boolean accept(File f){
                return (f != null) && (f.isDirectory() || filter.accept(f));
            }
            
            public String getDescription(){
                return "Folders and maps";
            }
        });
        chooser.addChoosableFileFilter(filter);
        
            int returnVal = chooser.showDialog(this,"Save");
            if(returnVal != JFileChooser.APPROVE_OPTION) {
               return;
        }}
        int col = colSld.getValue();
        int row = rowSld.getValue();
        Matrix mtr= new Matrix(col,row);
        String s;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                s=(String)((JComboBox)ComBoxs.getAt(j,i)).getSelectedItem();
                s = String.valueOf(s.charAt(0));
                s.toLowerCase();
                mtr.setAt(j,i,s);
            }
        }
        
        map.setMap(mtr);
        
        if(map.getFileName() != null && !b){
            if(!map.SaveMap()){
                JMessageBox.Message("Couldn't save to file "+map.getFileName());
            }
        }
        else{
            if(map.SaveMap(chooser.getSelectedFile().getPath()) != true){
                JMessageBox.Message("Couldn't save to file "+
                    chooser.getSelectedFile().getPath());
            }
        }
    }

}
