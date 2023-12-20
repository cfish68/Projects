
import java.util.ArrayList;
import java.util.Arrays;

public class AirportUtil {
    public static void sortTransport(Comparable[] transport){
        Arrays.sort(transport);
    }

    static String reportAll (Movable[] movables) {
        ArrayList<String> buffer = new ArrayList<>();
        for (Movable m: movables) {
            if(m.getType() == "Plane")
            {
             buffer.add(String.format("Plane %d going from %s to %s. Currently in %s", m.getId(), m.getSource(), m.getDestination(), m.getSource()));
            }
            else{//trains
                buffer.add(String.format("Train %d going from %s to %s. Currently in %s",
                        m.getId(), m.getSource(), m.getDestination(), m.getCurrentLocation()));
            }
        }
        return String.join("\n",buffer);
    }
}
