// Adam Holt
// lab 1
// ex 18.12
// week8
//
// lab 2
// ex 18.13
// week8

public class ResourceSharing{
	public static void main(String []args)
	{
		Resource res = new Resource();

		new Thread(new Incrementor(res)).start();
		new Thread(new Decrementor(res)).start();
	}
}

class Incrementor implements Runnable{
	public Incrementor(Resource res)
	{
		myres=res;
	}

	public void run(){
		
		while(true)
		{
			if(myres.getValue() != 1)
					//Thread.yield();
				myres.setValue(1);
		}
		
	}
	
	private Resource myres;
}

class Decrementor implements Runnable{
	public Decrementor(Resource res)
	{
		myres = res;
	}

	public void run(){
		while(true){
			if(myres.getValue() != 0)
				//Thread.yield();
				myres.setValue(0);
		}
	}

	private Resource myres;
}

/*   lab1 output
Call to setValue() with 0
Call to setValue() with 1
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Mismatch: value 0 cant be changed to  0
Value is now 0
Call to setValue() with 0
Value is now 1
Value is now 0
Call to setValue() with 1
Call to setValue() with 0
Value is now 1
Value is now 0
*/

/* lab2 output
Call to setValue() with 1
Value is now 1
Call to setValue() with 0
Value is now 0
Call to setValue() with 1
Value is now 1
Call to setValue() with 0
Value is now 0
Call to setValue() with 1
Value is now 1
Call to setValue() with 0
Value is now 0
Call to setValue() with 1
Value is now 1
Call to setValue() with 0
Value is now 0
*/
