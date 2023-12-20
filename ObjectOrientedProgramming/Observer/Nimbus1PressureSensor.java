

//import WS1.Observables.AlarmClock;
//import WS1.Observables.Sensor;
//import WS1.Observables.SensorAlarmListener;

public class Nimbus1PressureSensor extends Sensor {
    RandomSupplier random;
    public Nimbus1PressureSensor(String type, int interval)
    {
        super(type, interval);
        random = new RandomSupplier();
        (Nimbus1Clock.theInstance()).register(interval, new SensorAlarmListener(this));
    }
    public int read(){
        //generate number between 1050 and 950
        return (random.getRnd().nextInt(100)+950);
    }
}
