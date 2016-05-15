 /*
 * BugEnvironment.java
 *
 * Created on June 12, 2002, 8:08 AM
 */
import java.util.Vector;
import java.util.TimerTask;
import java.util.Timer;

/**
 * @author  adam
 * @version 1.1
 */
public class BugEnvironment extends TimerTask{
	private TaskStarter tsk;
	private Matrix map;

    /** Creates new BugEnvironment and start its scedule at 1000*/
    public BugEnvironment(BugMap nMap) {
        this(1000,nMap);
    }

	/** Creates a new BugEnvironmnet and starts its scedule at time 
	 *  It must have a a loaded BugMap passed */
	public BugEnvironment(int time,BugMap nMap){
        if(nMap.getMap() == null){
            System.err.println("Didn't pass a loaded BugMap" +
                               " object this will cas errors!");
        }
        else{
            Matrix m = nMap.getMap();
            map = new Matrix(m.getRows(),m.getCols());
			// Load the tiles
            for(int i=0;i<m.getRows();i++){
                for(int k=0;k<m.getCols();k++){
					// Load the appropreate tile for the map
                    if((String)m.getAt(i,k) == "D"){
                    }
                    else if((String)m.getAt(i,k) == "R"){
                    }
					else if((String)m.getAt(i,K) == "W"){
					}
                    else if((String)m.getAt(i,k) == "P"){
                    }
                    else{
                    }
                }
            }
                    
            tsk = new TaskStarter(time,this);
        }
    }

    public void run() {
    }
    
    /** This is a big nasty function bug its the best way i could think of doing this */
    static public Vector getVector(Matrix m,int row,int col){
        Vector v=new Vector();
        v.setSize(8);

        if(row-1 < 0){
            v.setElementAt(null,0);
            v.setElementAt(null,1);
            v.setElementAt(null,2);
            if(col-1 < 0){
                v.setElementAt(null,6);
                v.setElementAt(null,7);
                if(row+1 >= m.getRows()){
                    v.setElementAt(null,5);
                    v.setElementAt(null,4);
                    if(col+1 >= m.getCols()){
                        v.setElementAt(null,3);
                    }
                    else{
                        v.setElementAt(m.getAt(col+1,row),3);
                    }
                }
                else if(col+1 >= m.getCols()){
                    v.setElementAt(null,2);
                    v.setElementAt(null,3);
                    v.setElementAt(null,4);
                    v.setElementAt(m.getAt(col,row+1),5);
                }
                else{
                        v.setElementAt(m.getAt(col+1,row),3);
                        v.setElementAt(m.getAt(col+1,row+1),4);
                        v.setElementAt(m.getAt(col,row+1),5);
                }
            }
            else if(row+1 >= m.getRows()){
                v.setElementAt(null,4);
                v.setElementAt(null,5);
                v.setElementAt(null,6);
                if(col+1 >= m.getCols()){
                    v.setElementAt(null,3);
                    v.setElementAt(m.getAt(col-1,row),7);
                }
                else{
                    v.setElementAt(m.getAt(col+1,row),3);
                    v.setElementAt(m.getAt(col-1,row),7);
                }
            }
            else if(col+1 >= m.getCols()){
                v.setElementAt(null,3);
                v.setElementAt(null,4);
                v.setElementAt(m.getAt(col-1,row),7);
                v.setElementAt(m.getAt(col-1,row+1),6);
                v.setElementAt(m.getAt(col,row+1),5);
            }
            else{
                v.setElementAt(m.getAt(col+1,row),3);
                v.setElementAt(m.getAt(col+1,row+1),4);
                v.setElementAt(m.getAt(col,row+1),5);
                v.setElementAt(m.getAt(col-1,row+1),6);
                v.setElementAt(m.getAt(col-1,row),7);
            }
        }
        else if(col-1 < 0){
            v.setElementAt(null,0);
            v.setElementAt(null,7);
            v.setElementAt(null,6);
            if(row+1 >= m.getRows()){
                v.setElementAt(null,5);
                v.setElementAt(null,4);
                if(col+1 >= m.getCols()){
                    v.setElementAt(null,2);
                    v.setElementAt(null,3);
                    v.setElementAt(m.getAt(col,row-1),1);
                }
                else{
                    v.setElementAt(m.getAt(col,row-1),1);
                    v.setElementAt(m.getAt(col+1,row-1),2);
                    v.setElementAt(m.getAt(col+1,row),3);
                }
            }
            else if(col+1 >= m.getCols()){
                v.setElementAt(null,2);
                v.setElementAt(null,3);
                v.setElementAt(null,4);
                v.setElementAt(m.getAt(col,row-1),1);
                v.setElementAt(m.getAt(col,row+1),5);
            }
            else{
                v.setElementAt(m.getAt(col,row-1),1);
                v.setElementAt(m.getAt(col+1,row-1),2);
                v.setElementAt(m.getAt(col+1,row),3);
                v.setElementAt(m.getAt(col+1,row+1),4);
                v.setElementAt(m.getAt(col,row+1),5);
            }
        }
        else if(row+1 >= m.getRows()){
            v.setElementAt(null,4);
            v.setElementAt(null,5);
            v.setElementAt(null,6);
            if(col+1 >= m.getCols()){
                v.setElementAt(null,2);
                v.setElementAt(null,3);
                v.setElementAt(null,4);
                v.setElementAt(m.getAt(col-1,row-1),0);
                v.setElementAt(m.getAt(col,row-1),1);
                v.setElementAt(m.getAt(col-1,row),7);
            }
            else{
                v.setElementAt(m.getAt(col-1,row-1),0);
                v.setElementAt(m.getAt(col,row-1),1);
                v.setElementAt(m.getAt(col+1,row-1),2);
                v.setElementAt(m.getAt(col+1,row),3);
                v.setElementAt(m.getAt(col-1,row),7);
            }
        }
        else if(col+1 >= m.getCols()){
            v.setElementAt(null,2);
            v.setElementAt(null,3);
            v.setElementAt(null,4);
            v.setElementAt(m.getAt(col-1,row-1),0);
            v.setElementAt(m.getAt(col,row-1),1);
            v.setElementAt(m.getAt(col,row+1),5);
            v.setElementAt(m.getAt(col-1,row+1),6);
            v.setElementAt(m.getAt(col-1,row),7);
        }
        else{
            v.setElementAt(m.getAt(col-1,row-1),0);
            v.setElementAt(m.getAt(col,row-1),1);
            v.setElementAt(m.getAt(col+1,row-1),2);
            v.setElementAt(m.getAt(col+1,row),3);
            v.setElementAt(m.getAt(col+1,row+1),4);
            v.setElementAt(m.getAt(col,row+1),5);
            v.setElementAt(m.getAt(col-1,row+1),6);
            v.setElementAt(m.getAt(col-1,row),7);
        }
        return v;
    }
        
        
}

class TaskStarter{
    public TaskStarter(){
    }
    
    public TaskStarter(int time,BugEnvironment bug){
        Timer tim = new Timer();
		tim.schedule(bug,time,time); 
    }
}

// vim:ts=4
