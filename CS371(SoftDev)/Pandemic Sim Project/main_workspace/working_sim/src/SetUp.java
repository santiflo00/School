import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;

import javax.imageio.ImageIO;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleButton;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class SetUp extends Application {
	
	private int nrows;
	private int ncols;
	private Location locations[][];
	private LinkedList<Location> cities;
	
	// UI
	private GridPane gridPane;
	// Text
	private TextField setAmountField;
	private TextField fileName;
	// Buttons
	private Button saveButton;
	private ToggleButton setButton;
	
	
	public static final String PATH_TO_CONFIG_FOLDER = "config_files";
	private static final int LOWEST_LEVEL = 1;
	
	public void init() {
		cities = new LinkedList<Location>();
		
		
		BufferedImage image = null;
		try {
			image = ImageIO.read(new File("../../docs/maps/bw_world.jpg"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} // end catch
		
        nrows = image.getHeight();
        ncols = image.getWidth();
        locations = new Location[nrows][ncols];
        
        for(int i = 0; i < nrows; i++) {
		    for(int j = 0; j < ncols; j++) {
		    	locations[i][j] = new Location(i, j);
		    	
		        int red = new Color(image.getRGB(j, i)).getRed();
		        if(red <= 100) {
			    	locations[i][j].land = 1;
			    	locations[i][j].pop = -1;
		        } // end if
		    } // end for j
		} // end for i
        
        
        // GridPane
  		gridPane = new GridPane();
  		
  		// initialize the canvas in InfectedColor
  		BoardUI.initialize(nrows, ncols); 
		
		// buttons
		// button to determine if it is in the set up or not 
		setButton = new ToggleButton("Set up");
		
		// The button to start the simulation button
		saveButton = new Button("Save");
		// TextField for the amount to set a point in the program
		setAmountField = new TextField(Integer.toString(LOWEST_LEVEL));
		fileName = new TextField();
				
	} // end init
	
	@Override
	public void start(Stage primaryStage) {
		// set up the grid pane
		gridPane.setHgap(0.25); //The size of the horizontal gap between squares
  		gridPane.setVgap(0.25); //The size of the horizontal gap between squares
  		gridPane.setStyle("-fx-background-color: white;"); //The color of the background
  		
		 /* Inspired by Evan Knowlesand Nicolas Filotto 
		 * Links: https://stackoverflow.com/questions/7555564/what-is-the-recommended-way-to-make-a-numeric-textfield-in-javafx
		 */
		setAmountField.textProperty().addListener(new ChangeListener<String>() {
	
			@Override
			public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
				// if the new value is not a number (denoted by the regular expression \d+
				// set it to 0
				if (!newValue.matches("[1-9]|^$|(10)")) {
					setAmountField.setText(Integer.toString(LOWEST_LEVEL));
				} // end if
			} // end changed
			
		}); // end setAmountField.textProperty().addListener()
		
		fileName.textProperty().addListener(new ChangeListener<String>() {

			@Override
			public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
				if (!newValue.matches("[a-zA-Z][a-zA-Z0-9]*|^$")) {
					fileName.setText("config");
				} // end if
				
			}
			
		});;
		
		// set up the canvas
		for (int x = 0; x < nrows; x++) {
			for (int y = 0; y < ncols; y++) {
				if(locations[x][y].land == 1) {
					BoardUI.drawPos(x, y, BoardUI.LAND);
				} // end if
				else {
					BoardUI.drawPos(x, y, BoardUI.WATER);
				}//end else
			} // end for x
		} // end for y, 
		
		// how we can set the infected location
		BoardUI.getInstance().canvas.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				
				if (setButton.isSelected()) {
					// because the event.getY give us the location on the screen
					// we have to get the location using by dividing it by the scale 
					// bceause its location on the screen is calculated by the row and pos
					// times the scale
					int row = (int) (event.getY() / BoardUI.scale);
					int col  = (int) (event.getX() / BoardUI.scale); 
					
					if (locations[row][col].land == 1 && event.getClickCount() > 1) {
						if (event.getButton() == MouseButton.PRIMARY) {
							BoardUI.drawPos(row, col, BoardUI.IH);
							
							String level = setAmountField.getText();
							
							if (locations[row][col].pop == -1) {
								System.out.println("add");
								cities.add(locations[row][col]);
							} // end if
							locations[row][col].cityLevel = (level.isEmpty() ? LOWEST_LEVEL : Integer.parseInt(level));
							
						} // end if
						else {
							
							BoardUI.drawPos(row, col, BoardUI.LAND);
							//String level = setAmountField.getText();	
							
							if (locations[row][col].pop != -1) {
								System.out.println("remove");
								cities.remove(locations[row][col]);
							} // end if
							
						} // end else
					} // end if
				} // end if
											
				
			} // end handle
			
		}); // end setOnMouseClicked
		
		// set the mosue click event for start button
		saveButton.setOnMouseClicked(new EventHandler<MouseEvent>() {
			@Override
			public void handle(MouseEvent event) {
				File f = null;
				FileWriter fw = null; 
				BufferedWriter bw = null;
				try {
					
					f = new File(PATH_TO_CONFIG_FOLDER + 
							(fileName.getText().isEmpty() ? "config.txt" : fileName.getText() + ".txt"));
					fw = new FileWriter(f);
					bw = new BufferedWriter(fw);
					
					for (Location city : cities) {
						String info = city.row + " " + city.col + " " + (int) city.cityLevel + "\n";
						bw.write(info);
					} // end for
				} catch (IOException e) {
					e.printStackTrace();
				} finally {
					if (bw != null) {
						try {
							bw.close();
						} catch (IOException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
						try {
							fw.close();
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
				
			} // end handle
		}); // end button.setonActio
		
		//Add show_inf node to gridplane at last colum on first row 
		//Add show_inf node and show_iter node to gridplane at last colum on first and second row
		//Add the displaying number before the map is made
		gridPane.add(saveButton, 0, 5, ncols/2, 1);
		gridPane.add(setButton, 0, 6, ncols/2, 1);
		gridPane.add(setAmountField, 0, 7, ncols/2, 1);
		gridPane.add(fileName, 0, 8, ncols/2, 1);
		gridPane.add(BoardUI.getInstance().canvas, 0, 9, ncols/2, 1);

		
		// scene
		Scene scene = new Scene(gridPane);
		primaryStage.setTitle("Pandemic Simulation");
		primaryStage.setScene(scene);
		primaryStage.show();
	} // end start

	// create an image
	
	public static void main(String[] args) throws Exception {
        Main.launch(args);
	} // end main
}
