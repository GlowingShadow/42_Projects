public class State {

    public int[][] taquin;
    public int totalNbMove;
    public State previousState;
    public int priority;
    public int moveNumber;
    public int realX;
    public int realY;
    public String chaineTaquin;

    public State(int[][] taquin, int totalNbMove, State previousState, int moveNumber, int realX, int realY) {
        this.taquin = taquin;
        this.totalNbMove = totalNbMove;
        this.previousState = previousState;
        if(Taquin.type == 3){
            if(Taquin.algo == 1){
                priority = Taquin.numberCaseMissPlacedTaquinParameter(this.taquin);
            }else if(Taquin.algo == 2){
                priority = Taquin.manhattanDistancePriorityFunction(this.taquin);
            }else if(Taquin.algo == 3){
                priority = Taquin.LinearConflict(this.taquin);
            }else{
                priority = Taquin.manhattanDistancePriorityFunction(this.taquin);
            }
        }else{
            if(Taquin.algo == 1){
                priority = Taquin.numberCaseMissPlacedTaquinParameter(this.taquin) + totalNbMove;
            }else if(Taquin.algo == 2){
                priority = Taquin.manhattanDistancePriorityFunction(this.taquin) + totalNbMove;
            }else if(Taquin.algo == 3){
                priority = Taquin.LinearConflict(this.taquin) + totalNbMove;
            }else{
                priority = Taquin.manhattanDistancePriorityFunction(this.taquin) + totalNbMove;
            }
        }

        this.moveNumber = moveNumber;
        this.realX = realX;
        this.realY = realY;
        ToString();
    }

    void ToString(){
        chaineTaquin = "";
        for(int y = 0; y < taquin.length; y++){
            for(int x = 0; x < taquin[y].length; x++){
                chaineTaquin += taquin[x][y];
            }
        }
    }



}
