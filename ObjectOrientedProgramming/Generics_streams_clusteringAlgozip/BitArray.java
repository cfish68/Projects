import java.io.File;
import java.nio.file.Paths;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.util.ArrayList;
import java.util.List;


public class BitArray implements Clusterable<BitArray>{
	private ArrayList<Boolean> bits;

	public BitArray(String str){
		// TODO: Complete
		String delim = "[,]+";
		String[] lst = str.split(delim);
		List<String> list = Arrays.stream(lst).collect(Collectors.toList());
		bits = Arrays.stream(lst).map(x ->{
			return Boolean.parseBoolean(x);
		}).collect(Collectors.toCollection(ArrayList::new));
	}
	public BitArray(boolean[] bits) {
		// TODO: Complete
		bits = bits.clone();
	}

	@Override
	public double distance(BitArray other) {
		// TODO: Complete
		long dis = IntStream.range(0, bits.size()).filter(i ->{
			if(0 != Boolean.compare(bits.get(i), other.bits.get(i)))
				return true;
			return false;
		}).count();
		return (double)dis;
	}

	public static Set<BitArray> readClusterableSet(String path) throws IOException {
		// TODO: Complete. If the file contains bitarrays of different lengths,
		//  retain only those of maximal length
		Scanner scanner = new Scanner(new File(path));
		Stream<String> data = Files.lines(Paths.get(path));
		Set<BitArray> thisSet = data.map(x -> {
			String line = x;
			return new BitArray(line);
		}).collect(Collectors.toSet());
		BitArray longestArray = thisSet.stream().max((x, y) -> {
			 if(x.bits.size()>y.bits.size())
			 	return x.bits.size();
			 return y.bits.size();
		}).get();
		int longestSize = longestArray.bits.size();
		thisSet = thisSet.stream().filter(x ->{
			return x.bits.size() == longestSize;
		}).collect(Collectors.toSet());
		return thisSet;
	}

	@Override
	public String toString() {
		return bits.toString();
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		BitArray bitArray = (BitArray) o;
		return bits.equals(bitArray.bits);
	}

	@Override
	public int hashCode() {
		return Objects.hash(bits);
	}
}
