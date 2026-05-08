import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Graphics;

public class Display extends JFrame {
	int	image[][];
	@Override
	public void paint(Graphics g) {
		super.paint(g);
		for (int i = 0; i < image.length; i++){
			for (int j = 0; j < image[i].length; j++){
				g.setColor(new Color (image[i][j], image[i][j], image[i][j]));
				g.drawLine(i, j, i, j);
			}
		}
	}

	public Display(int data[][]){
		image = data;
	    this.setTitle("Mon cul en Java");
	    this.setSize(600, 600);
	    this.setLocationRelativeTo(null);// positionne au centre de l'ecran
	    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JPanel pan = new JPanel();
		// pan.setBackground(Color.ORANGE);
		this.setContentPane(pan);// pan devient le content pane de Jframe

		this.setVisible(true);
  }
}
