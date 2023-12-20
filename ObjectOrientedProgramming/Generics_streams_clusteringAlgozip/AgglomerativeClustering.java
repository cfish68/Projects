import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

public class AgglomerativeClustering<T extends Clusterable<T>> implements Clustering<T>{
	double threshold;
	public AgglomerativeClustering(double threshold) {
		this.threshold = threshold;
	}
	public class Pair<V>{
		V first;
		V second;
		Pair(V f, V s)
		{
			first = f;
			second = s;
		}
	}

	private double setDistance(Pair<Set<T>> pair)
	{
		Set<Double> MinDistance = pair.first.stream().map(xElement->{
			Set<Double> eleMin = pair.second.stream().map(yElement->{ return xElement.distance(yElement);
			}).collect(Collectors.toSet());
			return eleMin.stream().min(Double::compare).get();
		}).collect(Collectors.toSet());
		return MinDistance.stream().min(Double::compare).get();
	}

	private Pair<Set<T>> findClosestCluster(Set<Set<T>> clusterSet) {

		Pair<Set<T>> closesetCluster = clusterSet.stream()
				.flatMap(x ->
				{
					return clusterSet.stream().map(y -> {
						return new Pair<Set<T>>(x, y);

					});
				}).min((pair1, pair2) ->
				{
					if(pair1.first == pair1.second)
						return 1;
					if(pair2.first == pair2.second)
						return -1;
					if(pair1 == pair2)
						return 0;
					return Double.compare(setDistance(pair1), setDistance(pair2));
				}).orElseThrow(ArithmeticException::new);
		return closesetCluster;
	}
	public Set<Set<T>> clusterSet(Set<T> elements) {
		// TODO: Complete//
		Set<Set<T>> clusterSet = elements.stream().map(x -> {Set<T> y = new HashSet<T>();
		y.add(x);
		return y;
		}).collect(Collectors.toSet());
		while(clusterSet.size() != 1)
		{
			Pair<Set<T>> closestPair = findClosestCluster(clusterSet);
			if(setDistance(closestPair) <= threshold)
			{
				//perhaps there's a shorter way to do this
				clusterSet.remove(closestPair.second);
				clusterSet.remove(closestPair.first);
				Set<T> mergedSet = new HashSet<T>();
				mergedSet.addAll(closestPair.first);//(closestPair.first, closestPair.second);
				mergedSet.addAll(closestPair.second);
				clusterSet.add(mergedSet);
			}
			else {
				break;
			}
			//Elis implementation: find the minimum pair


		}
		//make all elements into its own set
		//create a "helper function" that takes 2 sets and compare every elemetn in one set to every elemetn in the other set and find the minjmum dsitance between one s
		//set and the other set
		//that is the distance between the sets
		//then compare every point with every other point
		//find which is the miniumum distance
		//and create a new set which is the union and put it back into the original set array.


		return clusterSet;
	}
}
