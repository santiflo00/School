
public class Circle2 extends Circle
{

public Circle2(double x, double y, double radius)
{
   super(x,y,radius);//mixed x and y
}

public boolean intersects(Circle other)
{
   double d;
   double r;
   double rd;
   r = radius + other.radius;
   d = Math.sqrt(Math.pow(center.x - other.center.x, 2) + 
                 Math.pow(center.y - other.center.y, 2));
if(radius < other.radius) { //find the larger radius to put on the right side
   if (d + radius < other.radius) //if a circle is inside another
      return false;
}
else {  
   if(d + other.radius < radius)
      return false;
}

   if (d < r)
      return true;
   else
      return false;

}//end intersects

}//end class

