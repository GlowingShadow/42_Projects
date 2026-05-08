
import javafx.scene.shape.MeshView;
import javafx.scene.shape.TriangleMesh;

public class Scenario2 {

	static int buff_sea[][] = null;
	static int buff_field[][] = null;
	public static void begin(MeshView sea, int field[][]) {
		if (buff_sea == null) {
			buff_sea = new int[Mod1.SIZEY][Mod1.SIZEX];
		}
		if (buff_field == null) {
			buff_field = new int[Mod1.SIZEY][Mod1.SIZEX];
		}
		for (int i = 0; i < buff_sea.length(); i++) {
			for (int j = 0; j < buff_sea[0].length; j++) {
				buff_sea[i][j] = 0;
				if (j == 0)
					buff_sea[i][j] = -1;
			}
		}
		while (1) {

		}
		System.out.println("Scenario2");
	}
}
