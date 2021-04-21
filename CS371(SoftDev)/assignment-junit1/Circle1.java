
public class Circle1 extends Circle
{

public Circle1(double x, double y, double radius)
{
   super(x,y,radius);
}

public boolean intersects(Circle other)
{
   double bigR;
   double smallR;
   if(radius > other.radius) {
      bigR = radius;
      smallR = other.radius;
   }
   else {
      bigR = other.radius;
      smallR = radius;
   }

   double d;
   double r;
   d = (center.x - other.center.x) * (center.x - other.center.x) +
       (center.y - other.center.y) * (center.y - other.center.y);
   r = (radius + other.radius) * (radius + other.radius);
   if(Math.sqrt(d) + smallR < bigR)
      return false;
   if(d < r)
      return true;
   return false;
}

}

