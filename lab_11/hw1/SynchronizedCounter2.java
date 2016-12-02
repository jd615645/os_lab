public class SynchronizedCounter2{
  public int c = 0;

  public synchronized void Inc() {
    for(int i = 0;i<25000000;i++){
      c++;
    }
  }

  public synchronized void Dec() {
    for(int i = 0;i<25000000;i++){
      c--;
    }
  }


  public int getValue(){
    return c;
  }

  public static void main(String[] args){

    final SynchronizedCounter2 Syc = new SynchronizedCounter2();
    Thread thread0 = new Thread(new Runnable() {  public void run() {  Syc.Inc();}});
    thread0.start();
    Thread thread1 = new Thread(new Runnable() {  public void run() {  Syc.Dec();}});
    thread1.start();
    Thread thread2 = new Thread(new Runnable() {  public void run() {  Syc.Inc();}});
    thread2.start();
    Thread thread3 = new Thread(new Runnable() {  public void run() {  Syc.Dec();}});
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
