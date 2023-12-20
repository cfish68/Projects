//package WS1.Observers;

//import WS1.Observables.PressureTrendSensor;
//import WS1.Observables.Sensor;
//import WS1.Observables.Observable;
//import WS1.Observables.Trend;

public class LogPressTrendObserver implements Observer{
    public LogPressTrendObserver(PressureTrendSensor PTS){
            System.out.println("LogPressTrendObserver was created");
            PTS.addObserver(this);
    }
    @Override
    public void update(int data) {

        System.out.println("Log: pressure trend = " + Trend.values()[data].toString());
    }
}
