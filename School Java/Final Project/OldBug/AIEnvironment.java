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
    public static int Sunny=0;
    public static int LightClouds=1;
    public static int OverCast=2;
    public static int Raining=3;
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
    public int GetAIEnvironment(){
        return type;
    }

}
