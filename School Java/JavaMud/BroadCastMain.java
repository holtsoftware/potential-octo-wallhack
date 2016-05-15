

class BroadCastMain{
	public BroadCastMain(){
	}

	public static void main(String[] args){
		try{
			
			final int port = 24101;
			BroadCastServer server = new BroadCastServer(port);
			server.run();
		}
		catch(Exception e){
			System.err.println("Exception: "+e.getMessage());
		}
	}
}

// vim:ts=4
