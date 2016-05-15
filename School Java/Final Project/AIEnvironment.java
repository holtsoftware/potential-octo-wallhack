/*
 * AIEnvironment.java
 *
 * Created on June 15, 2002, 5:16 PM
 */

/**
 *
 * @author  adam
 * @version 
 */
public class AIEnvironment {
    public static final int Sunny=0;
    public static final int LightClouds=1;
    public static final int OverCast=2;
    public static final int Raining=3;
    private int type;

    /** Creates new AIEnvironment */
    public AIEnvironment() {
        setAIEnvironment(Sunny);
    }
    
    public AIEnvironment(int tp){
        setAIEnvironment(tp);
    }
    
    /** sets how the envirernment is */
    public void setAIEnvironment(int tp){
        type = tp;
    }
    
    /** gets how the environment is */
    public int getAIEnvironment(){
        return type;
    }

}
