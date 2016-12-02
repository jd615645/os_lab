public class SynchronizedCounter implements Runnable {
	public int c = 0,key = 1;
	public void run() {
		if(key % 2 == 1)
    {
            key++;
            for(int i = 0;i<25000000;i++){
                    c++;
            }
    }else
    {
            key++;
            for(int i = 0;i<25000000;i++){
                    c--;
            }

    }
  }

	public int getValue(){
		return c;
	}

	public static void main(String[] args){
		
		SynchronizedCounter Syc = new SynchronizedCounter();
		Thread thread0 = new Thread(Syc);
		thread0.start();
		Thread thread1 = new Thread(Syc);
		thread1.start();
		Thread thread2 = new Thread(Syc);
		thread2.start();	
		Thread thread3 = new Thread(Syc);
		thread3.start();

		try{
			thread0.join();
			thread1.join();
			thread2.join();
			thread3.join();
		} catch(InterruptedException e) {
			//do nothing
		}
		System.out.printf("(%d)%n", Syc.getValue());
	}

}
