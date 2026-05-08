public class StateIDA {

    public int[][] taquin;
    public int xZero;
    public int yZero;

    public StateIDA previousStateIDA;
    public int totalNbMove;
    public int moveNumber;
    public String chaineTaquin;


    public StateIDA(int[][] taquin, int xZero, int yZero, StateIDA previousStateIDA, int totalNbMove, int moveNumber) {
        this.taquin = taquin;
        this.xZero = xZero;
        this.yZero = yZero;
        this.previousStateIDA = previousStateIDA;
        this.totalNbMove = totalNbMove;
        this.moveNumber = moveNumber;
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
