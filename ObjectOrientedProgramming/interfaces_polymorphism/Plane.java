
public class Plane implements Movable, Comparable{
    public static final int HEIGHT_LIMIT = 1500;
    int licenceNumber;
    Location source, destination;
    int maximalHeight;

    public Plane(int id, Location src, Location dst, int maxHeight) {
        licenceNumber = id;
        source = src;
        destination = dst;
        maximalHeight = maxHeight;
    }

    @Override
	public String toString() {
        //return String.format("Plane %d going from %s to %s. Currently in %s", licenceNumber, source, destination, source);
		return String.format("licence = %d, source = %s, destination = %s, maxHeight = %d",
				licenceNumber, source, destination, maximalHeight);
	}
	
    @Override
    public String getType() {
        return "Plane";
    }

    @Override
    public int getId() {
        return licenceNumber;
    }

    @Override
    public Location getSource() {
        return source;
    }

    @Override
    public Location getDestination() {
        return destination;
    }

    @Override
    public String getCurrentLocation() {
        return source.toString();
    }

    @Override
    public void move() {
        Location temp = source;
        source = destination;
        destination = temp;
    }

    @Override
    public int compareTo(Object o) {
        if(maximalHeight < ((Plane)o).maximalHeight)
            return -1;
        if(maximalHeight > ((Plane)o).maximalHeight)
            return 1;
        return 0;//neither if statements returned true height must be equal.
    }
}
