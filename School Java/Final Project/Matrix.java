/*
 * Matrix.java
 *
 * Created on June 10, 2002, 5:15 PM
 */
import java.util.*;
/**
 * Like the Vector class but two demental
 * @author  adam
 * @version 
 */
public class Matrix {
    protected Vector mtr;
    protected int cols=0,rows=0;

    /** Creates new Matrix  of zero elements*/
    public Matrix() {
        this(0,0);
    }
    
    /** Creates new Matrix of c cols and r rows*/
    public Matrix(int r,int c){
        cols = c;
        rows = r;
        
        Vector v;
        mtr = new Vector();
        mtr.setSize(r);
        for(int j=0;j<r;j++){
            v = new Vector();
            v.setSize(c);
            mtr.setElementAt(v,j);
        }        
    }
    
    /** Creates new Matrix of cr cols and rows*/
    public Matrix(int rc){
        this(rc,rc);
    }
    
    /** Crates a new Matrix of c cols and r rows*/
    public void setSize(int r,int c){
        mtr.setSize(r);
        if(r > rows){
            Vector v;
            for(int j=rows;j<r;j++){
                v = new Vector();
                mtr.setElementAt(v,j);
            }
        }
        
        cols=c;
        rows=r;
        for(int j=0;j<rows;j++){
            ((Vector)mtr.elementAt(j)).setSize(c);
        }
    }
    
    /** Sets the curent element at c and r to o */
    public void setAt(int r,int c,Object o){
        if(c >= cols || c < 0){
            System.err.println("Invalid colum number: "+c);
            System.exit(1);
        }
        else if(r >= rows || r < 0){
            System.err.println("Invalid row number: "+r);
            System.exit(1);
        }
        ((Vector)mtr.elementAt(c)).setElementAt(o,r);
    }
    
    /** Get the current element at c and r */
    public Object getAt(int r,int c){
        if(c >= cols || c < 0){
            System.err.println("Invalid colum number: "+c);
            System.exit(1);
        }
        else if(r >= rows || r < 0){
            System.err.println("Invalid row number: "+r);
            System.exit(1);
        }
        return ((Vector)mtr.elementAt(c)).elementAt(r);
    }
    
    /** Gets the number of Rows */
    public int getRows(){
        return rows;
    }
    
    /** Gets the number of cols */
    public int getCols(){
        return cols;
    }
}
