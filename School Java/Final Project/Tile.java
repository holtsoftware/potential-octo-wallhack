/*
 * BugTile.java
 *
 * Created on June 12, 2002, 7:18 PM
 */
import java.util.*;
/**
 *
 * @author  adam
 * @version 1.1
 */
public class Tile {
    public static final int Dirt=0;
    public static final int Rock=1;
	public static final int Water=2;
    public static final int Plant=3;
    public static final int Bug=4;
    protected int type=Dirt;
    protected long energy;
    protected long energydecro;
    protected long energyincro;
	protected long MaxEnergy=1;

    /** Creates new BugTile */
	public Tile(){
		this(false);
	}

    public Tile(boolean isRock) {
        energy = 0;
        energydecro = 0;
        energyincro = 0;
		if(isRock){
			setType(Rock);
		}
		else{
	        setType(Dirt);
		}
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
    public boolean isEdible(){
        return false;
    }

	/** if it can be drunk ie water */
	public boolean isDrinkable(){
		return false;
	}
    
	/** Gets what the tile is */
    public int getType(){
        return type;
    }
    
	/** sets what the tile is can only 
    protected void setType(int tp){
        type = tp;
    }
    
    public long getEnergy(){
        return energy;
    }
}

// vim:ts=4
