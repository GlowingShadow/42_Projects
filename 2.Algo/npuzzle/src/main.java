import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class main {

    public static Taquin theTaquin;

    public static void main (String[] args) {


        if(args.length != 1){
            System.out.println("Only 1 arg, with name of taquin file");
            return;
        }

        System.out.println("Reading file...");
        try {
            theTaquin = new Taquin();
            BufferedReader reader = new BufferedReader(new FileReader(args[0]));

                boolean sizeFind = false;
                String line = "";
                int size = 0;
                theTaquin.sizeTaquin = 0;
                int[][] taquin = null;//new int[size][size];
                int y = 0;
                while ((line = reader.readLine()) != null) {
                    if(sizeFind == false){
                        line = line.trim().replaceAll(" +", " ");
                        String tab[] = line.split(" ");
                        if(tab[0].charAt(0) != '#'){
                            int theSize = Integer.parseInt(tab[0]);
                            size = theSize;
                            if (size < 2) {
                                System.out.println("Size to small(min 2)");
                                return;
                            }
                            theTaquin.sizeTaquin = size;
                            taquin = new int[size][size];
                            y = 0;
                            sizeFind = true;
                        }
                    }else {
                        line = line.trim().replaceAll(" +", " ");
                        String tab[] = line.split(" ");
                        if(tab[0].charAt(0) != '#') {
                            if (tab.length < size) {
                                System.out.println("There was an error while reading the file .");
                                return;
                            }
                            for (int i = 0; i < size; i++) {
                                String info = tab[i];
                                taquin[i][y] = Integer.parseInt(info);
                                if (taquin[i][y] >= size * size || taquin[i][y] < 0) {
                                    System.out.println("There was an error while reading the file .");
                                    return;
                                }
                            }
                            y++;
                        }
                    }
                }
                theTaquin.taquin = taquin;

        }catch (FileNotFoundException e){
            System.out.println("Couldn't find file");
           return;
        }catch (IOException e) {
            System.out.println("There was an error while reading the file");
           return;
        }
        catch (NumberFormatException e){
            System.out.println("There was an error while reading the file");
            return;
        }
        System.out.println("Successful reading!");
        theTaquin.initGame();
    }
}
