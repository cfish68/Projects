import java.io.File;
import java.nio.file.Paths;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Objects;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class TwoDPoint implements Clusterable<TwoDPoint>{
	double x;
	double y;
	public TwoDPoint(String str){
		// TODO: Complete
		//for now, this assumes that the string is of the form int,int
		String delim = "[,]+";
		String[] both = str.split(delim);
		x = Double.parseDouble(both[0]);
		y = Double.parseDouble(both[1]);

	}
	public TwoDPoint(double x, double y) {
		// TODO: Complete.
		//deep copy constructor
		x=x;
		y=y;
	}
	@Override
	public double distance(TwoDPoint other) {
		// TODO: Complete
		//using the Euclidean_distance
		//not using Math.pow because it's only ^2
		return Math.sqrt(((x-other.x)*(x-other.x))+((y-other.y)*(y-other.y)));
	}

	public static Set<TwoDPoint> readClusterableSet(String path) throws IOException{
		// TODO: Complete
		Scanner scanner = new Scanner(new File(path));
		Stream<String> data = Files.lines(Paths.get(path));
		Set<TwoDPoint> thisSet = data.map(x -> {
			String line = x;
			return new TwoDPoint(line);
		}).collect(Collectors.toSet());

		return thisSet;
	}

	@Override
	public String toString() {
		return x + "," + y;
	}

	@Override
	public boolean equals(Object other) {
		TwoDPoint otherP = (TwoDPoint) other;
		return (otherP.x == x && otherP.y == y);
	}

	@Override
	public int hashCode() {
		return Objects.hash(x, y);
	}
}
