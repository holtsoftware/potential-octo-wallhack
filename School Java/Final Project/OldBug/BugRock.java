/*
 * BugRock.java
 *
 * Created on June 16, 2002, 7:56 PM
 */

/**
 *
 * @author  adam
 * @version 
 */
public class BugRock extends BugTile {

    /** Creates new BugRock */
    public BugRock() {
    }
    
    /** nothing can be done so only AIAction.None should be passed*/
    public boolean validateAction(AIAction act){
        if(act.getAIAction() == AIAction.None){
            return true;
        }
        return false;
    }

}
