import java.util.Scanner;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.event.EventType;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleButton;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.WritableImage;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Main extends Application {
	private boolean simulating = false;
	private int nrows;
	private int ncols;
	
	// Text
	private Text show_inf;
	private Text show_healthy;
	private Text show_iter;
	private Text show_alive;
	private Text show_dead;
	private Text show_rec;
	private TextField setAmountField;
	
	// Buttons
	private ToggleButton startButton;
	private ToggleButton setButton;
	private Button saveButton;
	
	// Pane
	private GridPane startScreen;
	
	// Scene
	private Scene scene;
	
	//
	private ListView<String> scenariosList; 
	
	// Stage
	private Stage pStage;
	
	// ScenarioFileManager
	private ScenarioFileManager sManager; 
	
	// Scenario
	public void init() {
		sManager = new ScenarioFileManager();
		
		//box for title
		startScreen = new GridPane();
		
		//startScreen.getChildren().g
		
		// create an observable list of all the options and scenarios for list view.
		ObservableList<String> list = FXCollections.observableList(sManager.getAllScenarios());
		
		// set the on click for each item.
		scenariosList = new ListView<String>(list);
		scenariosList.setOnMouseClicked((MouseEvent e) -> {
			// not double click, get out
			if (e.getClickCount() < 2) 
				return;
			
			// initialize boards
			Board testBoard = null;
			// get the name of the clicked sceranio
			String selectedName = scenariosList.getSelectionModel().getSelectedItem();
			// choose between options
			
			// existing sceranios
			testBoard = sManager.loadScenario(selectedName);
			// set up travel again (if there is) because the airports data is not saved
			testBoard.setUpTravel();
			
			GridPane simulationScreen = startNewSimulation(testBoard);
			scene.setRoot(simulationScreen);
		});
	
		// Buttons for initialization
		
		Button sqButton = new Button("Add new square");
		Button sButton = new Button("Add new simulation");
		Button saButton = new Button("Add new simulation with airports");
		
		sqButton.setOnAction((ActionEvent e) ->  {
			Board testBoard = new Board(false, false, "config.txt");
			GridPane simulationScreen = startNewSimulation(testBoard);
			scene.setRoot(simulationScreen);
		});
		
		sButton.setOnAction((ActionEvent e) ->  {
			Board testBoard = new Board(true, false, "config.txt");
			GridPane simulationScreen = startNewSimulation(testBoard);
			scene.setRoot(simulationScreen);
		});
		
		saButton.setOnAction((ActionEvent e) ->  {
			Board testBoard = new Board(true, true, "config.txt");
			GridPane simulationScreen = startNewSimulation(testBoard);
			scene.setRoot(simulationScreen);
		});
		
		
		
		// delete scenario button
		final Button deleteButton = new Button("Delete");
		deleteButton.setOnAction((ActionEvent e) -> {
			// check if an option or scenario has been selected
			String selectedName = scenariosList.getSelectionModel().getSelectedItem();
			if (selectedName == null)
				return;
			
			// delete, and check if it has not been deleted
			System.out.println(selectedName);
			if (sManager.deleteScenario(selectedName)) 
				System.out.println("Successfully delete " + selectedName);
			else
				System.out.println("Failed to delete " + selectedName);
			
			// remove the item from the ListView list.
			ObservableList<String> l = FXCollections.observableList(sManager.getAllScenarios());
			scenariosList.setItems(l);
			
		});
		
		// add the components into the pane
		startScreen.addColumn(1, deleteButton);
		startScreen.addColumn(0, new Text("Scenarios"));
		startScreen.addColumn(0, scenariosList);	
		startScreen.addColumn(0, sqButton);
		startScreen.addColumn(0, sButton);
		startScreen.addColumn(0, saButton);
		

//				
	} // end init
	
	@Override
	public void start(Stage primaryStage) {
		// scene
		pStage = primaryStage;
		
		//Scene scene = new Scene(gridPane);
		scene = new Scene(startScreen);
		primaryStage.setTitle("Pandemic Simulation");
		primaryStage.setScene(scene);
		primaryStage.show();
	} // end start
	
	// start a simulation screen based on the board object
	private GridPane startNewSimulation(Board testBoard) {
		// check if the parameter is a test board object
		if (testBoard == null) {
			System.err.println("No test board initialization");
			return null;
		} // end if
		
		// store the size of the Board
		nrows = testBoard.getBoardRows();
		ncols = testBoard.getBoardColumns();
        
        // GridPane
  		GridPane gridPane = new GridPane();
  		// set up the grid pane
		gridPane.setHgap(0.25); //The size of the horizontal gap between squares
  		gridPane.setVgap(0.25); //The size of the horizontal gap between squares
  		gridPane.setStyle("-fx-background-color: blue;"); //The color of the background
  		
  		// initialize the canvas in InfectedColor
  		BoardUI.initialize(nrows, ncols);
				
		// Data representation
		show_alive = new Text("Number of people alive: "+ testBoard.getTotalAlive());
		show_alive.setFill(Color.WHITE);
		show_alive.setFont(Font.font("Verdana",25));
		
		show_healthy = new Text("Number of healthy people:  "+testBoard.getTotalHealthy());
		show_healthy.setFill(Color.AQUA);
		show_healthy.setFont(Font.font("Verdana",25));
		
		show_inf = new Text("Number of people infected: "+ testBoard.getTotalInfected());
		show_inf.setFill(Color.RED);
		show_inf.setFont(Font.font("Verdana",25));
		
		show_dead = new Text("Number of dead people:  "+testBoard.getTotalDeath());
		show_dead.setFill(Color.BLACK);
		show_dead.setFont(Font.font("Verdana",25));
		
		show_rec = new Text("Number of recovered people:  " + testBoard.getTotalRecovered());
		show_rec.setFill(Color.PURPLE);
		show_rec.setFont(Font.font("Verdana",25));
		
		show_iter = new Text("Iteration: "+ testBoard.getIteration());
		show_iter.setFont(Font.font("Verdana",15));
		
		// buttons
		// button to determine if it is in the set up or not 
		setButton = new ToggleButton("Set up");
		setButton.setMinSize(75, 75);
		// The button to start the simulation button
		startButton = new ToggleButton("Start");
		startButton.setMinSize(75, 75);
		// save buttons
		saveButton = new Button("Save");
		saveButton.setMinSize(75, 75);
		
		// TextField for the amount to set a point in the program
		setAmountField = new TextField("50");
		setAmountField.setMaxWidth(150);
  		
		 /* Inspired by Evan Knowlesand Nicolas Filotto 
		 * Links: https://stackoverflow.com/questions/7555564/what-is-the-recommended-way-to-make-a-numeric-textfield-in-javafx
		 */
		setAmountField.textProperty().addListener(new ChangeListener<String>() {
			@Override
			public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
				// if the new value is not a number (denoted by the regular expression \d+
				// set it to 0
				if (!newValue.matches("\\d+")) {
					setAmountField.setText("0");
				} // end if
			} // end changed
			
		}); // end setAmountField.textProperty().addListener()
		
		// set up the canvas
		for (int x = 0; x < nrows; x++) {
			for (int y = 0; y < ncols; y++) {
				Location loc = testBoard.getLocation(x, y);
				if(testBoard.isLand(x, y)) {
					BoardUI.setInfectedColor(testBoard.getLocation(x, y), false);
				} // end if
			} // end for x
		} // end for y, 
		
		
		
		// how we can set the infected location
		BoardUI.getInstance().canvas.setOnMouseClicked(new EventHandler<MouseEvent>() {

			@Override
			public void handle(MouseEvent event) {
				
				if (startButton.isSelected() 
					|| !setButton.isSelected()
					|| event.getClickCount() < 2 
					|| event.getButton() != MouseButton.PRIMARY)
					return;
				
				// because the event.getY give us the location on the screen
				// we have to get the location using by dividing it by the scale 
				// bceause its location on the screen is calculated by the row and pos
				// times the scale
				testBoard.putInfection((int) (event.getY() / BoardUI.scale), 
											(int) (event.getX() / BoardUI.scale), 
											Double.parseDouble(setAmountField.getText()));
				
			} // end handle
			
		}); // end setOnMouseClicked
		
		// set the mosue click event for start button
		startButton.setOnMouseClicked((MouseEvent event) -> {
				// simulation thread
				Thread simThread;
				
				// when start
				if (startButton.isSelected()) {
					// initialize simulation thread
					simThread = new Thread(new Runnable() {

						@Override
						public void run() {
							while (simulating) {
								testBoard.do_iter();;
								
								show_alive.setText("Number of people alive: " + testBoard.getTotalAlive());
								show_healthy.setText("Number of healthy people: "+testBoard.getTotalHealthy());
								show_inf.setText("Number of people infected: "+(int)testBoard.getTotalInfected());
								show_dead.setText("Number of people dead: " + (int)testBoard.getTotalDeath());
								show_rec.setText("Number of people recovered: " + (int)testBoard.getTotalRecovered());
								show_iter.setText("Iteration: "+ testBoard.getIteration());
								try {
									Thread.sleep(1000);
								} catch (InterruptedException e) {
									return;
								} // end catch
							} // end while
							
						} // end run
						
					});
					
					// start simulating
					simulating = true;
					
					// set this so that this thread will also be closed when javafx thread is closed
					simThread.setDaemon(true); 
					
					// start running the simulation
					simThread.start();
					
					// change the text
					startButton.setText("Pause");
				} // end if
				else {
					// set this to end the simulation
					simulating = false;
					
					// change the text
					startButton.setText("Continue");
				} // end else
		}); // end button.setonActio
		
		// gui components for saving the scenarios box.
		final Stage dialog = new Stage();
		dialog.initModality(Modality.APPLICATION_MODAL); // other stages will not be interactive.
        dialog.initOwner(pStage);
        
        // field for entering the name of the scenario saved.
        final String DEFAULT_FILE_NAME = "scenario";
        TextField fileName = new TextField(DEFAULT_FILE_NAME);
        fileName.textProperty().addListener((ObservableValue<? extends String> observable, String oldValue, String newValue) -> {
				// if the value is an invalid file name
				// Taken from https://superuser.com/questions/358855/what-characters-are-safe-in-cross-platform-file-names-for-linux-windows-and-os
				// stack exchange
				// Windows: Not \/:*?"<>|
				// Linux/Mac: Not empty or /
				if (!newValue.matches("[^\\/:*?\"<>|]*"))
					Platform.runLater(() -> fileName.setText(""));
        });
        
        // save file button to confirm the file name entered
        Button saveFileButton = new Button("Save File");
        saveFileButton.setOnAction((ActionEvent e) -> {
        	if (sManager.saveScenario(fileName.getText(), testBoard))
        		System.out.println("Saved file sucessfully");
        	else
        		System.out.println("Unsuccessful Save");
        });
        
        // One column layout is preferred
        VBox dialogVbox = new VBox(20);
        dialogVbox.getChildren().addAll(new Text("Enter your file name"), fileName, saveFileButton);
        
        // set the new scene for the stage
        Scene dialogScene = new Scene(dialogVbox, 300, 200);
        dialog.setScene(dialogScene);
        
        // the save button to turn on the save option.
		saveButton.setOnAction((ActionEvent event) -> {
			// make sure that the simulation is not running before saving
			if (startButton.isSelected())
        		return;
			
	        dialog.show();
		});
		
		//Add show_inf node to gridplane at last colum on first row 
		//Add show_inf node and show_iter node to gridplane at last colum on first and second row
		//Add the displaying number before the map is made
		Button returnButton = new Button("Return");
		returnButton.setOnAction((ActionEvent e) -> {
			// stop the simulation thread
			simulating = false;
			
			ObservableList<String> list = FXCollections.observableList(sManager.getAllScenarios());
			// set the new list of scenarios. 
			scenariosList.setItems(list);
			
			// set the scene to the startScreen Pane.
			scene.setRoot(startScreen);
		});
		
		gridPane.add(returnButton, 0, 0, ncols/2, 1);
		gridPane.add(show_alive, 0, 1, ncols/2, 1);
		gridPane.add(show_healthy, 0, 2, ncols/2, 1);
		gridPane.add(show_inf, 0, 3, ncols/2, 1);
		gridPane.add(show_dead, 0, 4, ncols/2, 1);
		gridPane.add(show_rec, 0, 5,ncols/2,1);
		gridPane.add(show_iter, 0, 6, ncols/2, 1);
		gridPane.add(startButton, 0, 7, 1, 1);
		gridPane.add(setButton, 1, 7, 1, 1);
		gridPane.add(saveButton, 2, 7, 1, 1);
		gridPane.add(setAmountField, 0, 8, ncols/2, 1);
		gridPane.add(BoardUI.getInstance().canvas, 0, 9, ncols/2, 1);
		
		return gridPane;
	} // start new simulation
	
	public static void main(String[] args) throws Exception {
        Main.launch(args);
	} // end main
	
} // end Main