//package WS1.Observers;

//import WS1.Observables.Sensor;

public class MSPressObserver implements Observer{
    public MSPressObserver(Sensor sensor){
        System.out.println(this.getClass().getSimpleName() + " was created");
        sensor.addObserver(this);
    }
    @Override
    public void update(int data) {
        System.out.println("MonitoringScreen: pressure = " + data + " millibars");
    }
}
