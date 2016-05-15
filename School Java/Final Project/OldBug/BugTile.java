/*
 * BugTile.java
 *
 * Created on June 12, 2002, 7:18 PM
 */
import java.util.*;
/**
 *
 * @author  adam
 * @version 
 */
public class BugTile {
    public static final int Tile=-1;
    public static final int Dirt=0;
    public static final int Rock=1;
    public static final int Plant=2;
    public static final int Bug=3;
    protected int type;
    protected long energy;
    protected long energydecro;
    protected long energyincro;

    /** Creates new BugTile */
    public BugTile() {
        energy = 0;
        energydecro = 0;
        energyincro = 0;
        setType(Tile);
    }
    
    /** returns what action this object is going to do this rotation */
    public AIAction getAIAction(Vector v,AIEnvironment env){
        AIAction act = new AIAction();
        act.setAIAction(AIAction.None,0);
        return act;
    }
    
    /** validates that the spasific action can be preformed on this object */
    public boolean validateAction(AIAction ai){
        if(ai.getAIAction() == AIAction.None){
            return true;
        }
        else if(ai.getAIAction() == AIAction.Move){
            return true;
        }
        else{
            return false;
        }
    }
    
    /** das nothing here but in inherited classes it sould do the action requested of the object */
    public void doTargetAction(AIAction ai){
    }
    
    /** das nothing here but in inherited classed it should do the action it chose to do */
    public void doSendAction(AIAction ai){
    }
    
    /** the best way to see if this tile can be eaten */
    public boolean isEatAble(){
        return false;
    }
    
    public int getType(){
        return type;
    }
    
    public void setType(int tp){
        type = tp;
    }
    
    public long getEnergy(){
        return energy;
    }
}
