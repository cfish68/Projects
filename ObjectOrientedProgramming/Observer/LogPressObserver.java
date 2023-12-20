//package WS1.Observers;

//import WS1.Observables.PressureTrendSensor;
//import WS1.Observables.Sensor;


public class LogPressObserver implements Observer{
    public LogPressObserver(Sensor ps){
        System.out.println("LogPressObserver was created");
        ps.addObserver(this);
    }
    @Override
    public void update(int data) {
        System.out.println("Log: pressure = " + data + " millibars");
    }
}
