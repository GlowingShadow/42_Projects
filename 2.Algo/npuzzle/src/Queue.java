import java.util.ArrayList;

public class Queue {

    public ArrayList<State> queue;
    public int numberStateEver;
    public int numberStateEverAtTheSameTime;

    public Queue() {
            this.queue = new ArrayList<State>();
            numberStateEver = 0;
            numberStateEverAtTheSameTime = 0;
    }

}
