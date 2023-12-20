//package WS1.Nimbus1;

//import WS1.Observables.Sensor;
//import WS1.Observables.SensorAlarmListener;

public class Nimbus1TemperatureSensor extends Sensor {
    RandomSupplier random;
    public Nimbus1TemperatureSensor(String type, int interval)
    {
        super(type, interval);
        random = new RandomSupplier();
        (Nimbus1Clock.theInstance()).register(interval, new SensorAlarmListener(this));
    }
    public int read(){
       return random.getRnd().nextInt(40);
    }
}
