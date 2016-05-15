/*
 * AIAction.java
 *
 * Created on June 12, 2002, 7:52 AM
 */

/**
 *
 * @author  adam
 * @version 
 */
public class AIAction {
    static public int None = 0;
    static public int Move = 1;
    static public int TakeEnergy = 2;
    static public int IncreaseEnergy = 3;
    private int index;
    private int value;
    private int aiaction;

    /** Creates new AIAction */
    public AIAction() {
        index = 0;
        value = 0;
        aiaction = AIAction.None;
        
    }
    
    public void setAIAction(int a,int in,int val){
        aiaction = a;
        index = in;
        value = val;
    }
    
    public void setAIAction(int a,int in){
        aiaction = a;
        index = in;
    }
    
    public int getAIAction(){
        return aiaction;
    }
    
    public int getIndex(){
        return index;
    }
    
    public int getValue(){
        return value;
    }
}
