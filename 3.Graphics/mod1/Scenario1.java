
import javafx.scene.shape.MeshView;
import javafx.scene.shape.TriangleMesh;

public class Scenario1 {

	public static MeshView create_sea2() {

		float[] texCoords
			= {
				0.5f, 0.5f, 0.0f,
				0.8f, 0.8f, 0.8f
			};

		int image[][] = new int[Mod1.SIZEY][Mod1.SIZEX];
		for (int i = 0; i < Mod1.SIZEY; i++) {
			for (int j = 0; j < Mod1.SIZEX; j++) {
				image[i][j] = -1;
			}
		}

		float[] points = Mod1.create_vertex(image);
		int[] faces = Mod1.create_faces(points, (Mod1.SIZEY - 1) * (Mod1.SIZEX - 1) * 2, Mod1.SIZEX);

		// Create a TriangleMesh
		TriangleMesh mesh = new TriangleMesh();
		mesh.getPoints().addAll(points);
		mesh.getTexCoords().addAll(texCoords);
		mesh.getFaces().addAll(faces);

		// Create a NeshView
		MeshView meshView = new MeshView();
		meshView.setMesh(mesh);
		return meshView;
	}
	static int buff_field[][] = null;

	private static void rec(MeshView sea, int field[][], int height) {

		System.out.print(height);
		for (int xi = 0; xi < field[0].length; xi++) {
			for (int yi = 0; yi < field.length; yi++) {
				buff_field[xi][yi] = 0;
				if (xi == 0 || yi == 0) {
					buff_field[xi][yi] = 1;
				}

			}
		}
		buff_field[0][0] = 1;
		int fill = 0;
		System.out.print("\n->");

		do {
			int x, y;
			fill = 0;
			for (x = 1; x < field[0].length; x++) {
				for (y = 1; y < field.length; y++) {
					if (buff_field[x][y] == 0 && field[x][y] < height && ((buff_field[x - 1][y] == 1) || (y > 0 && buff_field[x][y - 1] == 1))) {
						buff_field[x][y] = 1;
						((TriangleMesh) (sea.getMesh())).getPoints().set(((x * field.length * 3) + y * 3 + 2), -height);
						fill++;
					}
				}
			}
			if (fill < 200) {
				return;
			}
						System.out.print(fill);

			fill = 0;
			System.out.print(fill);
			for (x--; x > 0; x--) {
				for (y = field.length - 1; y > 0; y--) {

					if (buff_field[x][y] == 0 && field[x][y] < height && ((x + 1 < field[0].length && buff_field[x + 1][y] == 1) || (y < field.length - 1 && buff_field[x][y + 1] == 1))) {
						buff_field[x][y] = 1;
						((TriangleMesh) (sea.getMesh())).getPoints().set(((x * field.length * 3) + y * 3 + 2), -height);
						fill++;
					}
				}
			}
			System.out.print(" ");

			System.out.print(fill);
			System.out.print("\n");

			if (fill < 200) {
				return;
			}
		} while (true);
		/*			if (x >= 0 && x < field.length && y >= 0 && y < field[0].length) {
				if (field[x][y] < height && ((TriangleMesh) (sea.getMesh())).getPoints().get((y * field.length * 3) + x * 3 + 2) < height) {

					((TriangleMesh) (sea.getMesh())).getPoints().set(((y * field.length * 3) + x * 3 + 2), height);
					rec(x + 1, y, sea, field, height);
					rec(x - 1, y, sea, field, height);
					rec(x, y + 1, sea, field, height);
					rec(x, y - 1, sea, field, height);
				}
			}*/
	}

	public static void super_rechercheur_de_collines(MeshView sea, int field[][], int height) {
		if (buff_field == null) {
			buff_field = new int[Mod1.SIZEY][Mod1.SIZEX];
		}
		rec(sea, field, height + 70);
	}
}
