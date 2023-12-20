//package WS1.Observers;

//import WS1.Observables.Sensor;


public class MSTempObserver implements Observer{
    public MSTempObserver(Sensor sensor){
        System.out.println(this.getClass().getSimpleName() + " was created");
        sensor.addObserver(this);
    }
    @Override
    public void update(int data) {
        System.out.println( "MonitoringScreen: temperature = " + data + " Celsius");
    }
}
