
/***
* Example JUnit testing class for Circle1 (and Circle)
***/

// Import all assertions and all annotations
// - see docs for lists and descriptions
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.*;

public class Circle1Test
{
   // Data you need for each test case
   private Circle1 circle1;

// 
// Stuff you want to do before each test case
//
@BeforeEach
public void setup()
{
   System.out.println("\nTest starting for Circle1...");
   circle1 = new Circle1(1,2,3);
}

//
// Stuff you want to do after each test case
//
@AfterEach
public void teardown()
{
   System.out.println("\nTest finished.");
}

//
// Test a simple positive move
//
@Test
public void simpleMove()
{
   Point p;
   System.out.println("Running test simpleMove.");
   p = circle1.moveBy(1,1);
   assertTrue(p.x == 2 && p.y == 3);
}

// 
// Test a simple negative move
//
@Test
public void simpleMoveNeg()
{
   Point p;
   System.out.println("Running test simpleMoveNeg.");
   p = circle1.moveBy(-1,-1);
   assertTrue(p.x == 0 && p.y == 1);
}

//
// Test scale to reduce size
//
@Test
public void changeSizeSmall()
{
   double r;
   r = circle1.scale(0.5);
   assertEquals(1.5, r);
}

//
// Test scale to increase size
//
@Test
public void changeSizeBig()
{
   double r;
   r = circle1.scale(1.7);
   assertEquals(5.1, r);
}

//
//Test scale with a negative value
//
@Test
public void changeSizeNeg()
{
   double r;
   r = circle1.scale(-2.3);
   assertEquals(3, r);
}

//
// Test if it sees two circles intersect
//
@Test
public void doesIntersect()
{
   boolean i;
   Circle1 testCircle = new Circle1(3,3,4);
   i = circle1.intersects(testCircle);
   assertTrue(i);
}

//
// Test if it sees two circles that DONT intersect
//
@Test
public void doesNotIntersect()
{
   boolean i;
   Circle1 testCircle = new Circle1(10,7,2);
   i = circle1.intersects(testCircle);
   assertFalse(i);
}

//
// Test to see if a circle will see if another circle intersects inside of it
//
@Test
public void inside() 
{
   boolean i;
   Circle1 testCircle = new Circle1(1,2,6);
   i = testCircle.intersects(circle1);
   assertFalse(i);
}

//
// Test the center in the constructor
//
@Test
public void constructorCenterTest()
{
   double x, y;
   x = circle1.center.x;
   y = circle1.center.y;
   assertTrue(x==1 && y==2);
}

//
// Test the center with negative values in the constructor
//
@Test
public void constructorCenterTestNeg()
{
   double x, y;
   Circle1 testCircle = new Circle1(-3,-6,12);
   x = testCircle.center.x;
   y = testCircle.center.y;
   assertTrue(x == -3 && y == -6);
}

//
// Test the radius in the constructor
//
@Test
public void constructorRadiusTest()
{
   double r;
   r = circle1.radius;
   assertTrue(r == 3);
}
}//end class

