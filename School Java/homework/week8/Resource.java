// Adam Holt
// week 8
// exersize 18.16
// wk8 hwk2: 18.16

    // Exercise outline.
    // A shared resource. Its value attribute should only
    // be adjusted by +1 or -1 via setValue.
    // Used to illustrate race hazards.
class Resource {
    public int getValue(){
        return value;
    }

        // Value should only be changed by 1 at most.
    public void setValue(int v){
		System.out.println("Call to setValue() with "+ v);
        if(Math.abs(value-v) != 1){
            System.out.println("Mismatch: value "+value+" cant be changed to  "+v);
        }
        synchronized(this){
            value = v;
            System.out.println("Value is now " + value);
        }
    }

    private int value;
}
