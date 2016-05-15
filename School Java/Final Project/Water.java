/*
 * Water.java
 *
 * Created on July 20, 2002, 10:10 AM
 */
import java.util.*;
/**
 *
 * @author  adam
 * @version 1.0
 */
public class Water extends Tile{
    
    /** Creates a new instance of Water */
    public Water() {
		energy = 250;
		energydecro = 2;
		energyincro = 5;
		MaxEnergy = 500;
		setType(Water);
    }

	public AIAction getAIAction(Vector v,AIEnvironment env){
		AIAction act = new AIAction();
		//We need to see the current environmental conditions to see what we do
		switch(env.getAIEnvironment()){
		case AIEnvironment.Sunny:
			act.setAIAction(AIAction.DecWater,0,energydecro);
			break;
		case AIEnvironment.LightClouds:
			act.setAIAction(AIAction.DecWater,0,energydecro/2);
			break;
		case AIEnvironment.OverCast:
			act.setAIAction(AIAction.IncreaseWater,0,energyincro/2);
			break;
		case AIEnvironment.Raining:
			act.setAIAction(AIAction.IncreaseWater,0,energyincro);
			break;
		default:
			//hikes what is it doing?
			System.out.println("Error environment hasn't been set.");
			return null;
		}
		return act;
	}

	public boolean validateAction(AIAction ai){
		if((ai.getAIAction() == AIAction.TakeWater) ||
			(ai.getAIAction() == AIAction.DecWater) ||
			(ai.getAIAction() == AIAction.IncreaseWater))
		{
			return true;
		}
		return false;
	}

	public void doSendAction(AIAction ai){
		// if were removing water
		if(ai.getAIAction() == AIAction.TakeWater || ai.getAIAction() == AIAction.DecWater)
		{
			energy -= ai.getEnergy();
		}
	}

		
    
}

// vim:ts=4
