
import javax.swing.*;
import javax.swing.Timer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;

public class Taquin {

    JFrame frame;

    int[][] initialTaquin;
    public static int[][] endSolution;
    public static int sizeTaquin;
    public static int[][] taquin;
    public static int algo;
    public static int type;
    static int indext;
    static  Timer timer;
    public String endSolutionChaine;
    public StateIDA validIDAPATH;

    public Taquin() {
        algo = 1;
    }

    public void printConsoleTaquin(){
        System.out.println("PRINT TAQUIN----------");
        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
                System.out.print(taquin[x][y]+ " ");
            }
            System.out.println("");
        }
        System.out.println("-----------------");
        numberCaseMissPlaced();
    }

    public void printConsoleTaquinParameter(int[][] taq){
        System.out.println("PRINT TAQUIN Parameter----------");
        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++){
                System.out.print(taq[x][y]+ " ");
            }
            System.out.println("");
        }
        System.out.println("-----------------");
    }

    public void generateEndSolution(){
        endSolution = new int[taquin.length][taquin.length];
        int num = 1;
        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
                if(y == taquin.length - 1 && x == taquin[y].length - 1){
                    endSolution[x][y] = 0;
                }
                else
                    endSolution[x][y] = num;
                num++;
            }
        }
    }

    public void generateEndSolutionWithZeroFirst(){
        endSolution = new int[taquin.length][taquin.length];
        int num = 0;
        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
                endSolution[x][y] = num;
                num++;
            }
        }
    }



    public int[][] copyTaquin(int[][] taq){
        int[][] returnedTaquin = new int[taq.length][taq.length];
        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++){
                    returnedTaquin[x][y] = taq[x][y];
            }
        }
        return  returnedTaquin;
    }


    public void printEndSolution(){
        System.out.println("PRINT END TAQUIN----------");
        for(int y = 0; y < endSolution.length; y++){
            for(int x = 0; x < endSolution[y].length; x++){
                System.out.print(endSolution[x][y]+ " ");
            }
            System.out.println("");
        }
        System.out.println("-----------------");
    }


    int numberCaseMissPlaced(){
        int numberMissPlaced = 0;
        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
               if(endSolution[x][y] != taquin[x][y]){

                    numberMissPlaced++;
               }
            }
        }
        System.out.println("MissPlaced case : " + numberMissPlaced);
        return  numberMissPlaced;
    }

   public static int numberCaseMissPlacedTaquinParameter(int[][] taq){
        int numberMissPlaced = 0;
        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++){
                if(endSolution[x][y] != taq[x][y]){
                    if(taq[x][y] != 0)
                      numberMissPlaced++;
                }
            }
        }
        return  numberMissPlaced;
    }

    public static int manhattanDistancePriorityFunction(int[][] taq){
       int sum = 0;
        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++){
                int num = taq[x][y];
                if(num != 0) {
                    boolean breakState = false;
                    for (int y2 = 0; y2 < endSolution.length; y2++) {
                        for (int x2 = 0; x2 < endSolution[y2].length; x2++) {
                            if (endSolution[x2][y2] == num) {
                                int distance = Math.abs(x - x2) + Math.abs(y - y2);
                                sum += distance;
                                breakState = true;
                                break;
                            }
                        }
                        if (breakState == true)
                            break;
                    }
                }
            }
        }
        return  sum;
    }


    static int[] getPosValTaquin(int[][] taq, int num){
        int[] tab = new int[2];

        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++) {
                if(taq[x][y] == num){
                    tab[0] = x;
                    tab[1] = y;
                    return tab;
                }
            }
        }
        return tab;
    }


    public static int LinearConflict(int [][] taq){
        int manathan = manhattanDistancePriorityFunction(taq);
        int linearConf = 0;
        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++) {
                if (taq[x][y] != 0){
                    if(taq[x][y] != endSolution[x][y]){
                        int[] index = getPosValTaquin(endSolution, taq[x][y]);
                        int yEndSolution = index[1];
                        int xEndsolution = index[0];
                        if(yEndSolution == y){
                            if(xEndsolution > x){
                                for(int i = x+1; i <= xEndsolution; i++){
                                    int numberHere = taq[i][y];
                                    if(numberHere != endSolution[i][y]&& numberHere != 0) {
                                        int[] pos = getPosValTaquin(endSolution, numberHere);
                                        if (pos[1] == y) {
                                            if (pos[0] <= x) {
                                                linearConf++;
                                            }
                                        }
                                    }
                                }
                            }
                            else{
                                for(int i = xEndsolution; i < x; i++){
                                    int numberHere = taq[i][y];
                                    if(numberHere != endSolution[i][y]&& numberHere != 0){
                                        int[] pos = getPosValTaquin(endSolution, numberHere);
                                        if(pos[1] == y){
                                            if(pos[0] >= x){
                                                linearConf++;
                                            }
                                        }
                                    }
                                }
                            }
                    }


                        if(xEndsolution == x) {
                            if(yEndSolution > y){
                                for(int i = y+1; i <= yEndSolution; i++){

                                    int numberHere = taq[x][i];
                                    if(numberHere != endSolution[x][i]&& numberHere != 0) {
                                        int[] pos = getPosValTaquin(endSolution, numberHere);
                                        if (pos[0] == x) {
                                            if (pos[1] <= y) {
                                                linearConf++;
                                            }
                                        }
                                    }
                                }
                            }
                            else{
                                for(int i = yEndSolution; i < y; i++){
                                    int numberHere = taq[x][i];
                                    if(numberHere != endSolution[x][i] && numberHere != 0){
                                        int[] pos = getPosValTaquin(endSolution, numberHere);
                                        if(pos[0] == x){
                                            if(pos[1] >= y){
                                                linearConf++;
                                            }
                                        }
                                    }
                                }
                            }


                        }
                    }

              }
            }
        }
        return (manathan + linearConf);
    }

    int makeMoveTaquin(int number){
        boolean finded = false;
        int realX = 0;
        int realY = 0;

        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
                if(taquin[x][y] == number){
                    finded = true;
                    realX = x;
                    realY = y;
                    break;
                }
            }
            if(finded == true)
                break;
        }

        if(realX + 1 < taquin[realY].length){
            if(taquin[realX + 1][realY] == 0){
                int tmp = taquin[realX + 1][realY];
                taquin[realX + 1][realY] = taquin[realX][realY];
                taquin[realX][realY] = tmp;
                return 1;
            }
        }
        if(realX - 1 >= 0){
            if(taquin[realX - 1][realY] == 0){
                int tmp = taquin[realX - 1][realY];
                taquin[realX - 1][realY] = taquin[realX][realY];
                taquin[realX][realY] = tmp;
                return 1;
            }
        }
        if(realY + 1 < taquin.length){
            if(taquin[realX][realY + 1] == 0){
                int tmp = taquin[realX][realY + 1];
                taquin[realX][realY + 1] = taquin[realX][realY];
                taquin[realX][realY] = tmp;
                return 1;
            }
        }
        if(realY - 1 >= 0){
            if(taquin[realX][realY - 1] == 0){
                int tmp = taquin[realX][realY - 1];
                taquin[realX][realY - 1] = taquin[realX][realY];
                taquin[realX][realY] = tmp;
                return 1;
            }
        }

        return 0;
    }



    void fillFrame(JFrame frame){
        frame.getContentPane().removeAll();
        ActionListener taquinClick = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int number = Integer.parseInt(((JButton) e.getSource()).getText());
                int move = makeMoveTaquin(number);
                if(move == 0)
                    System.out.println("Cant move this case");
                fillFrame(frame);
            }
        };

        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
                JButton button = new JButton(taquin[x][y] +"");
                frame.getContentPane().add(button);
                if(taquin[x][y] == 0)
                    button.setVisible(false);
                button.addActionListener(taquinClick);
            }
        }
         frame.revalidate();
        frame.repaint();
    }

    boolean sameTaquin(int[][] taq1, int [][] taq2){
        for(int y = 0; y < taq1.length; y++){
            for(int x = 0; x < taq1[y].length; x++){
                if(taq1[x][y] != taq2[x][y]){
                    return  false;
                }
            }
        }
        return true;
    }


    ArrayList<State> findNeighbour(State state, String taquinChaine){

        ArrayList<State> neighbour = new ArrayList<State>();
        boolean finded = false;

        int[][] taq = state.taquin;
        int realX = state.realX;//0;
        int realY = state.realY;//0;

        if(realX + 1 < taq[realY].length && state.moveNumber != taq[realX + 1][realY]){

            int[][] copyTaq = copyTaquin(taq);

            int moveNumber = copyTaq[realX + 1][realY];

            int tmp = copyTaq[realX + 1][realY];
            copyTaq[realX + 1][realY] = copyTaq[realX][realY];
            copyTaq[realX][realY] = tmp;

                State newState = new State(copyTaq, state.totalNbMove + 1, state, moveNumber, realX + 1, realY);
                neighbour.add(newState);
        }

        if(realX - 1 >= 0 && state.moveNumber != taq[realX - 1][realY]){
            int[][] copyTaq = copyTaquin(taq);

            int moveNumber = copyTaq[realX - 1][realY];

                int tmp = copyTaq[realX - 1][realY];
                copyTaq[realX - 1][realY] = copyTaq[realX][realY];
                copyTaq[realX][realY] = tmp;

                State newState = new State(copyTaq, state.totalNbMove + 1, state, moveNumber, realX -1, realY);
                neighbour.add(newState);
        }

        if(realY + 1 < taq.length && state.moveNumber != taq[realX][realY + 1]){
            int[][] copyTaq = copyTaquin(taq);

            int moveNumber =  copyTaq[realX][realY + 1];

                int tmp = copyTaq[realX][realY + 1];
                copyTaq[realX][realY + 1] = copyTaq[realX][realY];
                copyTaq[realX][realY] = tmp;

                State newState = new State(copyTaq, state.totalNbMove + 1, state, moveNumber, realX, realY + 1);
                neighbour.add(newState);
        }

        if(realY - 1 >= 0 && state.moveNumber != taq[realX][realY - 1]){
            int[][] copyTaq = copyTaquin(taq);

            int moveNumber = copyTaq[realX][realY - 1];

                int tmp = copyTaq[realX][realY - 1];
                copyTaq[realX][realY - 1] = copyTaq[realX][realY];
                copyTaq[realX][realY] = tmp;

                State newState = new State(copyTaq, state.totalNbMove + 1, state, moveNumber, realX, realY - 1);
                neighbour.add(newState);
        }

        return  neighbour;
    }

    int[] getRealyXRealY(int[][] taq){
        int[] tab = new int[2];

        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++){
                if(taq[x][y] == 0){
                    tab[0] = x;
                    tab[1] = y;
                    return tab;
                }
            }
        }

        return  tab;
    }



    ArrayList<StateIDA> findNeighbourIDA(StateIDA node){

        ArrayList<StateIDA> neighbour = new ArrayList<StateIDA>();

        int[][] taq = node.taquin;
        int realX = node.xZero;//0;
        int realY = node.yZero;//0;

        if(realX + 1 < taq[realY].length && node.moveNumber != taq[realX + 1][realY]){

            int[][] copyTaq = copyTaquin(taq);

            int moveNumber = copyTaq[realX + 1][realY];

            int tmp = copyTaq[realX + 1][realY];
            copyTaq[realX + 1][realY] = copyTaq[realX][realY];
            copyTaq[realX][realY] = tmp;

            StateIDA addedNode = new StateIDA(copyTaq, realX + 1, realY, node, node.totalNbMove + 1, moveNumber);
            neighbour.add(addedNode);
        }

        if(realX - 1 >= 0 && node.moveNumber != taq[realX - 1][realY]){
            int[][] copyTaq = copyTaquin(taq);

            int moveNumber = copyTaq[realX - 1][realY];

            int tmp = copyTaq[realX - 1][realY];
            copyTaq[realX - 1][realY] = copyTaq[realX][realY];
            copyTaq[realX][realY] = tmp;

            StateIDA addedNode = new StateIDA(copyTaq, realX - 1, realY, node, node.totalNbMove + 1, moveNumber);
            neighbour.add(addedNode);
        }

        if(realY + 1 < taq.length && node.moveNumber != taq[realX][realY + 1]){
            int[][] copyTaq = copyTaquin(taq);

            int moveNumber =  copyTaq[realX][realY + 1];

            int tmp = copyTaq[realX][realY + 1];
            copyTaq[realX][realY + 1] = copyTaq[realX][realY];
            copyTaq[realX][realY] = tmp;

            StateIDA addedNode = new StateIDA(copyTaq, realX, realY + 1, node, node.totalNbMove + 1, moveNumber);
            neighbour.add(addedNode);
        }

        if(realY - 1 >= 0 && node.moveNumber != taq[realX][realY - 1]){
            int[][] copyTaq = copyTaquin(taq);

            int moveNumber = copyTaq[realX][realY - 1];

            int tmp = copyTaq[realX][realY - 1];
            copyTaq[realX][realY - 1] = copyTaq[realX][realY];
            copyTaq[realX][realY] = tmp;

            StateIDA addedNode = new StateIDA(copyTaq, realX, realY - 1, node, node.totalNbMove + 1, moveNumber);
            neighbour.add(addedNode);
        }
        return  neighbour;
    }


    int searchIDA(ArrayList<StateIDA> path, int g, int bound){
        StateIDA node = path.get(path.size() - 1);

        int f = g;
        if(algo == 1)
            f += numberCaseMissPlacedTaquinParameter(node.taquin);
        else if(algo == 2)
            f += manhattanDistancePriorityFunction(node.taquin);
        else if(algo == 3)
            f += LinearConflict(node.taquin);
        if(f > bound){
            //counter two
            return f;
        }
        if(IsTheSameTaquin(node.chaineTaquin, endSolutionChaine)){
            validIDAPATH = node;
            return -1;
        }
        int min = 5000;//MAX
        ArrayList<StateIDA> neighbour = findNeighbourIDA(node);
        for(int i = 0; i < neighbour.size(); i++){
            boolean inPath = false;
            for(int b = 0; b < path.size(); b++){
                if(IsTheSameTaquin(neighbour.get(i).chaineTaquin, path.get(b).chaineTaquin) == true){
                    inPath = true;
                    break;
                }
            }
            if(!inPath){
                path.add(neighbour.get(i));
                int t = searchIDA(path, g + 1, bound);
                if(t == -1){
                    return  -1;
                }
                if(t < min){
                    min = t;
                }
                path.remove(path.size() - 1);
            }
        }
        return min;
    }

    int startIDA(StateIDA root){
        int bound = manhattanDistancePriorityFunction(root.taquin);
        ArrayList<StateIDA> path = new ArrayList<StateIDA>();
        path.add(root);
        while(true){
            int minimumBoundExceed = searchIDA(path, 0, bound);
            if(minimumBoundExceed == -1) {
                System.out.println("MOVE : "+bound);
                return 1;
            }
            if(minimumBoundExceed == 5000/*or max bound value WANTED*/)
            {
                //System.out.println("WRONG PATH");
                return 0;
            }
            bound = minimumBoundExceed;
        }
    }

    void solveIDASTAR(){
        if(sameTaquin(taquin, endSolution)) {
            System.out.println("Already Solved");
            return;
        }
        int[][] taquinCopied = copyTaquin(taquin);
        int[] tab = getRealyXRealY(taquinCopied);
        StateIDA root = new StateIDA(taquinCopied, tab[0], tab[1], null, 0,0);

       long start = System.currentTimeMillis();
       int launch = startIDA(root);
       if(launch == 0){
           System.out.println("Use <Zero change features>");
           return;
       }
        long end = System.currentTimeMillis();
        NumberFormat formatter = new DecimalFormat("#0.00000");
        System.out.println("Execution time is " + formatter.format((end - start) / 1000d) + " seconds");
        ArrayList<int[][]> listGoodMove = new ArrayList<int[][]>();
        ArrayList<Integer> movement = new ArrayList<Integer>();
        while (validIDAPATH.previousStateIDA != null){
            listGoodMove.add(validIDAPATH.taquin);
            movement.add(validIDAPATH.moveNumber);
            validIDAPATH = validIDAPATH.previousStateIDA;

        }
        indext = 0;
        int delay = 300;
        ActionListener taskPerformer = new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                makeMoveTaquin(movement.get((movement.size() - 1) - indext));
                fillFrame(frame);
                indext++;
                if(indext >= movement.size())
                    timer.stop();

            }
        };

        timer = new Timer(delay, taskPerformer);
        timer.setRepeats(true);
        if(movement.size() > 0)
            timer.start();
    }


    void solveTaquin(){

        if(sameTaquin(taquin, endSolution)) {
            System.out.println("Already Solved");
            return;
        }
        int[][] taquinCopied = copyTaquin(taquin);
        int[] tab = getRealyXRealY(taquinCopied);
        State state = new State(taquinCopied, 0, null, 0, tab[0], tab[1]);

        ArrayList<State> listNeigbhour;// = findNeighbour(state);


        State currentState = state;
        boolean success = false;
        ArrayList<Integer> listPriority = new ArrayList<Integer>();
        Queue priorityQueue = new Queue();
        priorityQueue.queue.add(state);

        listPriority.add(state.priority);


        priorityQueue.numberStateEver++;
        ArrayList<State> closedList = new ArrayList<State>();

        State validMove = null;

        boolean findedLowest = false;
        int indexLowesPrio = indexLowestPriority(priorityQueue) ;

        boolean needToFindIndexLowestPrio = false;
        currentState = priorityQueue.queue.get(indexLowesPrio);

        long startTime = System.currentTimeMillis();
        while(!priorityQueue.queue.isEmpty() && success == false){
            if(priorityQueue.queue.size() > priorityQueue.numberStateEverAtTheSameTime)
                priorityQueue.numberStateEverAtTheSameTime = priorityQueue.queue.size();

            /*
            if(priorityQueue.numberStateEver % 10000 == 0){
                System.out.println("MOVE : "+currentState.totalNbMove+" ite : "+priorityQueue.numberStateEver);
            }*/

            if(needToFindIndexLowestPrio == true) {
                indexLowesPrio = listPriority.indexOf(Collections.min(listPriority));//indexLowestPriority(priorityQueue);
                currentState = priorityQueue.queue.get(indexLowesPrio);
            }

            needToFindIndexLowestPrio = true;

            closedList.add(currentState);

            priorityQueue.queue.remove(indexLowesPrio);
            listPriority.remove(indexLowesPrio);

            listNeigbhour = findNeighbour(currentState, currentState.chaineTaquin);

            for(int i = 0; i < listNeigbhour.size(); i++){

                if(IsTheSameTaquin(listNeigbhour.get(i).chaineTaquin, endSolutionChaine) == true){
                    validMove = listNeigbhour.get(i);
                    success = true;
                    break;
                }

                boolean inClosed = false;
                boolean inOpen = false;
                int indexClosed = 0;
                int indexOpen = 0;
               for(int b = 0; b < closedList.size(); b++){
                    if(IsTheSameTaquin(closedList.get(b).chaineTaquin, listNeigbhour.get(i).chaineTaquin) == true){
                        inClosed = true;
                        indexClosed = b;
                        break;
                    }
                }
                for(int d = 0; d < priorityQueue.queue.size(); d++){

                    if(IsTheSameTaquin(priorityQueue.queue.get(d).chaineTaquin, listNeigbhour.get(i).chaineTaquin) == true){
                        inOpen = true;
                        indexOpen = d;
                        break;
                    }
                }

                boolean doit = false;

                if(inClosed == false && inOpen == false) {
                    priorityQueue.queue.add(listNeigbhour.get(i));
                    listPriority.add(listNeigbhour.get(i).priority);
                    priorityQueue.numberStateEver++;
                    doit = true;
                }
                else if(inOpen == true && priorityQueue.queue.get(indexOpen).priority > listNeigbhour.get(i).priority){
                    priorityQueue.queue.remove(indexOpen);
                    listPriority.remove(indexOpen);
                    priorityQueue.queue.add(listNeigbhour.get(i));
                    listPriority.add(listNeigbhour.get(i).priority);
                    priorityQueue.numberStateEver++;
                    doit = true;
                }else if(inClosed == true && closedList.get(indexClosed).priority > listNeigbhour.get(i).priority){
                    closedList.remove(indexClosed);
                    priorityQueue.queue.add(listNeigbhour.get(i));
                    listPriority.add(listNeigbhour.get(i).priority);
                    priorityQueue.numberStateEver++;
                    doit = true;
                }

                if(doit == true) {
                    if (listNeigbhour.get(i).priority <= currentState.priority) {
                        currentState = listNeigbhour.get(i);
                        needToFindIndexLowestPrio = false;
                        indexLowesPrio = priorityQueue.queue.size() - 1;
                    }
                }
            }
        }
        if(validMove == null){
            System.out.println("Use <Zero change features>");
            return;
        }

        long end = System.currentTimeMillis();

        NumberFormat formatter = new DecimalFormat("#0.00000");
        System.out.println("Execution time is " + formatter.format((end - startTime) / 1000d) + " seconds");
        System.out.println("Number State Ever Represented at the same time : "+ priorityQueue.numberStateEverAtTheSameTime);
        System.out.println("Number State take in open : "+ priorityQueue.numberStateEver);
        System.out.println("Number of moves to succeed : " + validMove.totalNbMove);

       ArrayList<int[][]> listGoodMove = new ArrayList<int[][]>();
        ArrayList<Integer> movement = new ArrayList<Integer>();
        while (validMove.previousState != null){
            listGoodMove.add(validMove.taquin);
            movement.add(validMove.moveNumber);
            validMove = validMove.previousState;

        }

        indext = 0;

        int delay = 300;
        ActionListener taskPerformer = new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                makeMoveTaquin(movement.get((movement.size() - 1) - indext));
                fillFrame(frame);
                indext++;
                if(indext >= movement.size())
                    timer.stop();

            }
        };

        timer = new Timer(delay, taskPerformer);
        timer.setRepeats(true);
        if(movement.size() > 0)
            timer.start();
    }

    int indexLowestPriority(Queue queue){
        int indexLowest = 0;
        int priorityLowest = 0;
        boolean start = true;
        for(int i = 0; i < queue.queue.size(); i++){
            if(start == true){
                indexLowest = i;
                priorityLowest = queue.queue.get(i).priority;
                start = false;
            }else{
                if(queue.queue.get(i).priority < priorityLowest){
                    indexLowest = i;
                    priorityLowest = queue.queue.get(i).priority;
                }
            }
        }

        return indexLowest;
    }
    public static boolean equals(final String s1, final String s2) {
        return s1 != null && s2 != null && s1.hashCode() == s2.hashCode()
                && s1.equals(s2);
    }

    boolean IsTheSameTaquin(String s1, String s2){
       return s1.hashCode() == s2.hashCode()
                && s1.equals(s2);
    }

    String ToStringAll(int[][] taq){
        String chaine = "";
        for(int y = 0; y < taq.length; y++){
            for(int x = 0; x < taq[y].length; x++){
                chaine += taq[x][y];
            }
        }
        return  chaine;
    }



    void ToStringEndSolution(){
        endSolutionChaine = "";
        for(int y = 0; y < endSolution.length; y++){
            for(int x = 0; x < endSolution[y].length; x++){
                endSolutionChaine += endSolution[x][y];
            }
        }
    }


    int getTotalInversionCount()
    {
        int[] arr = new int[taquin.length * taquin.length];

        int index = 0;
        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++) {
                arr[index] = taquin[x][y];
                index++;
            }
        }
        int inv_count = 0;
       for (int i = 0; i < (taquin.length * taquin.length) - 1; i++)
            for (int j = i+1; j < (taquin.length * taquin.length); j++)
                if (arr[j] != 0 && arr[i]!=0 && arr[i] > arr[j])
                    inv_count++;
        return inv_count;
    }




    boolean isTaquinSolvable(){
        int inversionCount = getTotalInversionCount();
        System.out.println("TotalInversion : "+inversionCount);
        return  (inversionCount % 2 == 0);
    }

    public void initGame(){
        
        initialTaquin = copyTaquin(taquin);
     //   generateEndSolution();
        generateEndSolutionWithZeroFirst();
        ToStringEndSolution();

        if(isTaquinSolvable() == false){
            System.out.println("Puzzle not valid, try another one");
            return;
        }else{
            System.out.println("Puzzle is Valid");
        }

         frame = new JFrame("Taquin");
        frame.setVisible(true);
        frame.setSize(600,600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        GridLayout grid = new GridLayout(taquin.length, taquin.length);
        frame.setLayout(grid);

        JMenuBar menuBar = new JMenuBar();
        JMenuItem resetButton = new JMenuItem("Reset");

        JRadioButtonMenuItem hamming = new JRadioButtonMenuItem("Hamming");
        JRadioButtonMenuItem manhattan = new JRadioButtonMenuItem("Manhattan");
        JRadioButtonMenuItem linearconflict = new JRadioButtonMenuItem("LC");
        manhattan.setSelected(true);
        algo = 2;
        ButtonGroup btg = new ButtonGroup();

        btg.add(hamming);
        btg.add(manhattan);
        btg.add(linearconflict);

        ActionListener chooseHamming = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// Hamming Heuristic selected //");
                algo = 1;
            }
        };

        ActionListener chooseManhatan = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// Manhattan Heuristic selected //");
                algo = 2;
            }
        };

        ActionListener chooseLinearConflit = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// Linear Conflict Heuristic selected //");
                algo = 3;
            }
        };

        hamming.addActionListener(chooseHamming);
        manhattan.addActionListener(chooseManhatan);
        linearconflict.addActionListener(chooseLinearConflit);
        menuBar.add(hamming);
        menuBar.add(manhattan);
        menuBar.add(linearconflict);

        JRadioButtonMenuItem aStar = new JRadioButtonMenuItem("A*");
        JRadioButtonMenuItem itastar = new JRadioButtonMenuItem("IDA*");
        JRadioButtonMenuItem bfsearch = new JRadioButtonMenuItem("BFS");
        ButtonGroup btg2 = new ButtonGroup();
        btg2.add(aStar);
        btg2.add(itastar);
        btg2.add(bfsearch);
        itastar.setSelected(true);
        type = 2;

        ActionListener chooseAstar = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// A* Algo selected //");
                type = 1;
            }
        };
        ActionListener chooseITAstar = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// IDA* Algo selected //");
                type = 2;
            }
        };
        ActionListener chooseBFS = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// Best First Search Algo selected //");
                type = 3;
            }
        };

        aStar.addActionListener(chooseAstar);
        itastar.addActionListener(chooseITAstar);
        bfsearch.addActionListener(chooseBFS);

        menuBar.add(aStar);
        menuBar.add(itastar);
        menuBar.add(bfsearch);

        JMenuItem solve = new JMenuItem("Solve");


        ActionListener chooseSolve = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("// Solve //");
                if(type == 1){
                    solveTaquin();
                }else if(type == 2){
                    solveIDASTAR();
                }else if(type == 3){
                    solveTaquin();
                }
            }
        };
        solve.addActionListener(chooseSolve);
        menuBar.add(solve);


        ActionListener resetAction = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("RESET");
                taquin = copyTaquin(initialTaquin);
                fillFrame(frame);
            }
        };
        resetButton.addActionListener(resetAction);
        menuBar.add(resetButton);

        JRadioButtonMenuItem normalResolution = new JRadioButtonMenuItem("");
        normalResolution.setSelected(false);
        ActionListener emptyChange = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("//Empty Case Change//");
                if(normalResolution.isSelected()){
                    System.out.println("//Zero End//");
                    generateEndSolution();
                    ToStringEndSolution();
                }
                else{
                    System.out.println("//Zero first//");
                    generateEndSolutionWithZeroFirst();
                    ToStringEndSolution();
                }
            }
        };
        normalResolution.addActionListener(emptyChange);
        menuBar.add(normalResolution);


        frame.setJMenuBar(menuBar);

        fillFrame(frame);

        frame.setBackground(Color.YELLOW);

    }

}
