import javafx.application.Platform;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.WritableImage;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;

public class BoardUI  {
	public final static Color IH = Color.PINK;
	public final static Color C = Color.DARKRED;
	public final static Color I = Color.RED;
	public final static Color B = Color.BLACK;
	public final static Color WATER = Color.BLUE;
	public final static Color LAND = Color.GREEN;
	
	// the scale of the picture increase this to make it bigger
	public static double scale = 1;
	
	// the canvas to display the simulation process
	// this will be initialized in Main
	public Canvas canvas = null;
	
	private static BoardUI instance = null;
	
	private BoardUI() {
		
	} // end BoardUI
	
	private BoardUI(int row, int col) {
		canvas = new Canvas(col * instance.scale, 
				row * instance.scale);
	} // end BoardUI
	
	
//	// create an image
//	public static Image createImage(Color color) {
//		WritableImage image = new WritableImage(1, 1);
//		image.getPixelWriter().setColor(0, 0, color);
//		return image;
//	} // end createImage	
	
	// set the infected color of a location
	public static void setInfectedColor(Location loc, boolean opt) {	
			//System.out.println("Here");
			if (loc != null) {
				double infected = loc.inf;
				double population = loc.pop;
				double dead = loc.rip;
				
				// this is here because there is a color whose condition will be true at the same time as black.
				if(loc.color != null && loc.color.equals(B)) {
					return;
				} // end if
					
				// if there is not more infected
				if (infected == 0) {
					if (loc.color != null && loc.color.equals(LAND) && opt)
						return;

					drawPos(loc.row, loc.col, LAND); 
					loc.color = LAND;
				} // end if
				else if (dead/population > .9) {
					if (loc.color != null && loc.color.equals(B) && opt) 
						return;
					drawPos(loc.row, loc.col, BoardUI.B); 
					loc.color = B;
				} // end if
				else if ( (infected + dead)/population > 0 && (infected + dead)/population < .3) {
					if (loc.color != null && loc.color.equals(IH) && opt)
						return;
					
					drawPos(loc.row, loc.col, BoardUI.IH); 
					loc.color = IH;
				} // if infected low
				else if ( (infected + dead)/population >= .3 && (infected + dead)/population < 0.8) {
					if (loc.color != null && loc.color.equals(I) && opt) 
						return;
					
					drawPos(loc.row, loc.col, BoardUI.I); 
					loc.color = I;
				} // if infected midS
				else if ( (infected + dead)/population >= .8) {
					if (loc.color != null && loc.color.equals(C) && opt) 
						return;
					
					drawPos(loc.row, loc.col, BoardUI.C); 
					loc.color = C;
		        } // if infected high
			} // end if

	} // end setPositionColor
	
	
	// set a location with the specified color
	public static void drawPos(double row, double col, Color color) {
		
		Runnable draw = new Runnable() {

			@Override
			public void run() {
				if (instance != null && instance.canvas != null) {
					// TODO Auto-generated method stub
					GraphicsContext gc = instance.canvas.getGraphicsContext2D();
					
					// set the color that will be used to draw
					gc.setFill(color);;
					
					// the order is switched because fill rectangle take x and y
					// x ~ x axis and y ~ the y axis
					// make a rectangle with the location on the screen, and the size of the rectangle
					// * scale because we scaled the picture
					gc.fillRect(col * instance.scale, row * instance.scale, instance.scale, instance.scale);
				} // end if
			} // end run
			
		}; // end draw
		
		Platform.runLater(draw);
		//System.out.println("Infect Color");
		//System.out.println(row + " " + col);
	
	} // end drawPos

	public static void initialize(int row, int col) {
		instance = new BoardUI(row, col);
	} // end initialize
	
	public static BoardUI getInstance() {
		return instance;
	} // end getInstance
	
} // end InfectedColo