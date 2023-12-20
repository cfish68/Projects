package sortingAlgorithms;
import org.jboss.weld.environment.se.Weld;
import org.jboss.weld.environment.se.WeldContainer;
import java.util.Scanner;
import javax.enterprise.inject.Produces;
import javax.inject.Named;

// TODO: Add java classes (in separate files for annotations and aspects
public class MainApp {
    public static void main(String[] args) {
        Weld weld = new Weld();
        WeldContainer container = weld.initialize();

        // TODO: Change this line to initialize an injected AlgorithmRunner
        AlgorithmRunner algorithmRunner = container.select(AlgorithmRunner.class).get();


        algorithmRunner.runAlgorithms();
    }
    // TODO: Add producers
    @Produces
    public @Named("quadAlgorithm") SortingAlgorithm<Integer> sortingAlgorithmGenerator()
    {
        //For checking purposes change the sorting algorithm. as per what the teacher advised.
        return new BubbleSort();
    }
    @Produces
    public @Named("nlognAlgorithm") SortingAlgorithm<Integer> sortingAlgorithm()
    {
        //For checking purposes change the sorting algorithm. as per what the teacher advised.
        return new QuickSort();
    }
    @Produces
    public @Named("numOfElements")  int howManyElements()
    {
        System.out.println("Enter number of elements to be sorted:");
        Scanner s = new Scanner(System.in);
        return s.nextInt();
    }
}
