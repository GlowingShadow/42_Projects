import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.PerspectiveCamera;
import javafx.scene.PointLight;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.MeshView;
import javafx.scene.shape.TriangleMesh;
import javafx.scene.transform.Rotate;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.KeyCode;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.CullFace;
import javafx.scene.AmbientLight;
import java.lang.*;
import javafx.animation.Timeline;
import javafx.animation.KeyFrame;


public class Mod1 extends Application {

	public static final int	SIZEX = 600;
	public static final int	SIZEY = 600;
	private final int	WIN_X = 800;
	private final int	WIN_Y = 800;
	private final int	MAX_Z = SIZEX / 3;
	private static  int [][]image=null;
	private static int height =-1;


	private static int pyta(int a, int b) {
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
		System.out.println("begin");
		for (int i = 0; i <= sommets.length - 3; i += 3){
			System.out.print("i = ");
			System.out.println(i);
			for (int k = sommets[i] - (sommets[i+2]); k <= sommets[i] + (sommets[i+2]); k++) {
				for (int l = sommets[i+1] - (sommets[i+2]); l <= sommets[i+1] + (sommets[i+2]); l++) {
					if (k >= 0 && k < image.length && l >=0 && l < image[i].length){
						int dist = pyta(Math.abs(sommets[i] - k), Math.abs(sommets[i+1] - l));
						if (dist <= (sommets[i+2])){
							int tmp = (sommets[i+2] - dist);
								// if ( k == sommets[i+1] ){System.out.print(tmp);System.out.print("/");System.out.print((double)sommets[i+2]);System.out.print(" ");
								// 	System.out.println((double)tmp / (double)sommets[i+2]);}
								// tmp = (int) ((double)tmp * Math.cos( (double)tmp / (double)sommets[i+2]) * Math.PI /2. );
							if (tmp > image[k][l])
								image[k][l] = tmp;
						}
					}
				}
			}
		}
	}

	private static int[][] blur_map(int image[][]){
		System.out.println("blur begin");
		int rayon = 10;
		int	speed = rayon / 20 + 1;
		int	newmap[][] = new int[image.length][image[0].length];
		for (int i = 0; i < image.length; i++) {
			// System.out.println(i);
			for (int j = 0; j < image[0].length; j++) {
				// System.out.println(j);
				int moyenne = 0;
				int n = 0;
				for (int k = i - rayon; k < i + rayon; k += speed) {
					for (int l = j - rayon; l < j + rayon; l += speed) {
						if (k >= 0 && l >= 0 && k < image.length && k < image.length && l < image[0].length) {
							if (pyta(Math.abs(i - k), Math.abs(j - l)) <= rayon) {
								moyenne += image[k][l];
							}
						}
						n++;
					}
				}
				newmap[i][j] = moyenne / n;
			}
		}
		for (int i = 0; i < newmap.length; i++) {
			for (int j = 0; j < newmap[0].length; j++) {
				if (j < 10 || j > newmap[0].length - 10 || i < 10 || i > newmap.length - 10)
					newmap[i][j] = 0;
			}
		}
		// print_data(newmap);
		return newmap;
	}

	public static void main(String[] args)
	{
		Application.launch(args);
	}

	@Override
	public void start(Stage stage)
	{
		// Create a MeshView
		MeshView meshView = this.create_field();
		meshView.setMaterial(new PhongMaterial(Color.LIGHTGREEN));
		meshView.setCullFace(CullFace.NONE);
		meshView.setTranslateX(-SIZEX / 2);
		meshView.setTranslateY(-SIZEY / 2);
		meshView.setTranslateZ(0);
		meshView.setRotationAxis(Rotate.Y_AXIS);

		MeshView sea = Scenario1.create_sea2();
		sea.setMaterial(new PhongMaterial(Color.LIGHTBLUE));
		sea.setCullFace(CullFace.NONE);
		sea.setTranslateX(-SIZEX / 2);
		sea.setTranslateY(-SIZEY / 2);
		sea.setTranslateZ(0);

		// Scale the Meshview to make it look bigger
		meshView.setScaleX(1.0);
		meshView.setScaleY(1.0);
		meshView.setScaleZ(1.0);

		// Create a Camera to view the 3D Shapes
		PerspectiveCamera camera = new PerspectiveCamera(false);
		camera.setTranslateX(-SIZEX / 2);
		camera.setTranslateY(-SIZEX / 2);
		camera.setTranslateZ(-300);
		camera.setRotationAxis(Rotate.X_AXIS);
		camera.setRotate(60);

		// Create the Lights
		// PointLight redLight = new PointLight();
		AmbientLight  redLight = new AmbientLight ();
		redLight.setColor(Color.WHITE);
		redLight.setTranslateX(250);
		redLight.setTranslateY(150);
		redLight.setTranslateZ(300);

		PointLight greenLight = new PointLight();
		//greenLight.setColor(Color.RED);
		greenLight.setTranslateX(200);
		greenLight.setTranslateY(-2350);
		greenLight.setTranslateZ(-450);

		// Add the Shapes and the Light to the Group
		Group root = new Group(meshView, sea, redLight, greenLight);

		// Create a Scene with depth buffer enabled
		Scene scene = new Scene(root, WIN_X, WIN_Y, true);
		scene.setCamera(camera);

		stage.setScene(scene);
		stage.setTitle("An Example using a TriangleMesh");
		stage.show();

		Rotate rotateX = new Rotate(0, Rotate.X_AXIS);
		Rotate rotateY = new Rotate(0, Rotate.Y_AXIS);
		Rotate rotateZ = new Rotate(0, Rotate.Z_AXIS);
		root.getTransforms().addAll(rotateX, rotateY, rotateZ);
		key_hook(scene, camera, root, rotateX, rotateY, rotateZ, sea);

	}

	static Timeline timeline;
	private static void key_hook(Scene scene, PerspectiveCamera cam, Group root, Rotate rotateX, Rotate rotateY, Rotate rotateZ, MeshView sea) {
		scene.addEventHandler(KeyEvent.KEY_PRESSED, (key) -> {
			System.out.println(key.getCode());

			if (key.getCode() == KeyCode.ESCAPE)
				System.exit(0);
			else if (key.getCode() == KeyCode.D)
				cam.setTranslateX(cam.getTranslateX() + 10);
			else if (key.getCode() == KeyCode.A)
				cam.setTranslateX(cam.getTranslateX() - 10);
			else if (key.getCode() == KeyCode.W)
				cam.setTranslateY(cam.getTranslateY() - 10);
			else if (key.getCode() == KeyCode.S)
				cam.setTranslateY(cam.getTranslateY() + 10);
			else if (key.getCode() == KeyCode.Q)
				cam.setTranslateZ(cam.getTranslateZ() - 10);
			else if (key.getCode() == KeyCode.E)
				cam.setTranslateZ(cam.getTranslateZ() + 10);
			else if (key.getCode() == KeyCode.T)
				rotateX.setAngle(rotateX.getAngle() + 5);
			else if (key.getCode() == KeyCode.G)
				rotateX.setAngle(rotateX.getAngle() - 5);
			else if (key.getCode() == KeyCode.Y)
				rotateY.setAngle(rotateY.getAngle() + 5);
			else if (key.getCode() == KeyCode.R)
				rotateY.setAngle(rotateY.getAngle() - 5);
			else if (key.getCode() == KeyCode.F)
				rotateZ.setAngle(rotateZ.getAngle() + 5);
			else if (key.getCode() == KeyCode.H)
				rotateZ.setAngle(rotateZ.getAngle() - 5);
			else if (key.getCode() == KeyCode.EQUALS) {
				for (int i = 4; i < 8; i++) {
					TriangleMesh mesh = (TriangleMesh)(sea.getMesh());
					float val = mesh.getPoints().get(i * 3 + 2);
					mesh.getPoints().set(i * 3 + 2, val + 2);
				}
			}
			else if (key.getCode() == KeyCode.MINUS) {
				for (int i = 4; i < 8; i++) {
					TriangleMesh mesh = (TriangleMesh)(sea.getMesh());
					float val = mesh.getPoints().get(i * 3 + 2);
					mesh.getPoints().set(i * 3 + 2, val - 2);
				}
			}
			else if (key.getCode() == KeyCode.DIGIT1) {
				timeline = new Timeline(new KeyFrame(
				Duration.millis(500),
				ae -> {
					Scenario1.super_rechercheur_de_collines(sea, image,height);
					height++;
						//(int)((TriangleMesh)(sea.getMesh())).getPoints().get(2));
				}));
				timeline.setCycleCount(100);
				timeline.play();
			}
			else if (key.getCode() == KeyCode.DIGIT2) {
				Scenario2.begin(sea, image);
			}
			else if (key.getCode() == KeyCode.SPACE && timeline != null) {
				timeline.stop();
			}

		});
	}

	private static MeshView create_sea(int sizex, int sizey, float sizez)
	{
        float[] texCoords =
        {
            0.5f, 0.5f, 0.0f,
        	0.8f, 0.8f, 0.8f
        };

		float[] points = {
            0, 0, 0,
            (float)sizex, 0, 0,
            (float)sizex, (float)sizey, 0, // 2
            0, (float)sizey, 0, // 3
            0, 0,(float)sizez,
            (float)sizex, 0, (float)sizez,
            (float)sizex, (float)sizey,(float)sizez, // 6
            0, (float)sizey, (float)sizez, // 7

        };
        int textnumber = 1;
        int[] faces = {
            0, textnumber, 1, textnumber, 5, textnumber,
            0, textnumber, 5, textnumber, 4, textnumber,
            1, textnumber, 2, textnumber, 6, textnumber,
            1, textnumber, 6, textnumber, 5, textnumber,
            2, textnumber, 3, textnumber, 6, textnumber,
            3, textnumber, 7, textnumber, 6, textnumber,
            3, textnumber, 0, textnumber, 4, textnumber,
            3, textnumber, 4, textnumber, 7, textnumber,
            4, textnumber, 6, textnumber, 5, textnumber,
            4, textnumber, 7, textnumber, 6, textnumber,
        };

        TriangleMesh mesh = new TriangleMesh();
        mesh.getPoints().addAll(points);
        mesh.getTexCoords().addAll(texCoords);
        mesh.getFaces().addAll(faces);

        // Create a NeshView
        MeshView meshView = new MeshView();
        meshView.setMesh(mesh);

        return meshView;
    };

	public static float[] create_vertex(int image[][]) {
        int nb_points = image.length * image[0].length;
        float[] map = new float[nb_points * 3];
        int x = 0;
        for (int i = 0; i < image.length; i++) {
            for (int j = 0; j < image[0].length; j++) {
                map[x + 0] = i;
                map[x + 1] = j;
                map[x + 2] = -image[i][j];
                x += 3;
            }
        }
        System.out.print(x);
        System.out.print("-");
        System.out.println(nb_points * 3);
        return map;
    }

    public static int[] create_faces(float map[], int nb_triangles, int linelen) {
        int[] faces = new int[nb_triangles * 6];
        int    x = 0;
        int    text =1;
        for (int i = 0; i < map.length - 1; i++) {
            if (i % linelen != linelen - 1 && i < (linelen * linelen - linelen)) {
                faces[x + 0] = i + 0;
                faces[x + 1] = text;
                faces[x + 2] = i + 1;
                faces[x + 3] = text+1;
                faces[x + 4] = i + linelen;
                faces[x + 5] = text+1;

                faces[x + 6] = i + 1;
                faces[x + 7] = text;
                faces[x + 10] = i + linelen;
                faces[x + 9] = text;
                faces[x + 8] = i + linelen + 1;
                faces[x + 11] = text;
                x += 12;
            }
        }
        return faces;
    }
	private MeshView create_field(/* int sommets[] */)
	{

		float[] texCoords =
		{
			0.5f, 0.5f, 0.0f,
			0.8f, 0.8f, 0.8f
		};

		int sommets[] =  {240, 240, 200, 350, 240, 200, 240, 350, 200, 360, 350, 200, 1, 1, 200};
		// int sommets[] = {240, 240, 200, 350, 240, 200};

		image = new int [SIZEY][SIZEX];
		calc_sommets(image, sommets);
		image = blur_map(image);
		image = blur_map(image);
		image = blur_map(image);
		image = blur_map(image);


		// System.exit(0);

		float[] points = create_vertex(image);
		int[] faces = create_faces(points, (SIZEY - 1) * (SIZEX - 1) * 2, SIZEX);

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
}
