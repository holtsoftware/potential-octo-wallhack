/*
 * Matrix.java
 *
 * Created on June 10, 2002, 5:15 PM
 */
import java.util.*;
/**
 *
 * @author  adam
 * @version 
 */
public class Matrix {
    protected Vector mtr;
    protected int cols=0,rows=0;

    /** Creates new Matrix  of zero elements*/
    public Matrix() {
        cols = 0;
        rows = 0;
    }
    
    /** Creates new Matrix of c cols and r rows*/
    public Matrix(int c,int r){
        setSize(c,r);
    }
    
    /** Creates new Matrix of cr cols and rows*/
    public Matrix(int cr){
        setSize(cr,cr);
    }
    
    /** Crates a new Matrix of c cols and r rows*/
    public void setSize(int c,int r){
        cols = c;
        rows = r;
        
        Vector v;
        mtr = new Vector();
        mtr.setSize(c);
        for(int j=0;j<c;j++){
            v = new Vector();
            v.setSize(r);
            mtr.setElementAt(v,j);
        }
    }
    
    /** Sets the curent element at c and r to o */
    public void setAt(int c,int r,Object o){
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
    public Object getAt(int c,int r){
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
