/*
 * AIAction.java
 *
 * Created on June 12, 2002, 7:52 AM
 */

/**
 *
 * @author  adam
 * @version 1.1
 */
public class AIAction {
    public static int None = 0;
    public static int Move = 1;
    public static int TakeEnergy = 2;
    public static int DecEnergy = 3;
    public static int IncreaseEnergy = 4;
    public static int TakeWater = 5;
    public static int DecWater = 6;
    public static int IncreaseWater = 7;
    private int index;
    private long value;
    private int aiaction;

    /** Creates new AIAction */
    public AIAction() {
        index = 0;
        value = 0;
        aiaction = AIAction.None;
        
    }
    
    public void setAIAction(int a,int in,long val){
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
    
    public long getValue(){
        return value;
    }
}
