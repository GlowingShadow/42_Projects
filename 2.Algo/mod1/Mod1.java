import static java.lang.StrictMath.sqrt;

public class Mod1 {
	private static int pyta(int a, int b){
		return ((int)Math.sqrt((double)(a * a + b * b)));
	}

	private static void print_data(int image[][]){
		for	(int i = 0; i < image.length; ++i){
			for(int j = 0; j < image[i].length;++j){
				if (image[i][j] == 0)
					System.out.print(".");
				else
					System.out.print(image[i][j]);
					// System.out.print("1");
				System.out.print(" ");
			}
			System.out.print("\n");
		}
	}

	private static void calc_sommets(int image[][], int sommets[]){
		for (int i = 0; i <= sommets.length - 3; i += 3){
			for (int k = sommets[i] - (sommets[i+2] / 2); k <= sommets[i] + (sommets[i+2] / 2); k++) {
				for (int l = sommets[i+1] - (sommets[i+2] / 2); l <= sommets[i+1] + (sommets[i+2] / 2); l++) {
					if (k >= 0 && k < image.length && l >=0 && l < image[i].length){
						int dist = pyta(Math.abs(sommets[i] - k), Math.abs(sommets[i+1] - l));
						if (dist <= (sommets[i+2] / 2)){
							int tmp = (sommets[i+2] - 2 * dist);
							if (tmp > image[k][l])
								image[k][l] = tmp;
						}
					}
				}
			}
		}
	}

	public static void main(String[] args){

		// map[i][j] -= cos(ratio hauteur min max)
		int sommets[] = {240, 240, 200, 350, 240, 200, 300, 240, 120};
		// int sommets[] = {240, 240, 200, 350, 240, 200};
		int image[][] = new int [600][600];

		calc_sommets(image, sommets);
		// print_data(image);
		Display fenetre = new Display(image);
	}
}
